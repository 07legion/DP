/*
* @Author: amish19
* @Date:   2021-03-29 18:13:41
* @Last Modified time: 2021-03-30 00:22:08
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
ll n, w;
vector<ll> v(MAX);
ll dp[MAX][MAX];

ll func(ll n, ll w) {
	if (w == 0 && n == -1) return 1;
	if(n == -1) return 0;
	if(dp[n][w] != -1) return dp[n][w];
	if(v[n] <= w) return dp[n][w] = (func(n-1, w-v[n]) + func(n-1, w));
	return dp[n][w] = func(n-1, w);
}

int main() {

	amish();
	memset(dp, false, sizeof dp);
	cin>>n>>w; 
	memset(dp, -1, sizeof dp);
	for(ll i=0;i<n;i++) cin>>v[i];
	cout<<func(n-1, w)<<"\n";
	v.clear(); 
	return 0;
}