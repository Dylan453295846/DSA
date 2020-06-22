#ifndef _VECTOR_H_
#define _VECTOR_H_

#define DEFAULT_CAPACITY 3 // 默认容量
#define  Rank int // 秩
template<class T>
class Vector {
private:
	int _size; // 规模
	int _capacity; // 容量
	T* _elem; // 数据

public:
	Vector() :_size(0), _capacity(DEFAULT_CAPACITY), _elem(new T [_capacity]){}
	~Vector();
public:
	// 无序向量
	// 读取
	bool Empty(); //判断是否为空
	T operator[](Rank r);// 循秩访问
	Rank find(T const& e, Rank lo, Rank hi);
	int Size();
	bool IsOrdered();

	// 写入
	void Insert(T const& e, Rank r);
	void CopyFromVector(Vector<T> v);
	void CopyFromArray(T arr[],int len);

	void Expand();// 扩容
	void Remove(Rank lo, Rank hi);//区间删除
	void Pop(); // 单元素删除
	void Shrink(); // 区间收缩
	
	void Duplicate(); // 唯一化，去重
	void Traverse(); //遍历

	// 有序向量
	void Sort();
	// 读取
	Rank Search(T const& e, Rank lo, Rank hi); // 返回不大于e的最大元素 的位置
	
	// 写入
	void Uniquify(); // 唯一化

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
//对于 `template` 类，需要将 `*.cpp` 的实现代码放在 `*.h` 中，才能编译通过
#endif // !_VECTOR_H_
