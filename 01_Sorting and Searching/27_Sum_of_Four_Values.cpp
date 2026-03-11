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
	long long k;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].ff;
		arr[i].ss = i + 1;
	}

	sort(arr.begin(), arr.end());

	for(int i = 0; i < n - 3; i++){
		for(int j = i + 1; j < n - 2; j++){
			int l = j + 1, r = n - 1;
			while(l < r){
				long long sum = (long long)arr[i].ff + arr[j].ff + arr[l].ff + arr[r].ff;
				if(sum == k){
					cout << arr[i].ss << " " << arr[j].ss << " " << arr[l].ss << " " << arr[r].ss;
					return;
				}
				else if(sum < k){
					l++;
				}
				else r--;
			}
		}
	}

	cout << "IMPOSSIBLE";

	return;

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