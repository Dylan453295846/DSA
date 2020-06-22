
#include <random>
#include<iostream>

template<typename T> bool Vector<T>::Empty() {
	if (_size < 1) return true;
	else return false;
}

template<typename T> T Vector<T>::operator[](Rank r) {
	if (0<= r < _size) return _elem[r];
	else std::cout << " Error: 元素访问出界\n";
}

template<typename T> int Vector<T>::Size() {
	return _size;
}
// 在[lo,hi)区间内从后向前查找
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi; // hi<lo即失败，否则hi即命中元素的秩
}

template<typename T> void Vector<T>::Insert(T const& e, Rank r) {
	// 先扩容
	Expand();
	for (int i = _size++; i > r; i--) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
}

// 倍增式扩容
template<typename T> void Vector<T>::Expand()
{
	if (_size < _capacity) return;
	/*else _capacity <<= 1;*/
	//为什么还要用新的向量复制旧的向量，释放原空间
	// 是因为如果加大容量，得到的可能不是连续的储存空间吗，还是出现野指针
	T* oldElem = _elem;  _elem = new T[_capacity <<= 1]; //容量加倍
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i]; //复制原向量内容
	delete[] oldElem;

}

// remove [lo, hi)
template<typename T> void Vector<T>::Remove(Rank lo, Rank hi) {
	int n = hi - lo;
	if (lo < hi) {
		while (n--) {
			_elem[lo++] = _elem[hi++];
		}
	}
	_size -= hi - lo;
	Shrink();
}

// 删除末尾元素
template<typename T> void Vector<T>::Pop() {
	Remove(_size - 1, _size);
}

// 容量收缩
template<typename T> void Vector<T>::Shrink() {
	if (_size * 2 < _capacity) _capacity >>= 2;
}

// 无序列表唯一化
template<typename T> void Vector<T>::Duplicate() {
	for(int i = 1; i < _size; i++) {
		if (find(_elem[i], 0, i) != -1) {
			Remove(i, i + 1);
		}
	}
}

template<typename T> Rank Vector<T>::Search(T const& e, Rank lo, Rank hi) {
	switch (0) {
	case 0: return binSearch(e, lo, hi); break;
	case 1: return FibSearch(e, lo, hi); break;
	}
}
// 有序列表唯一化
template<typename T> void Vector<T>::Uniquify() {
	int j = 0;
	for (Rank i = 0; i < _size; i++) {
		if (_elem[j] != _elem[i]) {
			_elem[++j] = _elem[i];
		}
	}
	Remove(j + 1, _size); // 成批删除
}

// 二分查找
template<typename T> Rank Vector<T>::binSearch(T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		int mi = (lo + hi) / 2;
		if (e < _elem[mi]) {
			hi = mi;
		}
		else {
			lo = mi+1;
		}
	}
	return lo-1;
}

// Fibonacci 查找
// 有错误，还是应该按照Fibonacci序列写，而不是黄金分割数字
template<typename T> Rank Vector<T>::FibSearch(T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		int mi = (int)((lo + hi) * 0.618);
		if (e < _elem[mi]) {
			hi = mi;
		}
		else {
			lo = mi + 1;
		}
	}
	return lo - 1;
}

template<typename T> void Vector<T>::CopyFromVector(Vector<T> v) {
	_capacity = v._capacity;
	_elem = new T[_capacity];
	for (int i = 0; i < v._size; i++) {
		_elem[i] = v._elem[i];
	}
	_size = v._size;
}

// 从数组中复制
template<typename T> void Vector<T>::CopyFromArray(T arr[], int len) {
	_capacity = 2 * len;
	_size = len;
	_elem = new T[_capacity];
	for (int i = 0; i < len; i++) {
		_elem[i] = arr[i];
	}
}

// 遍历
template<typename T> void Vector<T>::Traverse() {
	std::cout << "Size"<<_size<<": ";
	for (int i = 0; i < _size; i++) {
		std::cout << _elem[i] << " ";
	}
	std::cout << "\n";
}

template<typename T> void Vector<T>::Sort() {
	switch (2) {
	case 0: BubbleSort(); break;
	case 1: SelectionSort(); break;
	case 2: InsertionSort(); break;
	}
}

template<typename T> void Vector<T>::BubbleSort() {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j <_size-i ; j++) {
			if (_elem[j] < _elem[j - 1]) {
				std::swap(_elem[j], _elem[j - 1]);
			}
		}
	}
}

template<typename T> void Vector<T>::SelectionSort() {
	for (int i = 0; i < _size; i++) {
		int MaxRank = SelectMax(_elem, 0, _size - i);
		std::swap(_elem[MaxRank], _elem[_size - i - 1]);
	}
}

// max value in [lo,hi)
template<typename T> Rank Vector<T>::SelectMax(T *elem, int lo,int hi) {
	int MaxRank = lo;
	for (int i = lo+1; i < hi; i++) {
		if (elem[MaxRank] < elem[i]) {
			MaxRank = i;
		}
	}
	return MaxRank;
}

template<typename T> void Vector<T>::InsertionSort() {
	for (int i = 1; i < _size; i++) {
		for (int j = i; j > 0; j--) {
			if (_elem[j] < _elem[j-1]) {
				std::swap(_elem[j-1], _elem[j]);
			}
		}
	}
}
template<typename T> Vector<T>::~Vector() {
	Remove(0, _size);
	_size = 0;
	_capacity = 0;
}

// 判断是否有序
template<typename T> bool Vector<T>::IsOrdered() {
	for (int i = 1; i < _size; i++) {
		if (_elem[i] < _elem[i - 1]) {
			std::cout << "无序\n";
			return false;
		}
	}
	std::cout << "有序\n";
	return true;
}