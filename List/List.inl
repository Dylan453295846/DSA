#include <random>
#include <iostream>

//��ʼ������Ҫ�Ǵ���ͷβ�ڱ�
template<typename T> void List<T>::Init() {
	_size = 0;
	//Ҫע��˳����newһ���µ��б�ڵ㣬������ǰ�����
	header = new ListNode<T>;//����Ҫ���������������ֶ�����
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
}

//�����б�����λ��p���n��
template<typename T> void List<T>::CopyNodes(Posi(T) p, int n) {
	//����Ҫ����ͷβ�ڱ�
	Init();
	while (n--) {
		InsertAsLast(p->data);//������p��n��������Ϊĩ�ڵ����
		p = p->succ;
	}
}

template<typename T> List<T>::List() {
	Init();
}
//���帴������
template<typename T> List<T>::List(List<T> const& L) {
	CopyNodes(L.header->succ, L._size);
}
//�����б����Ե�r����n��
template<typename T> List<T>::List(List<T> const& L, Rank r, int n) {
	Posi(T) p = L.header->succ;
	while (r--) p = p->succ;
	CopyNodes(p, n);
}
//������λ��p���n��
template<typename T> List<T>::List(Posi(T) p, int n) {
	CopyNodes(p, n);
}

template<typename T> List<T>::~List() {
	while (_size > 0) Remove(header->succ);
	//T r = Remove(header);//����ִ��󣬽�������ֵ��Ϊ0
	//r = Remove(trailer);//��Ϊ��remove�г���header��ǰ��
	delete header;
	delete trailer;
}
//�п�
template<typename T> bool List<T>::Empty() {
	//if (header->succ) return true;
	//else return false;
	return _size <= 0;
}

//�ж��Ƿ�Ϸ�
template<typename T> bool List<T>::Valid(Posi(T) p) {
	return p && (p != header) && (p != trailer);//��ͷ��β�ڵ��ͬ��NULL
}

template<typename T> int List<T>::Size() {
	return _size;
}

//������Ԫ��
template<typename T> Posi(T) List<T>::First() {
	return header->succ;
}
//����ĩԪ��
template<typename T> Posi(T) List<T>::Last() {
	return trailer->pred;
}

template<typename T> void List<T>::Initiallize(T arr[],int len){
	Posi(T) p = header;
	for (int i = 0; i < len; i++) {
		p->InsertAsSucc(arr[i]);
	}
}

// �ڽڵ�p��n����ǰ���в���
template<typename T> Posi(T) List<T>::find(T const& e, int n, Posi(T) p) {
	while (n--) {
		p = p->pred;
		if (p->data == e) return p;
	}
	return NULL;

}
//ǰ�����㷨
template<typename T> void List<T>::InsertBefore(Posi(T) p, T const& e) {
	p->InsertAsPred(e);
	_size++;
}

template<typename T> void List<T>::InsertAfter(Posi(T) p, T const& e) {
	p->InsertAsSucc(e);
	_size++;
}

// header-first----last-trailer
//���ײ���
template<typename T> void List<T>::InsertAsFirst(T const& e) {
	header->succ->InsertAsPred(e);
	_size++;
}

//��β����
template<typename T> void List<T>::InsertAsLast(T const& e) {
	trailer->InsertAsPred(e);
	_size++;
}

template<typename T> T List<T>::Remove(Posi(T) p) {
	T e = p->data;
	((p->pred)->succ) = (p->succ);//pǰ���ĺ��Ϊp�ĺ��
	((p->succ)->pred) = (p->pred);//p��̵�ǰ��Ϊp��ǰ��
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
//��p��n����ǰ���в���
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
//ʼ��p��n��Ԫ������
template<typename T> void List<T>::SelectionSort(Posi(T) p, int n) {
	//��δ���������ҵ�����ߣ�����������������ǰ��

	Posi(T) tail = p;
	Posi(T) head = p->pred;
	for (int i = 0; i < n; i++) tail = tail->succ;//ȷ����������(head,tail)
	while(1 < n){
		Posi(T) MaxPosi = SelectMax(p, n--);
		InsertBefore(tail, Remove(MaxPosi));
		tail = tail->pred; //ǰ��
	}
}
//ʼ��p��n��Ԫ�������Ԫ��
template<typename T> Posi(T) List<T>::SelectMax(Posi(T) p, int n) {
	Posi(T) MaxPosi = p;
	while(n > 1) {
		p = p->succ;
		if (MaxPosi->data < p->data) MaxPosi = p;
		n--;
	}
	return MaxPosi;
}
//ʼ��p��n��Ԫ������
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

//����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�
template<typename T> template<typename VST> 
void List<T>::traverse(VST& visit) {
	for (Posi(T) p = header->succ; p != trailer; p = p->succ) {
		visit(p->data);
	}
}
//��Increase<T>()Ϊ�����������б���
template <typename T> void List<T>::increase(List<T>& L) //ͳһ�����б��еĸ�Ԫ��
{
	L.traverse(Increase<T>());
} 
