#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include<iostream>

typedef int Rank; //秩
#define Posi(T) ListNode<T>* //列表节点位置

template<typename T> struct ListNode {//以双向链表实现
	//成员
	T data; // 值
	Posi(T) pred; // 当前节点前驱节点的位置
	Posi(T) succ; // 当前节点后继节点的位置

	//构造函数
	ListNode() {}//针对header和trailer的构造
	ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL) :
		data(e), pred(p), succ(s) {}//默认构造器
	//操作接口
	Posi(T) InsertAsPred(T const& e);//紧靠当前节点之前插入新节点
	Posi(T) InsertAsSucc(T const& e);//紧随当前节点之后插入新节点
}; 
#include "ListNode.inl"
#endif// !_LISTNODE_H_
