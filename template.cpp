#include <bits/stdc++.h>
using namespace std;

// ==================== MACROS ====================
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b)-1; i >= (a); i--)
#define trav(a, x) for(auto& a : x)
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// ==================== TYPEDEFS ====================
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef map<int, int> mii;

// ==================== CONSTANTS ====================
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const double EPS = 1e-9;
const int MAXN = 2e5 + 5;

// ==================== UTILITY FUNCTIONS ====================
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int power(int a, int b, int mod = MOD) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int modinv(int a, int mod = MOD) {
    return power(a, mod - 2, mod);
}

// ==================== DEBUG TEMPLATE ====================
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << endl
    #define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#else
    #define debug(x)
    #define debug2(x, y)
#endif

// ==================== MAIN SOLUTION ====================
void solve() {
    // Your solution here
    
}

int32_t main() {
    fast_io;
    
    int t = 1;
    // Uncomment for multiple test cases
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}