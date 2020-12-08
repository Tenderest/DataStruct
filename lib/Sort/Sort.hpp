#include "../PublicLib.hpp"

// 插入排序
// 直接插入排序
// void InsertSort(ElemType A[], int n)
void InsertSort(int A[], int n)
{
    /**
     * 数组下标为 0 的不存储元素，作为中间变量，所以空间复杂度为 O(1)
     * 时间复杂度 最好 O(n) 平均 O(n^2) 最差 O(n^2)
     * 算法是稳定的，适用于顺序存储和链式存储
     **/
    int i, j;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        for (j = i - 1; A[0] < A[j]; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = A[0];
    }
}

// 折半插入排序
// void HalfInsertSort(ElemType A[], int n)
void HalfInsertSort(int A[], int n)
{
    /**
     * 折半查找：又称二分查找，仅适用于有序的顺序表，所以元素只能存放在数组当中
     * 数组下标为 0 的不存储元素，作为中间变量，所以空间复杂度为 O(1)
     * 时间复杂度 最好 O(n) 平均 O(n^2) 最差 O(n^2)
     * 算法是稳定的，并且只适用于顺序存储!!!
     **/
    int i, j;
    int low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            if (A[mid] > A[0])
            {
                high =  mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i -1; (high + 1) < j; j--)
        {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}

void  swapValue(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}


// 交换排序
// 冒泡排序
void BubbleSort(int A[], int n)
{
    /**
     * 冒泡排序：
     * 假设待排序表长为 n，从后往前（或者从前往后）两两比较相邻元素的值，
     * 若为逆序（后 > 前），则交换它们直到序列比较结束
     * 时间复杂度 最好 O(n) 平均 O(n^2) 最差 O(n^2)
     * 空间复杂度为 O(1)
     * 算法是稳定的，适用于顺序存储和链式存储
     **/
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        // for (int j = i; j < n - i; j++)
        for (int j = n -1; j > i; j--)
        {
            if (A[j -1] > A[j])
            {
                swapValue(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false) return ;
    }
}

// 快速排序
/**
 * 基本思想：
 * 在待排序表 L[1..n] 中任y一个元素 pivot 作为基准，通过一趟排序将待排序划分为具有如下特点的两部分
 * 左边的元素都小于(<) pivot ，pivot (<)都小于右边的元素
 * 一次划分会将一个元素 pivot 放置到它最终的位置上
 * 时间复杂度 O(high-low+1)  最好 O(nlog2n) 平均 O(nlog2n) 最差 O(n^2)
 * 空间复杂度为 O(log2n) 最坏 O(n)
 * 算法是 不稳定的，适用于顺序存储和(链式存储)
 * Partition
 * 初始化标记 low 为划分部分的第一个元素的位置，high 为最后一个元素的位置，然后不断地移动两标记并交换元素
 * 1️⃣ high 向前移动找到第一个比 pivot 小的元素
 * 2️⃣ low 向后移动找到第一个比 pivot 大的元素
 * 3️⃣ 交换当前两个位置的元素
 * 4️⃣ 继续移动标记，执行1️⃣ 2️⃣ 3️⃣ 的过程，直到 low 大于等于（>=） high 为止。
 **/
// int Partition(ElemType A[], int low, int high)
int Partition(int A[], int low, int high)
{
    // 返回值 int 是最后划分元素的位置
    // ElemType pivot = A[low];
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        // while (low < high && pivot <= A[high])
            high --;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low ++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

// void QuickSort(ElemType A[], int low, int high)
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}


// 选择排序
/**
 * 基本思想：
 * 每一趟在后面 n - i + 1 (i = 1, 2, 3,..., n - 1) 个待排y元素中选取关键字最小的元素，
 * 作为有序子序列的第 i 个元素，直到 n - 1 趟做完，待排序元素只剩下 1 个。
 * 一趟排序会将一个元素放置在最终的位置上
 **/
// 直接选择排序
/**
 * 时间复杂度与初始序列无关
 * 时间复杂度 最好 O(n^2) 平均 O(n^2) 最差 O(n^2)
 * 空间复杂度为 O(1)
 * 算法是 不稳定的，适用于顺序存储和(链式存储)
 **/
// void SelectSort(ElemType A[], int n)
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
            std::cout << "swap" << std::endl;
        }
        if (min != i)
            swapValue(A[i], A[min]);
    }
}

// 堆排序
/**
 * 数组下标为 0 的不存储元素，作为中间变量
 * 堆的初始化：（大根堆举例，小根堆只需要调一下符号就可以了）
 *  对所有具有双亲结点含义编号从大到小（[n/2] ~ 1）做出如下调整：
 *  1️⃣ 若孩子结全部小于（<）双亲结点，则该结点的调整结束
 *  2️⃣ 若存在孩子结点大于（>）双亲结点，则将最大的孩子结点与双亲结点交换，
 *      并对该孩子结点进行 1️⃣ 、2️⃣ 直到出现 1️⃣ 或者到叶结点为止
 * 
 * 时间复杂度 最好 O(n^2) 平均 O(n log2n) 最差 O(n^2)
 * 空间复杂度为 O(1)
 * 算法是 不稳定的，适用于顺序存储和(链式存储)
 **/
// void AdjustDown(ElemType A[], int k, int len)
void AdjustDown(int A[], int k, int len)
{
    // 大根堆的向下调整
    // 数组下标为 0 的不存储元素，作为中间变量
    A[0] = A[k];
    for (int i = 2*k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])
        {
            i ++;
        }
        if (A[0] >= A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

/**
 * 堆的插入
 * 将新结点放置在末端然后进行向上调整
 **/
// void AdjustUp(ElemType A[], int len)
// k 是最后那个结点，也就是长度 len
void AdjustUp(int A[], int k)
{
    A[0] = A[k];
    int i = k/2;
    while (i > 0 && A[i] < A[0])
    {
        A[k] = A[i];
        k = i;
        i = k/2;
    }
    A[k] = A[0];
}

/**
 * 建立一个大根堆，时间复杂度 O(n)
 **/
// void BuildMaxHeap(ElemType A[], int len)
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        AdjustDown(A, i, len);
    }
}

// 不断的输出堆顶元素，并向下调整
// void HeapSort(ElemType A[], int n)
void HeapSort(int A[], int n)
{
    BuildMaxHeap(A, n);
    for (int i = n; i > 1; i--)
    {
        swapValue(A[i], A[1]);
        AdjustDown(A, 1, i - 1);
    }
}
