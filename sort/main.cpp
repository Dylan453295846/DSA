#include<iostream>
#include <Windows.h>
#include <vector>
#include "Heap.h"
#include "Sort.h"

int main()
{
	std::vector<elemType *> arr;//important!
	
	arr.resize(7);
	int arr_len;
	std::cin >> arr_len;

	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = new elemType[5000];//important!
		for (int j = 0; j < arr_len; j++)
			arr[i][j]= rand() % 5000;
	}
	
	std::vector<Sort> s;
	for (int i = 0; i <5; i++) s.push_back(Sort(arr[i], arr_len));
	std::vector<DWORD> time;

	time.push_back(GetTickCount());
	s[0].Selction_sort();
	time.push_back(GetTickCount());

	s[1].Bubble_sort();
	time.push_back(GetTickCount());

	s[2].Insertion_sort();
	time.push_back(GetTickCount() );

	s[3].Merging_sort();
	time.push_back(GetTickCount());

	s[4].Quick_sort();
	time.push_back(GetTickCount());

	Heap h(arr[5], arr_len);
	h.HeapSort();
	time.push_back(GetTickCount());

	Heap h2(arr[6], arr_len);
	elemType t= h2.Maximum();
	time.push_back(GetTickCount());


	std::vector<std::string> str = {"Selction_sort","Bubble_sort", "Insertion_sort",
		"Merging_sort","quick_sort", "HeapSort","Heap_Maximum" };

	for(int i=0;i<time.size()-1;i++) std::cout <<str[i]<<" "<< time[i+1]-time[i] << std::endl;

	std::cout<<"Ending"<<std::endl;
	for (int i = 0; i < arr.size(); i++)delete[] arr[i];

	//these sort algorithms are compare algorithm, expect these, 
	//there are counting_sort, radix_sort£¬bucket_sort£¬but some requirements for data
	return 0;
}
