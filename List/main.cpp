#include <iostream>
#include "List.h"


int main() {
	List<int> a;
	a.InsertAsFirst(1);
	
	a.InsertAsFirst(5); a.InsertAsFirst(3); a.InsertAsFirst(9); a.InsertAsFirst(2);
	a.Traverse();
	std::cout << a.find(5, a.Size()-2, a.Last())->data << "\n";
	a.Sort(a.First(),a.Size());
	a.Traverse();
	std::cout<<a.Search(4, a.Size()-1, a.Last())->data<<"\n";

	List<int> b(a);
	b.InsertAfter(b.First(), 10);
	b.Traverse();
	b.InsertAsLast(2);
	b.Sort(b.First(), b.Size()); b.Traverse();
	b.Uniquify();
	b.Traverse();

	List<int> c(b.First(),3);
	c.Traverse();
	c.InsertAsLast(1);	c.Traverse();
	c.Dequplicate();	c.Traverse();

	c.increase(c);
	c.Traverse();
}