#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// selection Sort
void selectionSort(vector<int> &arr)
{
    // guard clause
    if(arr.size() <= 1) return;

    // start
    auto n = arr.size();
    // find the minimum -> put it to the array -> using 2 pointers
    for(auto i = 0; i < n; i++)
    {
        auto smallestIndex = i;
        for(auto j = i + 1; j < n; j++)
        {
            // find the smallest
            if(arr[j] < arr[smallestIndex]) smallestIndex = j;
        };
        // smallest Index now holding the smallest 
        if(smallestIndex != i)
        {
            swap(arr[i], arr[smallestIndex]);
        }
    };
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
    runTests(selectionSort);
}