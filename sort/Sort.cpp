#include "Sort.h"
#include <iostream>

Sort::Sort(elemType array[], int array_len)
{
	arr_len = array_len;
	for (int i = 0; i < array_len; i++) arr[i] = array[i];
}

Sort::~Sort()
{
	//delete[] arr;
}

void Sort::Insertion_sort()
{
	std::cout << "Insertion-sort-n^2" << std::endl;
	for (int i = 1; i < arr_len; i++)
	{
		//regard arr[0] as an array in order,
		//insert a new element in the ordered part of array
		for (int j = i; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				Swap(&arr[j - 1], &arr[j]);
			}
		}
	}
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}
void Sort::Bubble_sort()
{
	std::cout << "Bubble-sort-n^2" << std::endl;
	for (int i = 0; i < arr_len-1; i++)
	{
		//repeat swapping the neighbor element which is out of order 
		for (int j = arr_len - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(&arr[j], &arr[j - 1]);
			}
		}
	}
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void Sort::Selction_sort()
{
	std::cout << "Selection-sort-n^2" << std::endl;
	for (int i = 0; i < arr_len-1; i++)
	{
		//find the minimum element at arr[i]
		for (int j = i + 1; j < arr_len; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(&arr[i], &arr[j]);
			}
		}
	}
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}
void Sort::Merging_sort()
{
	std::cout << "Merging-sort-nlgn" << std::endl;
	MergSort(0, arr_len - 1);
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void Sort::MergSort(int p, int r)
{
	if (p >= r)return;
	int q = (p + r) / 2;
	//recursive
	MergSort(p, q);
	MergSort(q + 1, r);
	Merge(p, q, r);
}
//merge two ordered subarrays in arr[]
void Sort::Merge(int p, int q, int r)
{
	//method 1:
	//int n1 = q - p + 1;
	//int n2 = r - q;
	//elemType* L = new elemType[n1 + 1];
	//elemType* R = new elemType[n2 + 1];
	//for (int i = 0; i < n1; i++) L[i] = arr[p+i];
	//for (int i = 0; i < n2; i++) R[i] = arr[q+i+1];
	//L[n1] = INFINITY;
	//R[n2] = INFINITY;
	//int i = 0, j = 0;
	//for (int k = p; k <= r; k++)
	//{
	//	if (L[i] < R[j]) arr[k] = L[i++];
	//	else arr[k] = R[j++];
	//}
	//delete[] L;
	//delete[] R;
	
	//method 2:
	int lo = p, mi = q, hi = r;
	int lb = mi - lo + 1;
	int lc = hi - mi;
	elemType *B = new elemType[lb], *C = new elemType[lc];//subarray
	for (int i = 0; i < lb; i++) B[i] = arr[lo + i];
	for (int i = 0; i < lc; i++) C[i] = arr[mi + i + 1];
	for (int i = lo, j = 0, k = 0; (j < lb) || (k < lc); )
	{
		if (j < lb && (k >= lc || B[j] <= C[k]))arr[i++] = B[j++];
		if (k < lc && (j >= lb || C[k] < B[j])) arr[i++] = C[k++];
	}
	delete[] B;
	delete[] C;
}

void Sort::Swap(elemType* a, elemType* b)
{
	elemType t;
	t = *a;
	*a = *b;
	*b = t;
}

void Sort::Quick_sort()
{
	std::cout << "Quick-sort-nlgn" << std::endl;
	QuickSort(0,arr_len-1);
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}
void Sort::QuickSort(int p, int r)
{
	if (p < r)
	{
		//recursive
		//int q = Partition(p, r);
		int q=Randomized_Partition(p, r);
		QuickSort(p, q - 1);
		QuickSort(q + 1, r);
	}
}

int Sort::Partition(int p, int r)
{
	//part an array in two partition in origin array,keft and right
	elemType x = arr[r];//pivot element
	int i = p - 1;
	for (int j = p ; j < r; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[r]);
	return i + 1;
}

int Sort::Randomized_Partition(int p, int r)
{
	//randomly select a pivot element in array
	int i = p + (1 - rand() % 10 * 0.1) * (r - p);
	Swap(&arr[i], &arr[r]);
	return Partition(p, r);
}