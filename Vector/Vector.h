#ifndef _VECTOR_H_
#define _VECTOR_H_

#define DEFAULT_CAPACITY 3 // Ĭ������
#define  Rank int // ��
template<class T>
class Vector {
private:
	int _size; // ��ģ
	int _capacity; // ����
	T* _elem; // ����

public:
	Vector() :_size(0), _capacity(DEFAULT_CAPACITY), _elem(new T [_capacity]){}
	~Vector();
public:
	// ��������
	// ��ȡ
	bool Empty(); //�ж��Ƿ�Ϊ��
	T operator[](Rank r);// ѭ�ȷ���
	Rank find(T const& e, Rank lo, Rank hi);
	int Size();
	bool IsOrdered();

	// д��
	void Insert(T const& e, Rank r);
	void CopyFromVector(Vector<T> v);
	void CopyFromArray(T arr[],int len);

	void Expand();// ����
	void Remove(Rank lo, Rank hi);//����ɾ��
	void Pop(); // ��Ԫ��ɾ��
	void Shrink(); // ��������
	
	void Duplicate(); // Ψһ����ȥ��
	void Traverse(); //����

	// ��������
	void Sort();
	// ��ȡ
	Rank Search(T const& e, Rank lo, Rank hi); // ���ز�����e�����Ԫ�� ��λ��
	
	// д��
	void Uniquify(); // Ψһ��

protected:
	Rank binSearch(T const& e, Rank lo, Rank hi);
	Rank FibSearch(T const& e, Rank lo, Rank hi);
	void BubbleSort();
	void SelectionSort();
	Rank SelectMax(T* elem, int lo, int hi);
	void InsertionSort();
	void QuickSort();
	void HeapSort();
	void ShellSort();
};
#include"Vector.inl"
//���� `template` �࣬��Ҫ�� `*.cpp` ��ʵ�ִ������ `*.h` �У����ܱ���ͨ��
#endif // !_VECTOR_H_
