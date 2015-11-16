#include <iostream>
#include <vector>

using namespace std;

// Binary Indexed Trees or Fenwick tree
//
// Update = O(log(n))
// Sum = O(log(n))
template<typename T>
class BIT {
    vector<T> v;

public:
    BIT(int n)
    {
        v = vector<T>(n, 0);
    }

    // returns sum of the range [0...b-1]
    T sum(int b)
    {
        T sum = 0;
        for (b++; b; b -= (b & (-b)))
        {
            sum += v[b-1];
        }
        return sum;
    }

    // returns sum of the range [a...b]
    T sum(int a, int b)
    {
        return sum(b) - (a ? sum(a - 1) : 0);
    }

    // update value of the k-th element by v (v can be +ve/inc or -ve/dec)
    // i.e., increment or decrement kth element by a value v
    void update(int idx, T value)
    {
        for (idx++; idx <= v.size(); idx += (idx & (-idx)))
        {
            v[idx-1] += value;
        }
    }
};

int main()  {
    BIT<int> b(10);
    for (int i = 0; i < 10; i++)
    {
        b.update(i, i);
    }

    cout << "Test values:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << b.sum(i, i) << endl;
    }
    cout << endl;

    cout << "Test sums from 0 to i:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << b.sum(i) << endl;
    }
    cout << endl;

    cout << "Sum of first 5 elements: " << b.sum(5) << endl;
    return 0;
}