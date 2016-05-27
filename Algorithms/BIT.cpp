#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Tree / Fenwick tree
// Add = O(log(n))
// Sum = O(log(n))
template<typename T>
class BIT {
    private:
        vector<T> v;

    public:
        BIT(int n) : v(vector<T>(n + 1, 0)) {}

        // returns sum of the range [0...idx]
        T sum(int idx)
        {
            T sum = 0;
            for (idx++; idx; idx -= idx & -idx)
            {
                sum += v[idx];
            }
            return sum;
        }

        // returns sum of the range [a...b]
        T sum(int a, int b)
        {
            return sum(b) - sum(a - 1);
        }

        // add value to the idx-th element
        void add(int idx, T value)
        {
            for (idx++; idx < v.size(); idx += idx & -idx)
            {
                v[idx] += value;
            }
        }
};

int main()  {
    BIT<int> bit(10);
    for (int i = 0; i < 10; i++)
    {
        bit.add(i, i);
    }

    cout << "Test values:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i << ", " << i << "]: " << bit.sum(i, i) << endl;
    }
    cout << endl;

    cout << "Test ranges:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[0, " << i << "]: " << bit.sum(i) << endl;
    }
    cout << endl;
    for (int i = 0; i < 9; i++) {
        cout << "[" << i << ", " << i + 1 << "]: " << bit.sum(i, i+1) << endl;
    }

    return 0;
}
