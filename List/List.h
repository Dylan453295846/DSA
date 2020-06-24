#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
#include "ListNode.h"

template<typename T> class List {
private:
	//规模，头尾哨兵
	int _size;
	Posi(T) header;
	Posi(T) trailer;
	
public:
	List();
	List(List<T> const& L);//整体复制链表
	List(List<T> const& L, Rank r, int n);//复制列表中自第r项起n项
	List(Posi(T) p, int n);//复制自位置p起的n项
	~List();
	//只读访问接口
	int Size();
	Posi(T) First();
	Posi(T) Last();
	bool Empty();//判空
	bool Valid(Posi(T) p);//是否合法
	Posi(T) find(T const& e, int n, Posi(T) p);
	Posi(T) Search(T const& e, int n, Posi(T) p);

	//可写访问接口
	void Initiallize(T arr[],int len);

	void InsertBefore(Posi(T) p, T const& e);
	void InsertAfter(Posi(T) p, T const& e);
	void InsertAsFirst(T const& e);
	void InsertAsLast(T const& e);

	T Remove(Posi(T) p);
	void Dequplicate();
	void Uniquify();

	void Sort(Posi(T) p, int n);
	void SelectionSort(Posi(T) p,int n);
	void InsertionSort(Posi(T) p, int n);
	
	//遍历
	void Traverse();

	template<typename VST>//操作器
	void traverse(VST& visit);//遍历，依次实施visit操作（函数对象，可全局性修改）

	template <typename T> struct Increase //函数对象：递增一个T类对象
	{
		virtual void operator() (T& e) {//一个函数对象，即一个重载了括号操作符“（）”的对象。
			e++; 
		}
	}; //假设T可直接递增或已重载++

	//统一递增列表中的各元素,以Increase<T>()为基本操作进行遍历
	void increase(List<T>& L);

protected:
	Posi(T) SelectMax(Posi(T) p, int n);
	void Init();//初始化，主要是创建头尾哨兵
	void CopyNodes(Posi(T) p, int n);//复制列表中自位置p起的n项

};
#include"List.inl"
#endif // !_LIST_H_
