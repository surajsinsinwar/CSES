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

long long solve(vector<string> &v, int i, int j, vector<vector<long long>> &dp){
	if(i < 0 || j < 0) return 0;
	if(v[i][j] == '*') return 0;
	if(i == 0 && j == 0) return 1;

	if(dp[i][j] != -1) return dp[i][j];

	long long ans = 0;
	ans += solve(v, i - 1, j, dp);
	ans %= mod;
	ans += solve(v, i, j - 1, dp);
	ans %= mod;

	dp[i][j] = ans;
	return ans;
}

void init()
{
	int n;
	cin >> n;
	vector<string> v(n);
	scan(v);

	vector<vector<long long>> dp(n, vector<long long>(n, -1));

	cout << solve(v, n - 1, n - 1, dp) << endl;

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