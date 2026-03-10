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

void init()
{
	int n;
	long long sum;
	cin >> n >> sum;
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	arr[0] = 0;
	long long prefix_end = 0, prefix_start = 0, ans = 0;
	vector<long long> prefix(n + 1);
	for(int i = 0; i <= n; i++){
		prefix_end += arr[i];
		prefix[i] = prefix_end;
	}
	int j = 0, k = 0;
	for(int i = 1; i <= n; i++){
		while(j <= n && prefix[i] - prefix[j] > sum){
			j++;
		}
		if(prefix[i] - prefix[j] < sum){
			continue;
		}
		k = max(k, j);
		while(k <= n && prefix[i] - prefix[k] == sum){
			k++;
		}
		ans += (k - j);
	}
	cout << ans;

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