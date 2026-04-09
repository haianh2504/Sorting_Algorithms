#include <iostream>
#include <vector>
using namespace std;

// merge
void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftArray(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArray(arr.begin() + mid + 1, arr.begin() + right + 1);

    // 2 pointers
    int leftPtr = 0;
    int rightPtr = 0;

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
void mergeSort(vector<int> &arr)
{
    // guard clause
    if(arr.size() <= 1) return;
    //
    for(int currSize = 1; currSize < arr.size(); currSize *= 2)
    {
        for(int left_Start = 0; left_Start < arr.size(); left_Start += 2*currSize)
        {
            int right_end = left_Start + 2*currSize - 1;
            int mid = left_Start + (right_end - left_Start)/2;
            merge(arr, left_Start, mid, right_end);
        }
    }
}