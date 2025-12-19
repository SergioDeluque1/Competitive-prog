#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for speed
    cin.tie(nullptr);            // Untie cin from cout to avoid unnecessary flushing

    // Fixed coin denominations in cents
    const int coin[6] = {5, 10, 20, 50, 100, 200};

    while (true) { // Process multiple test cases
        vector<int> avail(6);   // Store available quantity of each coin
        int zero = 0;           

        // Read the availability of each coin type
        for (int i = 0; i < 6; i++) {
            cin >> avail[i];
            if (avail[i] == 0) zero++; // Count zeros to check for termination
        }

        // If all six coin counts are zero, terminate input
        if (zero == 6) break;

        // Read target amount as a string to safely parse X.Y
        string s;
        cin >> s;

        // Find the decimal point
        int dot = s.find('.');

        // Extract dollars and cents separately
        int x = stoi(s.substr(0, dot));       // Dollars
        int y = stoi(s.substr(dot + 1));      // Cents

        // Total value in cents
        int value = x * 100 + y;

        const int INF = 1e9; // Large number representing impossible value

        // DP array: dp[v] = minimum number of coins needed to form v cents
        vector<int> dp(value + 1, INF);
        dp[0] = 0; // Base case: zero coins needed to make 0 cents

        // Process each coin type
        for (int i = 0; i < 6; i++) {
            int c = coin[i];   // Coin value
            int a = avail[i];  // Available quantity of this coin

            // Binary decomposition trick:
            // Represent the number of coins as sum of powers of two
            // e.g., 13 coins -> 1, 2, 4, 6
            int k = 1;
            while (a > 0) {
                int use = min(k, a);        // Number of coins to use in this batch
                int weight = use * c;       // Total value contributed by this batch

                // Standard 0/1 knapsack DP transition (reverse order)
                // We iterate from high to low to avoid using the same batch multiple times
                for (int v = value; v >= weight; v--) {
                    dp[v] = min(dp[v], dp[v - weight] + use);
                }

                a -= use;    // Reduce remaining coins of this type
                k <<= 1;     // Double k for next power of two
            }
        }

        // Output the result
        if (dp[value] >= INF)
            cout << "impossible\n"; // Cannot form the target value with given coins
        else
            cout << dp[value] << "\n"; // Minimum number of coins needed
    }

    return 0;
}
