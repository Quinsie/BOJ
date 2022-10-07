// BOJ 17081 :: RPG Extreme
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// down, up, right, left
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

class equipment {
private:
    string type, acc;
    int atk, def;
public:
    equipment(string a, int b) {
        if (a == "W") {
            type = a;
            atk = b;
            acc = "";
            def = 0;
        }
        else {
            type = a;
            def = b;
            acc = "";
            atk = 0;
        }
    }
    equipment(string a, string b) {
        type = a;
        atk = 0;
        def = 0;
        acc = b;
    }
    ~equipment() {}

    int get_atk() { return atk; }
    int get_def() { return def; }
    string get_type() { return type; }
    string get_acc() { return acc; }
};

class monster {
private:
    int atk, def, hp, exp, full_hp;
    string name;
public:
    monster(string a, int b, int c, int d, int e) {
        name = a;
        atk = b;
        def = c;
        hp = d;
        exp = e;
        full_hp = hp;
    }
    ~monster() {}

    int get_atk() { return atk; }
    int get_def() { return def; }
    int get_hp() { return hp; }
    int get_exp() { return exp; }
    string get_name() { return name; }

    void damaged(int n) { hp -= n; }
    void reinc() { hp = full_hp; }
};

class player {
private:
    int level, now_hp, full_hp, atk, def, exp, target_exp;
    bool check[6];
    equipment* inventory[6];
public:
    player() {
        level = 1;
        now_hp = 20;
        full_hp = 20;
        atk = 2;
        def = 2;
        exp = 0;
        target_exp = level * 5;
        for (int i = 0; i < 6; i++) check[i] = false;
        for (int i = 0; i < 6; i++) inventory[i] = NULL;
    }
    ~player() {}

    int get_level() { return level; }
    int get_now_hp() { return now_hp; }
    int get_full_hp() { return full_hp; }
    int get_atk() { return atk; }
    int get_def() { return def; }
    int get_exp() { return exp; }
    int get_target_exp() { return target_exp; }

    int get_weapon() {
        if (check[0]) return inventory[0]->get_atk();
        else return 0;
    }
    int get_armour() {
        if (check[1]) return inventory[1]->get_def();
        else return 0;
    }

    bool check_same(equipment& e) {
        for (int i = 2; i < 6; i++) {
            if (check[i]) {
                if (inventory[i]->get_acc() == e.get_acc()) return true;
            }
        }
        return false;
    }

    void pick_item(equipment& e) {
        if (e.get_type() == "W") {
            if (!check[0]) {
                check[0] = true;
                inventory[0] = new equipment(e.get_type(), e.get_atk());
            }
            else *inventory[0] = equipment(e.get_type(), e.get_atk());
        }
        else if (e.get_type() == "A") {
            if (!check[1]) {
                check[1] = true;
                inventory[1] = new equipment(e.get_type(), e.get_def());
            }
            else *inventory[1] = equipment(e.get_type(), e.get_def());
        }
        else {
            if (check_same(e)) return;
            for (int i = 2; i < 6; i++) {
                if (!check[i]) {
                    check[i] = true;
                    inventory[i] = new equipment(e.get_type(), e.get_acc());
                    break;
                }
            }
        }
    }

    void level_up() {
        level += 1;
        full_hp += 5;
        atk += 2;
        def += 2;
        now_hp = full_hp;
        exp = 0;
        target_exp = level * 5;
    }

    void heal() {
        now_hp += 3;
        if (now_hp > full_hp) now_hp = full_hp;
    }

    void spike() {
        for (int i = 2; i < 6; i++) {
            if (check[i]) { // if acc exist
                if (inventory[i]->get_acc() == "DX") { // acc trap dmg to 1
                    now_hp -= 1;
                    if (now_hp <= 0) now_hp = 0;
                    return;
                }
            }
        }
        now_hp -= 5;
        if (now_hp <= 0) now_hp = 0;
    }

