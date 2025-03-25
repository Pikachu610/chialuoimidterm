#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> subsequences; 
    vector<int> current_subseq; 
    for (int i = 0; i < N; i++) {
        current_subseq.clear(); 
        current_subseq.push_back(A[i]);  // Bắt đầu dãy con mới từ A[i]

        // Tiếp tục tìm dãy con tăng dần từ phần tử A[i]
        for (int j = i + 1; j < N; j++) {
            if (A[j] > current_subseq.back()) {  // Nếu A[j] > phần tử cuối của dãy con hiện tại
                current_subseq.push_back(A[j]);  // Thêm A[j] vào dãy con
            }
        }

        // Lưu dãy con hiện tại vào mảng 2 chiều
        subsequences.push_back(current_subseq);
    }

    // Tìm dãy con dài nhất
    vector<int> longest_subseq;
    for (const auto& subseq : subsequences) {
        if (subseq.size() > longest_subseq.size()) {
            longest_subseq = subseq;
        }
    }

    // In ra dãy con dài nhất
    for (int num : longest_subseq) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
