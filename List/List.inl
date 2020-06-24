#include <random>
#include <iostream>

//初始化，主要是创建头尾哨兵
template<typename T> void List<T>::Init() {
	_size = 0;
	//要注意顺序，先new一个新的列表节点，再设置前驱后继
	header = new ListNode<T>;//不需要创建参数，后面手动设置
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
}

//复制列表中自位置p起的n项
template<typename T> void List<T>::CopyNodes(Posi(T) p, int n) {
	//首先要创建头尾哨兵
	Init();
	while (n--) {
		InsertAsLast(p->data);//将起自p的n项依次作为末节点插入
		p = p->succ;
	}
}

template<typename T> List<T>::List() {
	Init();
}
//整体复制链表
template<typename T> List<T>::List(List<T> const& L) {
	CopyNodes(L.header->succ, L._size);
}
//复制列表中自第r项起n项
template<typename T> List<T>::List(List<T> const& L, Rank r, int n) {
	Posi(T) p = L.header->succ;
	while (r--) p = p->succ;
	CopyNodes(p, n);
}
//复制自位置p起的n项
template<typename T> List<T>::List(Posi(T) p, int n) {
	CopyNodes(p, n);
}

template<typename T> List<T>::~List() {
	while (_size > 0) Remove(header->succ);
	//T r = Remove(header);//会出现错误，结束返回值不为0
	//r = Remove(trailer);//因为在remove中出现header的前驱
	delete header;
	delete trailer;
}
//判空
template<typename T> bool List<T>::Empty() {
	//if (header->succ) return true;
	//else return false;
	return _size <= 0;
}

//判断是否合法
template<typename T> bool List<T>::Valid(Posi(T) p) {
	return p && (p != header) && (p != trailer);//将头、尾节点等同于NULL
}

template<typename T> int List<T>::Size() {
	return _size;
}

//返回首元素
template<typename T> Posi(T) List<T>::First() {
	return header->succ;
}
//返回末元素
template<typename T> Posi(T) List<T>::Last() {
	return trailer->pred;
}

template<typename T> void List<T>::Initiallize(T arr[],int len){
	Posi(T) p = header;
	for (int i = 0; i < len; i++) {
		p->InsertAsSucc(arr[i]);
	}
}

// 在节点p的n个真前驱中查找
template<typename T> Posi(T) List<T>::find(T const& e, int n, Posi(T) p) {
	while (n--) {
		p = p->pred;
		if (p->data == e) return p;
	}
	return NULL;

}
//前插入算法
template<typename T> void List<T>::InsertBefore(Posi(T) p, T const& e) {
	p->InsertAsPred(e);
	_size++;
}

template<typename T> void List<T>::InsertAfter(Posi(T) p, T const& e) {
	p->InsertAsSucc(e);
	_size++;
}

// header-first----last-trailer
//在首插入
template<typename T> void List<T>::InsertAsFirst(T const& e) {
	header->succ->InsertAsPred(e);
	_size++;
}

//在尾插入
template<typename T> void List<T>::InsertAsLast(T const& e) {
	trailer->InsertAsPred(e);
	_size++;
}

template<typename T> T List<T>::Remove(Posi(T) p) {
	T e = p->data;
	((p->pred)->succ) = (p->succ);//p前驱的后继为p的后继
	((p->succ)->pred) = (p->pred);//p后继的前驱为p的前驱
	_size--;
	return e;
	
}
template<typename T> void List<T>::Dequplicate() {
	Posi(T) p = header->succ->succ;
	for (int i = 1; i < _size; i++) {
		if (find(p->data, i, p)) Remove(p);
		p = p->succ;
	}
}

template<typename T> void List<T>::Uniquify() {
	Posi(T) p = header->succ;
	while (p!=trailer) {
		if (p->data == p->succ->data) Remove(p->succ);
		p = p->succ;
	}
}
//在p的n个真前驱中查找
template<typename T> Posi(T) List<T>::Search(T const& e, int n, Posi(T) p) {
	while (n > -1) {
		p = p->pred;
		if (p->data <= e) break;
		n--;
	}
	return p;
}

template<typename T> void List<T>::Sort(Posi(T) p, int n) {
	switch (rand()%2){
	case 0: SelectionSort(p, n); break;
	case 1: InsertionSort(p, n); break;
	}
}
//始于p的n个元素排序
template<typename T> void List<T>::SelectionSort(Posi(T) p, int n) {
	//从未排序区间找到最大者，并移至有序区间最前端

	Posi(T) tail = p;
	Posi(T) head = p->pred;
	for (int i = 0; i < n; i++) tail = tail->succ;//确定排序区间(head,tail)
	while(1 < n){
		Posi(T) MaxPosi = SelectMax(p, n--);
		InsertBefore(tail, Remove(MaxPosi));
		tail = tail->pred; //前移
	}
}
//始于p的n个元素中最大元素
template<typename T> Posi(T) List<T>::SelectMax(Posi(T) p, int n) {
	Posi(T) MaxPosi = p;
	while(n > 1) {
		p = p->succ;
		if (MaxPosi->data < p->data) MaxPosi = p;
		n--;
	}
	return MaxPosi;
}
//始于p的n个元素排序
template<typename T> void List<T>::InsertionSort(Posi(T) p, int n) {
	for(int i = 0; i < n; i++){
		InsertAfter(Search(p->data,i, p), p->data);
		p = p->succ;
		Remove(p->pred);
	}
}

template<typename T> void List<T>::Traverse() {
	Posi(T) p = header;
	for (int i = 0; i < _size; i++) {
		p = p->succ;
		std::cout << p->data << " ";
	}
	std::cout <<"\n";
}

//遍历，依次实施visit操作（函数对象，可全局性修改）
template<typename T> template<typename VST> 
void List<T>::traverse(VST& visit) {
	for (Posi(T) p = header->succ; p != trailer; p = p->succ) {
		visit(p->data);
	}
}
//以Increase<T>()为基本操作进行遍历
template <typename T> void List<T>::increase(List<T>& L) //统一递增列表中的各元素
{
	L.traverse(Increase<T>());
} 