    bool battle(monster& m, bool boss_flag) {
        // 2 == double, 2 && 4 == triple
        bool acc[7]; // HR, RE, CO, EX, DX, HU, CU
        bool is_first;

        for (int i = 0; i < 7; i++) acc[i] = false;
        for (int i = 2; i < 6; i++) {
            if (check[i]) {
                if (inventory[i]->get_acc() == "HR") acc[0] = true;
                else if (inventory[i]->get_acc() == "RE") acc[1] = true;
                else if (inventory[i]->get_acc() == "CO") acc[2] = true;
                else if (inventory[i]->get_acc() == "EX") acc[3] = true;
                else if (inventory[i]->get_acc() == "DX") acc[4] = true;
                else if (inventory[i]->get_acc() == "HU") acc[5] = true;
                else acc[6] = true; // CU
            }
        }

        is_first = true;
        while (true) {
            // player turn
            if (is_first) {
                if (acc[5]) {
                    if (boss_flag) now_hp = full_hp;
                }
                if (acc[2]) {
                    if (acc[4]) m.damaged(max(1, (atk + get_weapon()) * 3 - m.get_def()));
                    else m.damaged(max(1, (atk + get_weapon()) * 2 - m.get_def()));
                }
                else m.damaged(max(1, atk + get_weapon() - m.get_def()));
            }
            else m.damaged(max(1, atk + get_weapon() - m.get_def()));

            if (m.get_hp() <= 0) {
                if (acc[3]) exp += (int)(m.get_exp() * 1.2);
                else exp += m.get_exp();

                if (exp >= target_exp) level_up();
                return true;
            }

            // enemy turn
            if (boss_flag && acc[5] && is_first) { is_first = false; continue; }
            now_hp -= max(1, m.get_atk() - (def + get_armour()));

            if (now_hp <= 0) {
                now_hp = 0;
                m.reinc();
                return false;
            }
            is_first = false;
        }
    }

    bool have_regeneration() {
        for (int i = 2; i < 6; i++) {
            if (check[i]) {
                if (inventory[i]->get_acc() == "HR") return true;
            }
        }
        return false;
    }

    bool have_reincarnation() {
        for (int i = 2; i < 6; i++) {
            if (check[i]) { // if acc exist
                if (inventory[i]->get_acc() == "RE") return true; // trap dmg 1
            }
        }
        return false;
    }

    void reincarnation() {
        now_hp = full_hp;
        for (int i = 2; i < 6; i++) {
            if (check[i]) { // if acc exist
                if (inventory[i]->get_acc() == "RE") { // acc trap dmg to 1
                    inventory[i] = NULL;
                    check[i] = false;
                    return;
                }
            }
        }
    }
};

void end(const int& turn, player& p, vector <string>& board)
{
    for (auto i : board) cout << i << '\n';
    cout << "Passed Turns : " << turn << '\n';
    cout << "LV : " << p.get_level() << '\n';
    cout << "HP : " << p.get_now_hp() << "/" << p.get_full_hp() << '\n';
    cout << "ATT : " << p.get_atk() << "+" << p.get_weapon() << '\n';
    cout << "DEF : " << p.get_def() << "+" << p.get_armour() << '\n';
    cout << "EXP : " << p.get_exp() << "/" << p.get_target_exp() << '\n';
}

int order_turn(char a)
{
    if (a == 'D') return 0;
    else if (a == 'U') return 1;
    else if (a == 'R') return 2;
    else return 3;
}

