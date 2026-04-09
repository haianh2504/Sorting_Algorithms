#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// HeapSort
// heapify
void heapify(vector<int> &arr, int lastNonLeaf, int n)
{
    // find the largest element -> push it to the is-checked node
    int largestIndex = lastNonLeaf;
    int left = 2*lastNonLeaf + 1;
    int right = 2*lastNonLeaf + 2;
    if(left < n && arr[left] > arr[largestIndex]) largestIndex = left;
    if(right < n && arr[right] > arr[largestIndex]) largestIndex = right;

    // check for a neccessary swap
    if(largestIndex != lastNonLeaf)
    {
        swap(arr[largestIndex], arr[lastNonLeaf]);
        heapify(arr, largestIndex, n);
    }
};
// Build Max-Heap
void buildMaxHeap(vector<int> &arr)
{
    // find the last non-leaf
    int lastNonLeaf = (arr.size() - 1)/2;
    // go from the last nonLeaf to the top root
    for(int i = lastNonLeaf; i >= 0; i--)
    {
        // heapify from the last non-leaf
        heapify(arr, i, arr.size());
    }
}
void HeapSort(vector<int> &arr)
{
    // guard clause
    if(arr.size() <= 1) return;
    int n = arr.size();
    // start
    // build Max-Heap
    buildMaxHeap(arr);
    // push root to end
    // heapify 
    // keep pushing until the arr.size() shrink to 0
    while(n > 1)
    {
        swap(arr[0], arr[n-1]);
        n--;
        heapify(arr, 0, n);
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
    runTests(HeapSort);
}