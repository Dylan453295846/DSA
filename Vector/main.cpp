#include<iostream>
#include "Vector.h"

int main() {
	int arr[] = { 2,7,5,8,3 };

	Vector<int> a;
	a.CopyFromArray(arr, 5);
	std::cout<<a.Empty()<<" "<<a.Size()<<"\n";
	a.Insert(0, 3);
	a.Insert(5, a.Size()); a.Traverse();

	a.Duplicate(); a.Traverse();
	
	std::cout << a.find(9,0,a.Size()) << " " <<"\n";

	std::cout << a.find(3, 0, a.Size()) << " " << "\n";
	std::cout << a.IsOrdered() << " " << "\n";

	a.Pop(); a.Traverse();


	a.Sort(); a.Traverse();

	a.Insert(5, a.Size()); a.Traverse();
	std::cout << a.IsOrdered() << " " << "\n";

	a.Sort(); a.Traverse();
	std::cout << a.IsOrdered() << " " << "\n";

	a.Uniquify(); a.Traverse();

	std::cout << a.Search(2, 0, a.Size()) << "\n";

	a.Insert(1, 0); a.Insert(1, 0); a.Insert(1, 0);
	a.Insert(1, 0); a.Insert(1, 0); a.Insert(1, 0);
	a.Insert(1, 0); a.Insert(1, 0);
	a.Insert(1, 0); a.Insert(1, 0);
	a.Traverse();

}