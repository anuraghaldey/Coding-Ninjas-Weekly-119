// Problem statement
// You are given an array ‘A’ containing the distinct coordinates of ‘N’ cities
// numbered from ‘0’ to ‘N - 1’. Initially you can select any coordinate as your
// starting point.

// You can only move in either left or right direction during the whole journey.
// Changing the direction is not allowed, so you have to decide your direction
// before continuing the journey. You have to visit exactly ‘N - 2’ cities by
// moving minimum distance possible.

// Your task is to tell the minimum distance that is covered to visit exactly ‘N
// - 2’ cities and return it.

// Example:
// ‘N’ = 4
// ‘A’ = [-1,  3,  2,  -2,  5]
// Here, ‘0th’ city is present at coordinate ‘-1’, ‘1st’ city is present at
// coordinate ‘3’, ‘2nd’ city is present at coordinate ‘2’, ‘3rd’ city is
// present at coordinate ‘-2’, and ‘4th’ city is present at coordinate ‘5’.

// The best possible way is to choose coordinate ‘2’ as a starting point and
// follow the path: 2 -> 3 -> 4 -> 5. Here, you’ve visited exactly ‘N - 2’
// cities (‘1st’, ‘2nd’, and ‘4th’).

// So, the minimum moves required is ‘3’.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'T' <= 10
// 3 <= 'N' <= 10^5
// -10^9 <= A[i] <= 10^9

// Time Limit: 1 sec

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
long double PI = acos(-1.0);
#define fastio()                                                               \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define pb push_back
#define NL cout << endl;
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define ff(i, l, r) for (int i = l; i < r; i++)
#define fr first
#define sc second
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define returnYes()                                                            \
    yes();                                                                     \
    return
#define returnNo()                                                             \
    no();                                                                      \
    return

const int MOD = (1e9 + 7);
/*1sec -10^7-10^8 OPS APPROX
int- (-10^-9 to 10^9)RANGE
long (-10^12 to 10^12)RANGE
long long(-10^18 to 10^18)RANGE
(a+b)%M=((a%M)+(b%M))%M
(a*b)%M=((a%M)*(b%M))%M
(a-b)%M=((a%M)-(b%M)+M)%M
(a/b)%M=((a%M)*(b^-1)%M)%M
*/
#ifdef ANURAG
#define debug(x)                                                               \
    cerr << #x << ": ";                                                        \
    _print(x);                                                                 \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void read(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}
void read1(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void read2dn(vii &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cin >> a[i][j];
        }
    }
}
void read2dcustom(vii &a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

void print(vector<int> a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int binpow1(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b % 2) {
        return a * binpow1(a, b - 1) % MOD;
    }
    int ans = binpow1(a, b / 2);
    return (ans * ans) % MOD;
}
int fact[100004];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}
int ncrpc(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    int d = (fact[r] * fact[n - r]) % MOD;
    return fact[n] * binpow1(d, MOD - 2) % MOD;
}
int NCR(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    n %= MOD;
    r %= MOD;
    int ans = 1;
    for (int i = 0; i < r; i++) {
        ans = (ans % MOD * (((n % MOD) - (i % MOD)) % MOD) % MOD) % MOD;
        int m = binpow(i + 1, MOD - 2, MOD);
        ans = (ans * m) % MOD;
    }
    return (ans % MOD + MOD) % MOD;
}

const int N = 1e3 + 8;
int lb(vector<pair<int, int>> vp, int v) {
    int l = 0, h = vp.size() - 1;
    int ans = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;

        if (vp[mid].second >= v) {
            ans = vp[mid].first;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
void pfsi(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
}
int coveredCities (int n, vector <int> &a) {
   if(n<=3){
      return 0;
   }
   sort(a.begin(),a.end());

   int mn=INT_MAX;
   int b=n-3;

   for(int i=b;i<n;i++){
      mn=min(mn,abs(a[i-b]-a[i]));
   }
   return mn;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    read1(a, n);
    cout << coveredCities(n, a) << endl;
}

signed main() {
    fastio();

#ifdef Anurag5623
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}