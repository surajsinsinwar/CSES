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

int solve(vector<int> &a, vector<int> &v, int i, int j, vector<vector<int>> &dp){
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(a[i] == v[j]) return dp[i][j] = 1 + solve(a, v, i - 1, j - 1, dp);
	return dp[i][j] = max(solve(a, v, i - 1, j, dp), solve(a, v, i, j - 1, dp));
}

void init()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	scan(a);
	scan(b);

	vector<vector<int>> dp(n, vector<int>(m, -1));
	// cout << solve(a, b, n - 1, m - 1, dp) << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]) dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
			else dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
		}
	}

	vector<int> path;
	int i = n - 1, j = m - 1, ma = dp[i][j];
	while(i >= 0 && j >= 0){
		if(a[i] == b[j]){
			path.pb(a[i]);
			i--, j--;
			ma--;
		}
		else if(i > 0 && dp[i - 1][j] == ma) i--;
		else j--;
	}

	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	print(path);
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