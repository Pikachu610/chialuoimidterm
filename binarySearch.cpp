#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int target) {
    int left = 0; //chỉ số phần tử đầu
    int right = arr.size() - 1; //chỉ số phần tử cuối

    while (left <= right) { // khi k tìm thấy phần tử target

        int mid = left + (right - left) / 2;// chỉ số phần tử ở giữa

        if (arr[mid] == target) { // nếu phần tử ở giữa bằng target
            return mid;  //chỉ sô phần tử ở giữa
        }

        if (arr[mid] > target) { // lớn hơn target
            right = mid - 1; //
        } else { // nhỏ hơn target
            left = mid + 1;
        }
    }
    return 0;
}
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 17;
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Phần tử " << target << " được tìm thấy tại vị trí: " << result + 1 << endl;
    } else {
        cout << "Phần tử không có trong mảng." << endl;
    }
    return 0;
}