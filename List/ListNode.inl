
//��e������ǰ�ڵ�֮ǰ�����ڵ�ǰ�ڵ������б������ڱ�ͷ�ڵ�header��
template<typename T> Posi(T) ListNode<T>::InsertAsPred(T const& e) {
	Posi(T) x = new ListNode (e, pred, this);//�����½ڵ�
	pred->succ = x;
	pred = x; //������������
	return x; //�����½ڵ��λ��
}

//��e���浱ǰ�ڵ�֮������ڵ�ǰ�ڵ������б������ڱ�β�ڵ�trailer��
template<typename T> Posi(T) ListNode<T>::InsertAsSucc(T const& e) {
	//�����½ڵ㣬data=e,pred=this,succ=succ
	Posi(T) y = new ListNode(e, this, succ);
	succ->pred = y;//������������
	succ = y;
	return y;//�����½ڵ��λ��
}
