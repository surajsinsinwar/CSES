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

bool check(vector<int> &arr, long long mid, int k)
{
	int n = arr.size();
	long long sum = 0;
	int count = 1;

	for(int i = 0; i < n; i++){
		if(arr[i] > mid){
			return false;
		}
		if(sum + arr[i] > mid){
			count++;
			sum = arr[i];
		}
		else{
			sum += arr[i];
		}
	}

	return count <= k;
}

void init()
{
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	scan(arr);

	long long l = 1, r = 0;
	for(int i = 0; i < n; i++){
		r += arr[i];
	}

	while(l <= r){
		long long mid = mid(l, r);
		if(check(arr, mid, k)){
			if(mid == l || !check(arr, mid - 1, k)){
				cout << mid << endl;
				return;
			}
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << endl;

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