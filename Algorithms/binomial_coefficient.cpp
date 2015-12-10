#include <iostream>
#include <vector>

using namespace std;

template <typename  T>
class BinomialCoefficient
{
    vector<vector<T>> bc;
public:
    BinomialCoefficient(unsigned long max_n, T mod) {
        bc = vector<vector<T>>(max_n + 1, vector<T>(max_n + 1, 0));
        for (int n = 0; n <= max_n; n++) {
            bc[n][0] = 1;
            for (int k = 1; k < n; k++) {
                bc[n][k] = bc[n-1][k-1] + bc[n-1][k];
                if (mod != -1) bc[n][k] %= mod;
            }
            bc[n][n] = 1;
        }
    }
    T operator()(int n, int k) { return bc[n][k]; }
};

int main()
{
    BinomialCoefficient<int> bc(10, -1);
    for (int n = 0; n < 10; n++) {
        for (int k = 0; k <= n; k++)
            cout << bc(n, k) << " ";
        cout << endl;
    }

    cout << endl;

    BinomialCoefficient<int> bc_mod(10, 50);
    for (int n = 0; n < 10; n++) {
        for (int k = 0; k <= n; k++)
            cout << bc_mod(n, k) << " ";
        cout << endl;
    }
}