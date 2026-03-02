#include<bits/stdc++.h>
using namespace std;

#ifdef declare


int32_t main() {
    file_i_o();

    return 0;
}





#else



typedef long long int     ll;
typedef long double       ld;
typedef pair<int, int>    pii;
typedef vector<pii>       vpii;
typedef vector<int>       vi;

typedef pair<ll, ll>      pll;
typedef vector<pll>       vpll;
typedef vector<ll>        vl;

#define pb                push_back
#define mod               (int)1e9+7
#define inf               (ll)1e18
#define endl              "\n"
#define vs                vector<string>
#define ump               unordered_map
#define mp                map
#define pq_max            priority_queue<ll>
#define pq_min            priority_queue<ll,vi,greater<ll> >
#define ff                first
#define ss                second
#define mid(l, r)         (l+(r-l)/2)
#define loop(i, a, b)     for(int i = (a); i <= (b); i++)
#define looprev(i, a, b)  for(int i = (a); i >= (b); i--)
#define print(arr, a, b)  for(int i = (a); i <= (b); i++) cout << arr[i] << " ";


void file_i_o() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define declare
#include __FILE__
#endif



/*
*****************************************************************************************************************
                                               Finding whether n is prime or not
*****************************************************************************************************************
*/

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    if (n <= 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

/*
*****************************************************************************************************************
                                               Finding exponential (a power b)
*****************************************************************************************************************
*/

long long exp(long long base, long long power)
{
    long long ans = 1;

    while (power > 0)
    {
        if (power & 1)
        {
            ans *= base;
            power--;
        }
        else
        {
            base *= base;
            power >>= 1;
        }
    }
    return ans;
}

/*
*****************************************************************************************************************
                                                Euclidean GCD
*****************************************************************************************************************
*/

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// Iterative
long long s, e, t;
long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a > b) {s = a; e = b;}
    else {s = b; e = a;}

    while (s > 0 && e > 0) {
        t = s;
        s = e % s;
        e = t;
    }

    return (s == 0 ? e : s);
}

/*
*****************************************************************************************************************
                                                Sieve Of Eratosthenes
*****************************************************************************************************************
*/

void sieve(int n)
{
    vector<bool> primes(n + 1, true);
    vector<int> v;

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
}

/*
*****************************************************************************************************************
                                                Prime Factorizattion
*****************************************************************************************************************
*/

void primefactorization(int n)
{
    vector<int> v;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) v.push_back(i);
        while (n % i == 0) n /= i;
    }

    if (n > 1) v.push_back(n);

    for (auto i : v)
    {
        printf("%d ", i);
    }

    return;
}

/*
*****************************************************************************************************************
Disjoint Set Union
*****************************************************************************************************************
*/

class UnionFind
{
public:
    vi p, r;

    void init(int n)
    {
        r.reserve(n + 1);
        p.reserve(n + 1);
        for (int i = 0; i <= n; i++) p[i] = i , r[i] = 1;
        return;
    }

    int findSet(int x)
    {
        if (p[x] == x) return x;
        return p[x] = findSet(p[x]);
    }

    bool isSameSet(int a, int b) { return (findSet(a) == findSet(b)); }

    void unionSet(int x, int y)
    {
        if (!isSameSet(x, y))
        {
            x = findSet(x); y = findSet(y);
            if (r[x] >= r[y]) p[y] = x , r[x] += r[y];
            else p[x] = y , r[y] += r[x];
        }
        return;
    }

    int numDisjointSets(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            p[i] = findSet(i);
            if (p[i] == i) count++;
        }
        return count;
    }

    int sizeOfSet(int x) { return r[findSet(p[x])];}
};

/*
*****************************************************************************************************************
Square Root Decomposition
*****************************************************************************************************************
*/

class squareRootDecomposition {
public:
    int bucketSize;
    int numberOfBuckets;
    vector<int> buckets;

    void preComputation(vector<int> &v, int &n) {
        bucketSize = sqrt(n);
        numberOfBuckets = ceil(n * 1.0 / bucketSize);

        buckets.resize(numberOfBuckets, INT_MAX);
        for (int i = 0; i < n; i++) {
            buckets[i / bucketSize] = min(buckets[i / bucketSize], v[i]);
        }

        return;
    }
    int answerQuery(vector<int> &v, int &l, int &r) {
        int bucketNumberLeft = l / bucketSize;
        int bucketNumberRight = r / bucketSize;

        int ans = v[l];
        if (bucketNumberLeft == bucketNumberRight) {
            ans = computeAns(v, l, r);
        }
        else {
            ans = min(ans, computeAns(v, l, (bucketNumberLeft + 1) * bucketSize - 1));
            ans = min(ans, computeAns(v, bucketNumberRight * bucketSize, r));
            ans = min(ans, computeAns(buckets, bucketNumberLeft + 1, bucketNumberRight - 1));
        }

        return ans;
    }

    // below functions Will not be called from outside of the class
    int computeAns(vector<int> &v, int s, int e) {
        int ans = INT_MAX;
        for (int i = s; i <= e; i++) ans = min(ans, v[i]);
        return ans;
    }
};

/*
*****************************************************************************************************************
Sparce Table
*****************************************************************************************************************
*/

class sparceTable {
public:
    int ln;
    vector<vector<int>> mat;

    void preComputation(vector<int> &v, int &n) {
        ln = log2(n) + 1;
        mat.resize(n);
        for (int i = 0; i < n; i++) mat[i].resize(ln);

        for (int j = 0; j < ln; j++) {
            for (int i = 0; i < n; i++) {
                if (j == 0) mat[i][j] = v[i];
                else if (i + pow(2, j - 1) < n) mat[i][j] = min(mat[i][j - 1], mat[i + pow(2, j - 1)][j - 1]);
            }
        }

        return;
    }

    int answerQuery(int &l, int &r) {
        int p = 0, idx = l, diff = r - l + 1, ans = INT_MAX;

        while (diff) {
            if (diff & 1) {
                ans = min(ans, mat[idx][p]);
                idx += pow(2, p);
            }
            p++;
            diff >>= 1;
        }

        return ans;
    }

    int answerQueryInOne(int &l, int &r) {
        int diff = r - l + 1, len = log2(diff);
        int ans = min(mat[l][len], mat[r - pow(2, len) + 1][len]);

        return ans;
    }
};

