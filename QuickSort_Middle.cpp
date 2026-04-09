

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// Quick Sort
void quickSort(vector<int> &arr, int left, int right)
{
    // guard clause
    if(left >= right) return;
    // find the middle point as the pivot
    // left side of the pivot includes smaller values / right side includes bigger values
    int pivot_middle = (left+right)/2;
    int i = left;
    int j = right;
    while(i < j)
    {
        while(arr[i] < arr[pivot_middle]) i++;
        while(arr[j] > arr[pivot_middle]) j--;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };
    //
    if(i < right) quickSort(arr, i, right);
    if(j > left) quickSort(arr, left, j);
    
}
// function overload
void quickSort(vector<int> &arr)
{
    if(!arr.empty())
    {
        quickSort(arr, 0, arr.size() - 1);
    }
}
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
    runTests(quickSort);
}