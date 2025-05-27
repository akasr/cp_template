#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void solve() {
    int n, k, numOnes = 0, numZeroes;
    string bin;

    cin >> n >> k;
    cin >> bin;

    for(int i = 0; i < n; i++){
      if(bin[i] == '1'){
        numOnes += 1;
      }
    }
    numZeroes = n-numOnes;
    int goodPairs = (numOnes/2)+(numZeroes/2);

    if(goodPairs == k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
}


int32_t main() {
    fast_io();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
