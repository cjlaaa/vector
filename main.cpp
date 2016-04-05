#include"Vector.h"
#include<iostream>
#include <string>
using namespace std;

int main()
{
	Vector<int> MyVector;
	MyVector.PushBack(123);
	MyVector.PushBack(234);
	MyVector.PushBack(345);
	MyVector.PushBack(456);
	MyVector.Insert(987,3);

	Vector<int>::Iterator iter=MyVector.Begin();

	for (;iter != MyVector.End();iter++)
	{
		cout<<iter.Get()<<" ";
	}

	cout<<endl;

	//iter=MyVector.End();
	//while(iter!=MyVector.Begin())
	//{
	//	cout<<iter.Get()<<" ";
	//	iter--;
	//}
    return 0;
}