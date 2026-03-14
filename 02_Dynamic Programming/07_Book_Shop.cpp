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

int solve(int n, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
	if(n < 0) return 0;
	if(dp[n][x] != -1) return dp[n][x];

	int ans = 0;
	ans = max(ans, solve(n - 1, x, price, pages, dp));
	if(x - price[n] >= 0) ans = max(ans, pages[n] + solve(n - 1, x - price[n], price, pages, dp));

	return dp[n][x] = ans;
}

void init()
{
	int n, x;
	cin >> n >> x;

	vi price(n), pages(n);
	scan(price);
	scan(pages);
	vector<vector<int>> dp(n, vector<int>(x + 1, 0));

	// cout << solve(n - 1, x, price, pages, dp) << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= x; j++){
			if(i == 0){
				dp[i][j] = (price[i] <= j) ? pages[i] : 0;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], (j - price[i] >= 0) ? pages[i] + dp[i - 1][j - price[i]] : 0);
			}
		}
	}

	cout << dp[n - 1][x] << endl;

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