void solve()
{
    int row, column, order_len, order_num, start_x, start_y, num_mon, num_box;
    int x, y, mon_atk, mon_def, mon_hp, mon_exp;
    int pos_x, pos_y, npos_x, npos_y, turn;
    bool player_alive, boss_alive;
    string order, mon_name, equ_type, acc_type;
    vector <string> board;
    vector <vector <monster*>> monster_board;
    vector <vector <equipment*>> equipment_board;
    player p;

    cin >> row >> column;
    board.assign(row, "");
    monster_board.assign(row, vector <monster*>(column, NULL));
    equipment_board.assign(row, vector <equipment*>(column, NULL));

    start_x = -1; start_y = -1;
    num_mon = 0; num_box = 0;
    for (int i = 0; i < row; i++) {
        cin >> board[i];
        for (int j = 0; j < column; j++) {
            if (board[i][j] == '@') { start_x = i; start_y = j; }
            if (board[i][j] == '&' || board[i][j] == 'M') num_mon++;
            if (board[i][j] == 'B') num_box++;
        }
    }

    cin >> order;
    order_len = order.size();

    for (int i = 0; i < num_mon; i++) {
        cin >> x >> y >> mon_name >> mon_atk >> mon_def >> mon_hp >> mon_exp;
        x--; y--;
        monster_board[x][y] = new monster(mon_name, mon_atk, mon_def, mon_hp, mon_exp);
    }

    for (int i = 0; i < num_box; i++) {
        cin >> x >> y >> equ_type >> acc_type;
        x--; y--;
        if (equ_type == "W" || equ_type == "A") equipment_board[x][y] = new equipment(equ_type, stoi(acc_type));
        else equipment_board[x][y] = new equipment(equ_type, acc_type);
    }

    // down, up, right, left
    pos_x = start_x; pos_y = start_y;
    player_alive = true; boss_alive = true;
    turn = 0;
    while (turn < order_len) {
        turn++;
        //cout << turn << '\n';
        if (board[pos_x][pos_y] != '^') board[pos_x][pos_y] = '.';

        order_num = order_turn(order[turn - 1]);

        npos_x = pos_x + dx[order_num]; npos_y = pos_y + dy[order_num];
        if (npos_x < 0 || npos_x >= row || npos_y < 0 || npos_y >= column || board[npos_x][npos_y] == '#') {
            npos_x = pos_x; npos_y = pos_y; // out of range or wall
        }

        if (board[npos_x][npos_y] == 'B') { // item box
            p.pick_item(*equipment_board[npos_x][npos_y]);
        }

        else if (board[npos_x][npos_y] == '&') {
            if (p.battle(*monster_board[npos_x][npos_y], false)) { // win
                if (p.have_regeneration()) p.heal();
            }
            else { // lost
                if (p.have_reincarnation()) {
                    p.reincarnation();
                    npos_x = start_x; npos_y = start_y;
                }
                else player_alive = false;
            }
        }

        else if (board[npos_x][npos_y] == 'M') {
            if (p.battle(*monster_board[npos_x][npos_y], true)) { // win
                if (p.have_regeneration()) p.heal();
                boss_alive = false;
                board[npos_x][npos_y] = '@';
                break;
            }
            else { // lost
                if (p.have_reincarnation()) {
                    p.reincarnation();
                    npos_x = start_x; npos_y = start_y;
                }
                else player_alive = false;
            }
        }

        else if (board[npos_x][npos_y] == '^') { // trap
            p.spike();
            if (p.get_now_hp() <= 0) {
                if (p.have_reincarnation()) {
                    p.reincarnation();
                    npos_x = start_x; npos_y = start_y;
                }
                else player_alive = false;
            }
        }

        if (!player_alive) {
            end(turn, p, board);
            cout << "YOU HAVE BEEN KILLED BY ";
            if (board[npos_x][npos_y] == '&' || board[npos_x][npos_y] == 'M') cout << monster_board[npos_x][npos_y]->get_name() << "..\n";
            else cout << "SPIKE TRAP..\n";
            return;
        }

        if (board[npos_x][npos_y] != '^') board[npos_x][npos_y] = '@';
        pos_x = npos_x; pos_y = npos_y;
    }

    if (!boss_alive) {
        end(turn, p, board);
        cout << "YOU WIN!\n";
    }
    else {
        if (player_alive && board[pos_x][pos_y] == '^') board[pos_x][pos_y] = '@';
        end(turn, p, board);
        cout << "Press any key to continue.\n";
    }
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}
