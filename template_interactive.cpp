#include <bits/stdc++.h>
using namespace std;

// ==================== MACROS ====================
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// ==================== TYPEDEFS ====================
typedef vector<int> vi;
typedef pair<int, int> pii;

// ==================== CONSTANTS ====================
const int INF = 1e18;
const int MOD = 1e9 + 7;

// ==================== INTERACTIVE FUNCTIONS ====================
// Function to ask a query and get response
int ask(int x) {
    cout << "? " << x << endl;
    cout.flush();  // Important for interactive problems
    int response;
    cin >> response;
    return response;
}

// Function to give final answer
void answer(int x) {
    cout << "! " << x << endl;
    cout.flush();
}

// Alternative query functions for different problem types
int ask_range(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int response;
    cin >> response;
    return response;
}

void guess(int x) {
    cout << x << endl;
    cout.flush();
}

// ==================== MAIN SOLUTION ====================
void solve() {
    // Interactive problem solution here
    // Remember to use cout.flush() after each query
    
    // Example binary search for guessing number game:
    /*
    int l = 1, r = 1000000;
    while (l < r) {
        int mid = (l + r) / 2;
        int response = ask(mid);
        if (response == 0) {
            answer(mid);
            return;
        } else if (response == 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    answer(l);
    */
}

int32_t main() {
    // Note: Don't use fast_io for interactive problems as it might cause issues
    // fast_io;
    
    int t = 1;
    // cin >> t;  // Usually interactive problems have only one test case
    
    while (t--) {
        solve();
    }
    
    return 0;
}
