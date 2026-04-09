#include <iostream>
#include <vector>
using namespace std;

// merge
template <typename T>
void merge(vector<T> &arr, int left, int mid, int right)
{
    vector<T> leftArray(arr.begin() + left, arr.begin() + mid + 1);
    vector<T> rightArray(arr.begin() + mid + 1, arr.begin() + right + 1);

    // 2 pointers
    size_t leftPtr = 0;
    size_t rightPtr = 0;

    while(leftPtr < leftArray.size() && rightPtr < rightArray.size())
    {
        if(leftArray[leftPtr] <= rightArray[rightPtr]) arr[left++] = leftArray[leftPtr++];
        else arr[left++] = rightArray[rightPtr++];
    }
    // remaining
    while(leftPtr < leftArray.size()) arr[left++] = leftArray[leftPtr++];
    while(rightPtr < rightArray.size()) arr[left++] = rightArray[rightPtr++];
}

// mergesort
template <typename T>
void mergeSort(vector<T> &arr)
{
    // guard clause
    if(arr.size() <= 1) return;
    
    // logic start here
    for(size_t width = 1; width < arr.size(); width *= 2)
    {
        for(size_t i = 0; i < arr.size(); i = i + width*2)
        {
            size_t left = i;
            size_t mid = min(left + width - 1, arr.size() - 1);
            size_t right = min(left + 2*width - 1, arr.size() - 1);

            if(mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
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
    runTests(mergeSort);
}