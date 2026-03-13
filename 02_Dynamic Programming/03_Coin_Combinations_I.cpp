#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order, order_of_key

#define pb push_back
#define mod (int)1e9 + 7
#define inf (ll)1e18
#define endl "\n"
#define vs vector<string>
#define ump unordered_map
#define mp map
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define looprev(i, a, b) for (int i = a; i >= b; i--)
#define print(a)       \
	for (auto &it : a) \
		cout << it << " ";
#define scan(a)        \
	for (auto &it : a) \
		cin >> it;

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

long long solve(int n, int m, vector<int> &coins, vector<long long> &dp){
	if(m == 0) return 1;
	if(dp[m] != -1) return dp[m];
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(coins[i] <= m){
			ans += solve(n, m - coins[i], coins, dp);
			ans %= mod;
		}
	}

	return dp[m] = ans;
}

void init()
{
	int n, m;
	cin >> n >> m;
	vi coins(m);
	scan(coins);
	vector<long long> dp(m + 1, 0);

	// cout << solve(n, m, coins, dp) << endl;
	dp[0] = 1;
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < n; j++){
			if(coins[j] <= i){
				dp[i] += dp[i - coins[j]];
				dp[i] %= mod;
			}
		}
	}

	cout << dp[m] << endl;

	return;
}

int main()
{
	file_i_o();

	int t = 1;
	// cin >> t;

	while (t--)
	{
		init();
	}

	return 0;
}