/*
* @Author: amish19
* @Date:   2021-03-29 18:41:53
* @Last Modified time: 2021-03-29 20:03:08
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
bool dp[MAX][MAX];

bool func(ll n, ll w) {
	if (w == 0) return true;
	if (n == -1) return false;
	if (v[n] <= w) return dp[n][w] = (func(n-1, w-v[n]) || func(n-1, w));
	return dp[n][w] = func(n-1, w);
}

int main() {

	amish();
	cin>>n;
	ll sm = 0;
	for(ll i=0;i<n;i++) cin>>v[i], sm += v[i];
	memset(dp, false, sizeof dp);
	// cout<<func(n-1, 10)<<"\n";
	ll ans = INF;
	for(ll i=1;i<=1 + (sm/2);i++) {
		if(func(n-1, i)) {
			// memset(dp, false, sizeof dp);
			ans = min(ans, llabs(sm-(2*i)));
		}
	}
	cout<<ans<<"\n";
	v.clear(); 
	return 0;
}