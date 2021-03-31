/*
* @Author: amish19
* @Date:   2021-03-29 18:41:53
* @Last Modified time: 2021-03-31 13:50:35
*/

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;
const ll MAX = 1e3 + 9;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void amish() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	fastio;
}

string str1, str2;
ll dp[MAX][MAX];

ll func(ll i, ll j) {
	if (i == -1 || j == -1) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (str1[i] == str2[j]) return dp[i][j] = 1 + func(i-1, j-1);
	return dp[i][j] = max(func(i-1, j), func(i, j-1));
}

int main() {

	amish();
	memset(dp, -1, sizeof dp);
	cin>>str1>>str2;
	cout<<func(str1.length()-1, str2.length()-1)<<"\n";
	return 0;
}