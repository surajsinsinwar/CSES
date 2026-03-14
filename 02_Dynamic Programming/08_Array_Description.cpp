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

int solve(vector<int> &a, int n, int m, int prv, vector<vector<int>> &dp){
	if(n < 0) return 1;
	if(dp[n][prv] != -1) return dp[n][prv];
	int ans = 0;
	if(a[n] != 0){
		if(prv != 0 && abs(a[n] - prv) > 1) return 0;
		ans = solve(a, n - 1, m, a[n], dp);
		ans %= mod;
	}
	else{
		if(prv == 0){
			for(int i = 1; i <= m; i++){
				ans += solve(a, n - 1, m, i, dp);
				ans %= mod;
			}
		}
		else{
			int gtr = prv + 1, lss = prv - 1;
			if(gtr <= m){
				ans += solve(a, n - 1, m, gtr, dp);
				ans %= mod;
			}
			if(lss >= 1){
				ans += solve(a, n - 1, m, lss, dp);
				ans %= mod;
			}
			ans += solve(a, n - 1, m, prv, dp);
			ans %= mod;
		}
	}

	return dp[n][prv] = ans;
}

void init()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	scan(a);

	vector<vector<int>> dp(n, vector<int>(m + 1, -1));

	int prv = 0;
	cout << solve(a, n - 1, m, prv, dp) << endl;

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