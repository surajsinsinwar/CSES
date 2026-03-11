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

int solve(int m,int n, vector<int> &coins, vector<int> &dp){
	if(m == 0) return 0;
	if(m < 0) return -1;
	if(dp[m] != -1) return dp[m];
	int ans = INT_MAX;
	for(int i = 0; i < n; i++){
		int sub_ans = solve(m - coins[i], n, coins, dp);
		if(sub_ans != -1){
			ans = min(ans, sub_ans + 1);
		}
	}
	return dp[m] = (ans == INT_MAX ? -1 : ans);
}

void init()
{
	int n, m;
	cin >> n >> m;
	vector<int> coins(n);
	scan(coins);

	vector<int> dp(m + 1, -1);

	// solve(m, n, coins, dp);
	// cout << dp[m] << endl;

	dp[0] = 0;
	for(int i = 1; i <= m; i++){
		int ans = INT_MAX;
		for(int j = 0; j < n; j++){
			if(i - coins[j] >= 0 && dp[i - coins[j]] != -1){
				ans = min(ans, dp[i - coins[j]] + 1);
			}
		}
		dp[i] = (ans == INT_MAX ? -1 : ans);
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