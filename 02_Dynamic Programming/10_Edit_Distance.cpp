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

int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
	if(i < 0) return j + 1;
	if(j < 0) return i + 1;
	if(dp[i][j] != -1) return dp[i][j];
	if(a[i] == b[j]) return dp[i][j] = solve(a, b, i - 1, j - 1, dp);
	return dp[i][j] = 1 + min({solve(a, b, i - 1, j, dp), solve(a, b, i, j - 1, dp), solve(a, b, i - 1, j - 1, dp)});
}

void init()
{
	string a, b;
	cin >> a >> b;

	vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));

	cout << solve(a, b, a.size() - 1, b.size() - 1, dp) << endl;

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