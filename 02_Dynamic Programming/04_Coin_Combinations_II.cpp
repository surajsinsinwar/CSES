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

long long solve(int n, int m, vi &coins, vector<vector<int>> &dp){
	if(m == 0) return 1;
	if(m < 0 || n < 0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	long long ans = 0;
	ans += solve(n - 1, m, coins, dp);
	ans += solve(n, m - coins[n], coins, dp);
	ans %= mod;
	return dp[n][m] = ans;
}

void init()
{
	int n, m;
	cin >> n >> m;
	vi coins(m);
	scan(coins);

	vector<vector<int>> dp(2, vector<int>(m + 1, 0));
	int flag = 0;

	// cout << solve(n - 1, m, coins, dp) << endl;

	dp[0][0] = dp[1][0] = 1;
	for(int j = 0; j < n; j++){
		for(int i = 1; i <= m; i++){
			long long ans = 0;
			int idx = 1 - flag;
			if(j >= 1){
				ans += dp[idx][i];
			}
			if(i - coins[j] >= 0){
				ans += dp[flag][i - coins[j]];
			}
			ans %= mod;
			dp[flag][i] = ans;
		}
		flag = 1 - flag;
	}

	cout << dp[1 - flag][m] << endl;

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