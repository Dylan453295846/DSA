
//将e紧靠当前节点之前插入于当前节点所属列表（设有哨兵头节点header）
template<typename T> Posi(T) ListNode<T>::InsertAsPred(T const& e) {
	Posi(T) x = new ListNode (e, pred, this);//创建新节点
	pred->succ = x;
	pred = x; //设置正向链接
	return x; //返回新节点的位置
}

//将e紧随当前节点之后插入于当前节点所属列表（设有哨兵尾节点trailer）
template<typename T> Posi(T) ListNode<T>::InsertAsSucc(T const& e) {
	//创建新节点，data=e,pred=this,succ=succ
	Posi(T) y = new ListNode(e, this, succ);
	succ->pred = y;//设置逆向链接
	succ = y;
	return y;//返回新节点的位置
}
