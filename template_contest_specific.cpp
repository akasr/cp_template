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
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// ==================== TYPEDEFS ====================
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// ==================== CONSTANTS ====================
const int INF = 1e18;
const int MOD = 1e9 + 7;        // For most problems
const int MOD_ATCODER = 998244353;  // Common in AtCoder
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

// ==================== PLATFORM-SPECIFIC NOTES ====================
/*
CODEFORCES:
- Usually multiple test cases (cin >> t)
- Time limit: typically 1-2 seconds
- Memory limit: usually 256MB
- Common MOD: 1e9+7
- Use fast_io for faster I/O

ATCODER:
- Usually single test case
- Time limit: typically 2 seconds
- Memory limit: usually 1GB
- Common MOD: 998244353
- Precision problems are common (use long double if needed)

CODECHEF:
- Usually multiple test cases
- Time limit: varies (1-5 seconds)
- Memory limit: usually 256MB
- Common MOD: 1e9+7
- Sometimes requires optimized I/O
*/

// ==================== MAIN SOLUTION ====================
void solve() {
    // Your solution here
    
}

int32_t main() {
    fast_io;
    
    int t = 1;
    
    // UNCOMMENT FOR MULTIPLE TEST CASES (Codeforces/CodeChef style)
    // cin >> t;
    
    // FOR ATCODER: Usually single test case, so keep t = 1
    
    while (t--) {
        solve();
    }
    
    return 0;
}
