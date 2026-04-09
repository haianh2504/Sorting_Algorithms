#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
class quickSort_Middle
{
    private:
    quickSort_Middle(){};
    public:
    //
    static void quickSort(vector<T> &arr, size_t left, size_t right)
    {
        // guard clause
        if(left >= right) return;
        
        //
        T pivot = arr[left+(right-left)/2];
        // 2 pointers aside
        auto i = left;
        auto j = right;
        while(i < j)
        {
            while(arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        };
        if(left < j) quicksort(arr, left, j);
        if(right > i) quicksort(arr, i, right);
    }

    // function overload
    static void quickSort(vector<int> &arr)
    {
    if(!arr.empty())
    {
        quickSort(arr, 0, arr.size() - 1);
    }
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
    runTests(quickSort_Middle<int>::quickSort);
}