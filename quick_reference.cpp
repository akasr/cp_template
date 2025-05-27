// ==================== COMPETITIVE PROGRAMMING QUICK REFERENCE ====================

// ==================== COMMON ALGORITHMS ====================

// Binary Search
int binary_search(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Binary Search on Answer
bool check(int x) {
    // return true if x is a valid answer
    return true;
}

int binary_search_answer(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// Two Pointers
int two_pointers(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) return l; // or return {l, r}
        if (sum < target) l++;
        else r--;
    }
    return -1;
}

// Sliding Window
int sliding_window(vector<int>& arr, int k) {
    int n = arr.size();
    int window_sum = 0, max_sum = 0;
    
    // First window
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    max_sum = window_sum;
    
    // Slide the window
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}

// ==================== GRAPH ALGORITHMS ====================

// DFS
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// BFS
vector<int> bfs(int start, int n) {
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

// Dijkstra's Algorithm
vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ==================== DYNAMIC PROGRAMMING PATTERNS ====================

// 1D DP
vector<int> dp(n + 1, 0);
for (int i = 1; i <= n; i++) {
    // dp[i] = some function of dp[i-1], dp[i-2], etc.
}

// 2D DP
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        // dp[i][j] = some function of dp[i-1][j], dp[i][j-1], etc.
    }
}

// Knapsack DP
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// ==================== NUMBER THEORY ====================

// GCD and LCM
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// Fast Exponentiation
int power(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Modular Inverse
int modinv(int a, int mod) {
    return power(a, mod - 2, mod);
}

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// ==================== USEFUL STL FUNCTIONS ====================

// Sorting
sort(arr.begin(), arr.end());                    // Ascending
sort(arr.begin(), arr.end(), greater<int>());    // Descending

// Binary Search in STL
lower_bound(arr.begin(), arr.end(), x);  // First element >= x
upper_bound(arr.begin(), arr.end(), x);  // First element > x
binary_search(arr.begin(), arr.end(), x); // Returns true if x exists

// Unique elements
sort(arr.begin(), arr.end());
arr.erase(unique(arr.begin(), arr.end()), arr.end());

// Next/Previous permutation
next_permutation(arr.begin(), arr.end());
prev_permutation(arr.begin(), arr.end());

// ==================== COMMON PATTERNS ====================

// Frequency counting
map<int, int> freq;
for (int x : arr) freq[x]++;

// Prefix sums
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
// Sum from l to r: prefix[r + 1] - prefix[l]

// Coordinate compression
vector<int> coords = arr;
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());
for (int& x : arr) {
    x = lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

// ==================== DEBUGGING TIPS ====================
/*
1. Check for integer overflow (use long long)
2. Check array bounds
3. Initialize variables properly
4. Handle edge cases (n=1, empty input, etc.)
5. Read the problem statement carefully
6. Check for off-by-one errors
7. Use assert() for debugging
8. Print intermediate values when debugging
*/
