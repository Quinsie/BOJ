#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979;

class circle {
    private:
    double x, y, r;
    
    public:
    circle() {
        this -> x = 0;
        this -> y = 0;
        this -> r = 0;
    }
    circle(double a, double b, double c = 0) {
        this -> x = a;
        this -> y = b;
        this -> r = c;
    }
    ~circle(){}

    void input()
    {
        double a, b, c;
        cin >> a >> b >> c;
        this -> x = a;
        this -> y = b;
        this -> r = c;
    }

    double get_x() { return this -> x; }
    double get_y() { return this -> y; }
    double get_r() { return this -> r; }

    bool isbigger(const circle& other)
    {
        return this -> r > (other.r);
    }

    void swap_circle(circle& other)
    {
        double temp_x, temp_y, temp_r;
        temp_x = this -> x;
        temp_y = this -> y;
        temp_r = this -> r;
        this -> x = other.x;
        this -> y = other.y;
        this -> r = other.r;
        other.x = temp_x;
        other.y = temp_y;
        other.r = temp_r;
    }

    double distance(const circle& other)
    {
        return sqrt(pow((this -> x - other.x), 2) + pow((this -> y - other.y), 2));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(3);
    cout << fixed;

    double d, theta1, theta2, s1, s2, ans;
    circle c1, c2;
    c1.input();
    c2.input();

    if (!c1.isbigger(c2)) {
        c1.swap_circle(c2);
    }
    d = c1.distance(c2);

    if (d >= c1.get_r() + c2.get_r()) {
        cout << 0.000 << "\n";
    } else if (d + c2.get_r() <= c1.get_r()) {
        cout << pow(c2.get_r(), 2) * PI << "\n";
    } else {
        theta1 = acos((pow(c1.get_r(), 2) + pow(d, 2) - pow(c2.get_r(), 2)) / (2 * c1.get_r() * d));
        theta2 = acos((pow(c2.get_r(), 2) + pow(d, 2) - pow(c1.get_r(), 2)) / (2 * c2.get_r() * d));
        s1 = ((pow(c1.get_r(), 2) * 2 * theta1) / 2) - (pow(c1.get_r(), 2) * sin(2 * theta1) / 2);
        s2 = ((pow(c2.get_r(), 2) * 2 * theta2) / 2) - (pow(c2.get_r(), 2) * sin(2 * theta2) / 2);
        ans = s1 + s2;
        cout << ans << "\n";
    }

    return 0;
}