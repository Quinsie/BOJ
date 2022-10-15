#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int mod = 10e8;

int _mod(int a, int b, int flag)
{
    ULL la = (ULL)a, lb = (ULL)b;
    if (flag == 0) return ((la % mod) * (lb % mod)) % mod;
    else return ((la % mod) + (lb % mod)) % mod;
}

void matrix_mul (int a[2][2], int b[2][2])
{
    int w, x, y, z;
    w = _mod(_mod(a[0][0], b[0][0], 0), _mod(a[0][1], b[1][0], 0), 1);
    x = _mod(_mod(a[0][0], b[0][1], 0), _mod(a[0][1], b[1][1], 0), 1);
    y = _mod(_mod(a[1][0], b[0][0], 0), _mod(a[1][1], b[1][0], 0), 1);
    z = _mod(_mod(a[1][0], b[0][1], 0), _mod(a[1][1], b[1][1], 0), 1);
    a[0][0] = w; a[0][1] = x; a[1][0] = y; a[1][1] = z;
}

void matrix_pow (int mat[2][2], ULL num)
{
    if (num < 2) return;
    
    int temp[2][2] = {{ 1, 1 }, { 1, 0 }};

    matrix_pow(mat, (long long)(num / 2));
    matrix_mul(mat, mat);
    if (num % 2 != 0) matrix_mul(mat, temp);
}

int fibo(ULL n)
{
    int matrix[2][2] = {{ 1, 1 }, { 1, 0 }};
    if (n == 0) return 0;
    matrix_pow(matrix, n - 1);
    return matrix[0][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ULL start, end;
    int fib_start, fib_end, ans;

    cin >> start >> end;
    fib_start = fibo(start + 1) - 1; fib_end = fibo(end + 2) - 1;
    ans = fib_end - fib_start;
    if (ans < 0) ans += mod;
    cout << ans << '\n';

    return 0;
}