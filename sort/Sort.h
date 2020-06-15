#ifndef _SORT_H_
#define _SORT_H_

#define elemType int

//include different methods for sorting of array
class Sort
{
public:
	Sort(elemType array[],int array_len);
	~Sort();

private:
	elemType arr[5000];
	int arr_len;
	
public:
	void Insertion_sort();
	void Bubble_sort();
	void Selction_sort();
	void Merging_sort();
	void Quick_sort();

private:
	void Swap(elemType* a, elemType* b);

	void Merge(int p, int q, int r);
	void MergSort(int p, int r);

	void QuickSort(int p, int r);
	int Partition(int p, int r);
	int Randomized_Partition(int p, int r);
};

#endif // !_SORT_H_
