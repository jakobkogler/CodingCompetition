#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SegmentTree
{
    private:
        vector<T> data;
        T max_value = INT_MAX;

        T func(T a, T b)
        {
            return min(a, b);
        }

    public:
        SegmentTree(int n)
        {
            int size = 1;
            while (size < n) size *= 2;
            size = size * 2 - 1;
            data = vector<T>(size, max_value);
        }

        SegmentTree(vector<T> a) : SegmentTree(a.size())
        {
            copy(a.begin(), a.end(), data.begin() + data.size() / 2);

            for (int i = data.size() / 2 - 1; i >= 0; i--) {
                data[i] = func(data[2*i+1], data[2*i+2]);
            }
        }

        T minimum_of_range(int left, int right, int idx = 0, int low = 0, int high = -1)
        {
            if (high == -1)
                high = data.size() / 2;
            
            if (left <= low && right >= high)
                return data[idx];

            if (right < low || left > high)
                return max_value;
           
            int dist = (high + 1 - low) / 2;
            T l = minimum_of_range(left, right, 2*idx+1, low, low + dist - 1);
            T r = minimum_of_range(left, right, 2*idx+2, low + dist, high);
            return func(l, r);
        }

        void update(int idx, T val)
        {
            idx += data.size() / 2;
            data[idx] = val;

            while (idx > 0)
            {
                idx = (idx - 1) / 2;
                data[idx] = func(data[2*idx+1], data[2*idx+2]);
            };
        }
};

int main()
{
    SegmentTree<int> st(vector<int>{51, 27, 17, 2, 71, 94, 65, 47, 30, 69});

    cout << st.minimum_of_range(0, 9) << endl;
    cout << st.minimum_of_range(8, 8) << endl;

    cout << st.minimum_of_range(1, 3) << endl;
    cout << st.minimum_of_range(3, 5) << endl;

    st.update(3, 100);
    cout << st.minimum_of_range(0, 9) << endl;

    return 0;
}

