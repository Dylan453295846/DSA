#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
#include "ListNode.h"

template<typename T> class List {
private:
	//��ģ��ͷβ�ڱ�
	int _size;
	Posi(T) header;
	Posi(T) trailer;
	
public:
	List();
	List(List<T> const& L);//���帴������
	List(List<T> const& L, Rank r, int n);//�����б����Ե�r����n��
	List(Posi(T) p, int n);//������λ��p���n��
	~List();
	//ֻ�����ʽӿ�
	int Size();
	Posi(T) First();
	Posi(T) Last();
	bool Empty();//�п�
	bool Valid(Posi(T) p);//�Ƿ�Ϸ�
	Posi(T) find(T const& e, int n, Posi(T) p);
	Posi(T) Search(T const& e, int n, Posi(T) p);

	//��д���ʽӿ�
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
	
	//����
	void Traverse();

	template<typename VST>//������
	void traverse(VST& visit);//����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�

	template <typename T> struct Increase //�������󣺵���һ��T�����
	{
		virtual void operator() (T& e) {//һ���������󣬼�һ�����������Ų��������������Ķ���
			e++; 
		}
	}; //����T��ֱ�ӵ�����������++

	//ͳһ�����б��еĸ�Ԫ��,��Increase<T>()Ϊ�����������б���
	void increase(List<T>& L);

protected:
	Posi(T) SelectMax(Posi(T) p, int n);
	void Init();//��ʼ������Ҫ�Ǵ���ͷβ�ڱ�
	void CopyNodes(Posi(T) p, int n);//�����б�����λ��p���n��

};
#include"List.inl"
#endif // !_LIST_H_
