#include <bits/stdc++.h>
using namespace std;

bool isLocalMax(const vector<vector<int>>& arr, int i, int j, int m, int n) {
    int current = arr[i][j];
    if (i > 0 && arr[i - 1][j] > current) return false; 
    if (i > 0 && j > 0 && arr[i - 1][j - 1] > current) return false;
    if (i < m - 1 && arr[i + 1][j] > current) return false; 
    if (i > 0 && j < n - 1 && arr[i - 1][j + 1] > current) return false;
    if (j > 0 && arr[i][j - 1] > current) return false; 
    if (j < n - 1 && arr[i][j + 1] > current) return false; 
    if (i < m - 1 && j > 0 && arr[i + 1][j - 1] > current) return false; 
    if (i < m - 1 && j < n - 1 && arr[i + 1][j + 1] > current) return false;
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> nuxt;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isLocalMax(arr, i, j, m, n)) {
                nuxt.push_back(arr[i][j]);
            }
        }
    }

    for (size_t i = 0; i < nuxt.size(); i++) {
        cout << nuxt[i] << " ";
    }
    cout << endl;

    return 0;
}
