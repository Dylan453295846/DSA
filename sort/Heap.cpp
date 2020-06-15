#include "Heap.h"
#include<iostream>

#include<assert.h>

Heap::Heap(elemType array[], int array_len)
{
	//init a heap
	for (int i = 0; i < array_len; i++)
	{
		arr[i] = array[i];
	}
	arr_len = array_len;
	
	Build_max_heap();
}

Heap::~Heap()
{
	//do nothing
	//delete[] arr;
}

void Heap::Max_heapify(int i)
{
	int le = Left(i);
	int ri = Right(i);
	int largest;
	if (le < heap_size && arr[i] < arr[le]) largest = le;
	else largest = i;
	if (ri < heap_size && arr[largest] < arr[ri])
	{
		largest = ri;
	}
	if (largest != i)
	{
		Swap(&arr[i], &arr[largest]);
		Max_heapify(largest);
	}
	
}
void Heap::Build_max_heap()
{
	heap_size = arr_len;
	for (int i = arr_len / 2; i >= 0; i--)//
	{
		Max_heapify(i);
	}
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
}

void Heap::HeapSort()
{
	//get the root parent node and keep the max-heap property
	for (int i = arr_len - 1; i >= 0; i--)
	{
		Swap(&arr[i], &arr[0]);
		heap_size--;
		Max_heapify(0);
	}
	std::cout << "Heap Sort: "<< std::endl;
	//for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
}
//priority queue
elemType Heap::Maximum()//distinguish between HeapSort and Priority queue
{
	return arr[0];
}
void Heap::Extract_max()
{
	//get the root parent node ,swap the start and the end, 
	//decrease the heap size, keep the max-heap property
	if(heap_size < 1) std::cout<<"error: heap underflow"<<std::endl;
	elemType max = arr[0];
	arr[0] = arr[heap_size-1];
	heap_size--;
	Max_heapify(0);
	for (int i = 0; i < heap_size; i++) std::cout << arr[i] << " ";
}

void Heap::Increase_key(int i, elemType k)//increase to k, i.e. arr[i]=k
{
	std::cout << "Increase key at pos " << i << "to" << k << ": ";
	if (arr[i] > k)
	{
		std::cout << "error: new key is smaller than current key" << std::endl;
		return;
	}
	arr[i] = k;
	while (i >= 0 && arr[Parent(i)] < arr[i])
	{
		Swap(&arr[i], &arr[Parent(i)]);
		i = Parent(i);
	}
	for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
}

void Heap::Insert(elemType k)
{
	std::cout << "Insert (" << k << "): ";
	heap_size++;
	arr[heap_size] = -INFINITY;
	Increase_key(heap_size - 1, k);
	for (int i = 0; i < arr_len; i++) std::cout << arr[i] << " ";
}

//left child node
int Heap::Left(int i)
{
	return 2*i;
}
//right child node
int Heap::Right(int i)
{
	return 2 * i +1;
}
//parent node
int Heap::Parent(int i)
{
	return i / 2;
}

void Heap::Swap(elemType* a, elemType* b)
{
	elemType t;
	t = *a;
	*a = *b;
	*b=t;
}