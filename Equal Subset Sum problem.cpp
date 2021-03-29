/*
* @Author: amish19
* @Date:   2021-03-29 18:12:05
* @Last Modified time: 2021-03-29 18:16:55
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef long long int ll;

class Solution{
private:
    bool dp[1002][1002];
public:
    Solution() {
        memset(dp, false, sizeof dp);
    }
    bool func(int n, int w, int v[]) {
    	if (w == 0) return true;
    	if (n == -1) return false;
    	if(dp[n][w]) return true;
    	if (v[n] <= w) return dp[n][w] = (func(n-1, w-v[n], v) || func(n-1, w, v));
    	return dp[n][w] = func(n-1, w, v);
    }
    int equalSubset(int n, int W, int arr[]) {
        if(func(n-1, W, arr)) return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalSubset(N, W, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends