/*
* @Author: amish19
* @Date:   2021-03-31 12:18:23
* @Last Modified time: 2021-03-31 17:18:20
*/

#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        cout << cutRod(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function Template for C++
int dp[1002][1002];
int func(int v[], int n, int w) {
    if (n == -1 || w == 0) return 0;
    if (dp[n][w] != -1) return dp[n][w];
    if (n+1 <= w) return dp[n][w] = max(v[n] + func(v, n, w-n-1), func(v, n-1, w));
    return dp[n][w] = func(v, n-1, w);
}
int cutRod(int price[], int n) {
    int w = n;
    memset(dp, -1, sizeof dp);
    return func(price, n-1, w);
}