#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include<iostream>

typedef int Rank; //��
#define Posi(T) ListNode<T>* //�б�ڵ�λ��

template<typename T> struct ListNode {//��˫������ʵ��
	//��Ա
	T data; // ֵ
	Posi(T) pred; // ��ǰ�ڵ�ǰ���ڵ��λ��
	Posi(T) succ; // ��ǰ�ڵ��̽ڵ��λ��

	//���캯��
	ListNode() {}//���header��trailer�Ĺ���
	ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL) :
		data(e), pred(p), succ(s) {}//Ĭ�Ϲ�����
	//�����ӿ�
	Posi(T) InsertAsPred(T const& e);//������ǰ�ڵ�֮ǰ�����½ڵ�
	Posi(T) InsertAsSucc(T const& e);//���浱ǰ�ڵ�֮������½ڵ�
}; 
#include "ListNode.inl"
#endif// !_LISTNODE_H_
