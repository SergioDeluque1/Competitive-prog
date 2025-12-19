#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// Compute LIS starting at each index
// length_start[i] = LIS length starting at index i.

void compute_LIS_start(const vector<int>& a, vector<int>& length_start) 
{
    int N = a.size();
    length_start.assign(N, 1);

    // Go backward so dp[j] is already known for all j > i
    for (int i = N - 1; i >= 0; i--) 
    {
        for (int j = i + 1; j < N; j++) 
        {
            if (a[j] > a[i])
                length_start[i] = max(length_start[i], 1 + length_start[j]);
        }
    }
}


// Compute LIS ending at each index, using patience sorting

void compute_LIS_end(const vector<int>& a, vector<int>& length_end) 
{
    int N = a.size();
    length_end.assign(N, 0);

    vector<int> L;

    for (int i = 0; i < N; i++) 
    {
        int x = a[i];

        // find position to place x (for LIS ending at i)
        int pos = lower_bound(L.begin(), L.end(), x) - L.begin();

        if (pos == (int)L.size())
            L.push_back(x);
        else
            L[pos] = x;

        length_end[i] = pos + 1;
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;

        vector<int> numbers(N);
        vector<int> reversed(N);
        vector<int> length_start(N);
        vector<int> length_end_reversed(N);
        vector<int> length_end(N);

        // Read input + build reversed array for LDS simulation
        for (int i = 0; i < N; i++) 
        {
            cin >> numbers[i];
            reversed[N - 1 - i] = numbers[i];
        }

        // LIS starting at index i
        compute_LIS_start(numbers, length_start);

        // LIS computed on reversed
        compute_LIS_end(reversed, length_end_reversed);

        // Map reversed LIS-ending to original indices:
        for (int i = 0; i < N; i++)
            length_end[i] = length_end_reversed[N - 1 - i];

        // total = LIS_start[i] + LIS_end[i] - 1
        int best = 0;
        for (int i = 0; i < N; i++)
            best = max(best, length_start[i] + length_end[i] - 1);

        cout << best << "\n";
    }

    return 0;
}
