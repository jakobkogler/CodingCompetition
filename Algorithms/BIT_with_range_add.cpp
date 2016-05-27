#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Tree / Fenwick tree
// Add = O(log(n))
// Sum = O(log(n))
template<typename T>
class BIT {
    private:
        vector<T> v_mul, v_add;

    public:
        BIT(int n) : v_mul(vector<T>(n + 1, 0)), 
                     v_add(vector<T>(n + 1, 0)) {}

        // returns sum of the range [0...idx]
        T sum(int idx)
        {
            T mul = 0;
            T add = 0;
            T start = idx;
            for (idx++; idx; idx -= idx & -idx)
            {
                mul += v_mul[idx];
                add += v_add[idx];
            }
            return mul * start + add;
        }

        // returns sum of the range [a...b]
        T sum(int a, int b)
        {
            return sum(b) - sum(a - 1);
        }

        // add a value to the range [a, b]
        void range_add(int a, int b, int val)
        {
            internal_add(a, val, -val * (a - 1));
            internal_add(b, -val, val * b);
        }
        
    private:
        void internal_add(int idx, T mul, T add)
        {
            for (idx++; idx < v_mul.size(); idx += idx & -idx)
            {
                v_mul[idx] += mul;
                v_add[idx] += add;
            }
        }
};

int main()  {
    BIT<int> bit(5);
    
    bit.range_add(0, 0, 5);
    cout << bit.sum(0) << endl;
    cout << bit.sum(1) << endl;
    cout << endl;

    BIT<int> bit2(6);
    bit2.range_add(1, 4, 2);
    for (int i = 0; i < 6; i++) {
        cout << bit2.sum(i) << endl;
    }
    bit2.range_add(2, 3, 100);
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << bit2.sum(i) << endl;
    }
    cout << endl;
    cout << bit2.sum(3, 3) << endl;

    return 0;
}
