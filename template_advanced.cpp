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
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqmin;

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

// ==================== NUMBER THEORY ====================
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> fact(MAXN), inv_fact(MAXN);
void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
}

// ==================== GRAPH ALGORITHMS ====================
class Graph {
public:
    int n;
    vector<vector<int>> adj;
    
    Graph(int n) : n(n), adj(n) {}
    
    void add_edge(int u, int v, bool directed = false) {
        adj[u].pb(v);
        if (!directed) adj[v].pb(u);
    }
    
    vector<int> bfs(int start) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    
    vector<bool> visited;
    void dfs(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
};

// ==================== DATA STRUCTURES ====================
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) : parent(n), rank(n, 0) {
        iota(all(parent), 0);
    }
    
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

class SegmentTree {
public:
    int n;
    vector<int> tree;
    
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
    
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

// ==================== DEBUG TEMPLATE ====================
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << endl
    #define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
    template<typename T> void print_vector(vector<T>& v) {
        cerr << "Vector: ";
        for (auto x : v) cerr << x << " ";
        cerr << endl;
    }
#else
    #define debug(x)
    #define debug2(x, y)
    template<typename T> void print_vector(vector<T>& v) {}
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
