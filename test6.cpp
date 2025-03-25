#include <bits/stdc++.h>

using namespace std;
vector<int> longest_increasing_subsequence(int N, vector<int>& A) {
    if (N == 0) return {};
    vector<int> dp(N, 1);
    vector<int> prev(N, -1);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    while (maxIndex != -1) {
        lis.push_back(A[maxIndex]);
        maxIndex = prev[maxIndex];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> result = longest_increasing_subsequence(N, A);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
