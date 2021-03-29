/*
* @Author: amish19
* @Date:   2021-03-29 18:10:26
* @Last Modified time: 2021-03-29 18:11:16
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    private:
        int dp[1002][1002]; 
    public:
    Solution() {
        memset(dp, -1, sizeof dp);
    }
    int knapSack(int w, int wt[], int pro[], int n) {
	    if (n-1 == -1 || w == 0) return 0;
    	if (dp[n-1][w] != -1) return dp[n-1][w];
    	if(wt[n-1] <= w) {
    		return dp[n-1][w] = max(pro[n-1] + knapSack(w - wt[n-1], wt, pro, n-1), knapSack(w, wt, pro, n-1));
    	}
    	return dp[n-1][w] = knapSack(w, wt, pro, n-1);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  