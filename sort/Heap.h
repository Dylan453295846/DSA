#ifndef _HEAP_H_
#define _HEAP_H_

#define elemType int
class Heap
{
public:
	Heap(elemType array[],int array_len);
	~Heap();

private:
	elemType arr[5000];
	int arr_len;
	int heap_size;
	
public:
	void Build_max_heap();//build a heap

	void HeapSort();//heapSort

	//priority queue
	void Insert(elemType k);
	elemType Maximum();
	void Extract_max();
	void Increase_key(int i,elemType k);

private:
	void Max_heapify(int i);//keep the max-heap property
	int Left(int i);
	int Right(int i);
	int Parent(int i);
	void Swap(elemType* a, elemType* b);
};

#endif // _HEAP_
