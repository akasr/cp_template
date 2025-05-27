# Competitive Programming Templates

This repository contains comprehensive C++ templates for competitive programming contests including Codeforces, AtCoder, and CodeChef.

## Files Overview

### 1. `template.cpp` - Basic Template
- Clean and minimal template
- Good for beginners and quick problem solving
- Includes essential macros and utilities

### 2. `template_advanced.cpp` - Advanced Template
- Comprehensive template with many useful algorithms
- Includes data structures (DSU, Segment Tree)
- Graph algorithms (BFS, DFS)
- Number theory functions
- Best for complex problems

### 3. `template_interactive.cpp` - Interactive Problems
- Specialized for interactive problems
- Includes proper flush operations
- Example binary search for guess-the-number style problems

### 4. `template_contest_specific.cpp` - Contest Platform Specific
- Optimized for different contest platforms
- Platform-specific notes and configurations
- Handles different MOD values and constraints

### 5. `quick_reference.cpp` - Algorithm Reference
- Common algorithms and patterns
- Quick copy-paste snippets
- Useful for during contests

## Platform-Specific Notes

### Codeforces
- Usually multiple test cases (`cin >> t`)
- Time limit: 1-2 seconds
- Memory: 256MB
- MOD: 1e9+7
- Use `fast_io` for faster I/O

### AtCoder
- Usually single test case
- Time limit: 2 seconds  
- Memory: 1GB
- MOD: 998244353
- Precision problems are common

### CodeChef
- Usually multiple test cases
- Time limit: varies (1-5 seconds)
- Memory: 256MB
- MOD: 1e9+7
- Sometimes requires optimized I/O

## Usage Instructions

1. **For quick problems**: Use `template.cpp`
2. **For complex problems**: Use `template_advanced.cpp`
3. **For interactive problems**: Use `template_interactive.cpp`
4. **Need algorithm reference**: Check `quick_reference.cpp`

## Compilation

The workspace is configured with a build task. Use:
```bash
g++ -std=c++23 -fdiagnostics-color=always -g filename.cpp -o executable
```

Or use the VS Code build task: `Ctrl+Shift+P` → "Tasks: Run Build Task"

## Common Macros Explained

- `#define int long long` - Uses 64-bit integers by default
- `#define endl '\n'` - Faster line break
- `#define all(x) (x).begin(), (x).end()` - Shorthand for begin/end
- `#define sz(x) (int)(x).size()` - Get size as int
- `#define rep(i, a, b)` - Loop from a to b-1
- `fast_io` - Faster input/output

## Debug Mode

Compile with `-DLOCAL` flag to enable debug output:
```bash
g++ -DLOCAL -std=c++23 filename.cpp -o executable
```

## Tips for Contests

1. **Read the problem carefully** - Understand constraints and examples
2. **Check for edge cases** - n=1, empty input, maximum constraints
3. **Use appropriate template** - Don't over-engineer simple problems
4. **Test with examples** - Always verify with given test cases
5. **Watch for integer overflow** - Use long long when needed
6. **Time complexity** - Ensure your solution fits time limits
7. **Interactive problems** - Remember to flush output

## Common Patterns

### Multiple Test Cases
```cpp
int t;
cin >> t;
while (t--) {
    solve();
}
```

### Single Test Case
```cpp
int t = 1;
// Don't read t
while (t--) {
    solve();
}
```

### Interactive Problem
```cpp
cout << "? " << query << endl;
cout.flush();
int response;
cin >> response;
```

## Useful STL Functions

- `sort(all(v))` - Sort vector
- `reverse(all(v))` - Reverse vector
- `unique(all(v))` - Remove duplicates (after sorting)
- `lower_bound()` - First element >= target
- `upper_bound()` - First element > target
- `__builtin_popcount()` - Count set bits
- `__gcd(a, b)` - GCD function

## Contest Strategy

1. **Read all problems first** - Get overview of difficulty
2. **Start with easiest** - Build momentum
3. **Implement brute force first** - Then optimize if needed
4. **Don't get stuck** - Move to next problem if stuck too long
5. **Check constraints** - They often hint at the solution approach
6. **Use templates wisely** - Don't include unnecessary code

Good luck with your competitive programming journey! 🚀
