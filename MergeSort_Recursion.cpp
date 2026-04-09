#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
// merge
void merge(vector<int> &arr, int left, int mid, int right)
{
    // tao 2 vector buffer
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    // 2 pointers to compare
    int leftPtr = 0;
    int rightPtr = 0;
    
    while(leftPtr < leftArr.size() && rightPtr < rightArr.size())
    {
        if(leftArr[leftPtr] <= rightArr[rightPtr]) arr[left++] = leftArr[leftPtr++];
        else arr[left++] = rightArr[rightPtr++];
    }

    while(leftPtr < leftArr.size()) arr[left++] = leftArr[leftPtr++];
    while(rightPtr < rightArr.size()) arr[left++] = rightArr[rightPtr++];
}
// mergeSort
void mergeSort(vector<int> &arr, int left, int right)
{
    // guard clause
    if(left >= right) return;

    // logic start!
    int mid = left + (right - left)/2;

    // recursion
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
// function overload to fit the testing function
void mergeSort(vector<int> &arr)
{
    if(!arr.empty())
    {
        mergeSort(arr, 0, arr.size() - 1);
    }
};

// unit_testing
// Kiểm tra mảng đã sắp xếp chưa
bool isSorted(const vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

// Hàm test tổng quát
void runTests(void (*sortFunc)(vector<int>&)) {
    vector<vector<int>> testCases = {
        {},                         // Rỗng
        {10},                       // 1 phần tử
        {1, 2, 3, 4, 5},            // Đã sắp xếp
        {5, 4, 3, 2, 1},            // Ngược
        {2, 2, 1, 1, 3, 3},         // Trùng lặp
        {9, -1, 4, 0, 5, 2}         // Số âm và số 0
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> arr = testCases[i];
        sortFunc(arr);

        if (isSorted(arr)) {
            cout << "Test Case " << i << ": PASSED" << endl;
        } else {
            cout << "Test Case " << i << ": FAILED" << endl;
        }
    }
}

int main()
{
    runTests(mergeSort);
}