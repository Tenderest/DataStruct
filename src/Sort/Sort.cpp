#include "../../lib/Sort/Sort.hpp"
int main(void)
{
    using namespace std;
    int arr[] = {-1, 53, 5, 28, 34, 11, 56, 82, 9, 10, 7};
    int arr2[6] = {-1, 5, 23, 34, 11};
    int len2 = 5;
    // 数组 0 不存放数据，用来暂存变量
    int len = sizeof(arr) / sizeof(int);
    // InsertSort(arr, len);
    // HalfInsertSort(arr, len); // problem
    // BubbleSort(arr, len);

    /* cout << Partition(arr, 0, len - 1) << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << Partition(arr, 0, len - 1) << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    /* QuickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    /* SelectSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    HeapSort(arr, len);
    //BuildMaxHeap(arr, len);
    cout << "HeapSort: " << endl;
    for (int i = 1; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    BuildMaxHeap(arr2, len2);
    cout << "BuildMaxHeap len2:" << endl;
    for (int i = 1; i < len2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    // insert node
    arr2[5] = 44;
    len2++;
    AdjustUp(arr2, 5);
    cout << "Insert arr2[5] = 44 and AdjustUp len2:" << endl;
    for (int i = 1; i < len2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    HeapSort(arr2, len2);
    cout << "HeapSort len2:" << endl;
    for (int i = 1; i < len2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
