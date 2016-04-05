#ifndef __CJLAAA_VECTOR__
#define __CJLAAA_VECTOR__

#define NULL 0

template<class Node,class Type>
class MyIterator
{
public:
	MyIterator();
	MyIterator(Node*iter);
	void operator++(int);
	void operator--(int);
	bool operator==(MyIterator &pForCompare);
	bool operator!=(MyIterator &pForCompare);
	Type Get();
private:
	Node *pCur;
};

template<class Node,class Type>
MyIterator<Node,Type>::MyIterator(Node*iter)
{
	this->pCur=iter;
}

template<class Node,class Type>
Type MyIterator<Node, Type>::Get()
{
	return pCur->type;
}

template<class Node,class Type>
bool MyIterator<Node, Type>::operator==(MyIterator &pForCompare)
{
	if (pForCompare.pCur==pCur)
	{
		return true;
	}
	return false;
}

template<class Node,class Type>
bool MyIterator<Node, Type>::operator!=( MyIterator &pForCompare )
{
	if (pForCompare.pCur!=pCur)
	{
		return true;
	}
	return false;
}

template<class Node,class Type>
void MyIterator<Node, Type>::operator--(int)
{
	pCur=pCur->Pre;
}

template<class Node,class Type>
void MyIterator<Node, Type>::operator++(int)
{
	pCur=pCur->Next;
}

template<class Type>
class Vector
{
public:
	Vector();
	~Vector();
	void PushBack(Type type);
	void PopBack();
	void Insert(Type type,int Index);
	Type At(int Index);
	int Size();
	void Erase(int Index);
	void Modify(int Index,Type type);
	void Clear();
	Type operator[](int Index);
	bool Empty();
private:
	struct Node
	{
		Type type;
		Node *Next;
		Node *Pre;
	};

public:
	typedef MyIterator<Node,Type> Iterator;
private:
	Node *pHead;
	Node *pTail;
	int VectorSize;

	Node* GetNodeFromIndex(int Index)
	{
		Node* p=pHead;
		int Count=0;
		while (p!=NULL)
		{
			if (Index==Count)
			{
				return p;
			}
			p=p->Next;
			Count++;
		}
		return NULL;
	}
public:
	Iterator Begin()
	{
		Iterator iter(pHead);
		return iter;
	}
	Iterator End()
	{
		Iterator iter(NULL);
		return iter;
	}
};

template<class Type>
bool Vector<Type>::Empty()
{
	if (VectorSize==0)
	{
		return true;
	}
	return false;
}

template<class Type>
void Vector<Type>::Clear()
{
	while (pHead!=NULL)
	{
		Erase(0);
	}
}

template<class Type>
void Vector<Type>::Modify(int Index,Type type)
{
	Node *p=GetNodeFromIndex(Index);
	p->type=type;
	return ;
}

template<class Type>
Type Vector<Type>::operator[]( int Index )
{
	Node*p=GetNodeFromIndex(Index);
	return p->type;
}

template<class Type>
void Vector<Type>::PopBack()
{
	Erase(VectorSize-1);
}

template<class Type>
void Vector<Type>::Insert(Type type,int Index)
{
	Node *p=new Node;
	p->type=type;
	if (Index==0)
	{
		pHead->Pre=p;
		p->Pre=NULL;
		p->Next=pHead;
		pHead=p;
		VectorSize++;
		return;
	}
	else
	{
		Node *pCur=GetNodeFromIndex(Index);
		pCur->Pre->Next=p;
		p->Pre=pCur->Pre;
		pCur->Pre=p;
		p->Next=pCur;
		VectorSize++;
		return;
	}
}

template<class Type>
void Vector<Type>::Erase(int Index)
{
	if (Index==0)
	{
		if (VectorSize==1)
		{
			VectorSize--;
			delete pHead;
			pHead=NULL;
			return;
		}
		Node *p=pHead;
		p->Next->Pre=NULL;
		pHead=p->Next;
		delete p;
		VectorSize--;
		return;
	}
	else if (Index==VectorSize-1)
	{
		Node *p=pTail;
		p->Pre->Next=NULL;
		pTail=p->Pre;
		delete p;
		VectorSize--;
		return;
	}
	else
	{
		Node *p=GetNodeFromIndex(Index);
		p->Next->Pre=p->Pre;
		p->Pre->Next=p->Next;
		delete p;
		VectorSize--;
		return;
	}
}

//template<class Type>
//Node* Vector<Type>::GetNodeFromIndex( int Index )
//{
//	Node* p=Begin;
//	int Count=0;
//	while (p!=NULL)
//	{
//		if (Index==Count)
//		{
//			return p;
//		}
//		p=p->Next;
//		Count++;
//	}
//	return NULL;
//}

template<class Type>
int Vector<Type>::Size()
{
	return VectorSize;
}

template<class Type>
void Vector<Type>::PushBack(Type type)
{
	Node *p=new Node;
	p->type=type;
	p->Next=NULL;
	p->Pre=NULL;

	if (VectorSize==0)
	{
		pHead=p;
		pTail=p;
		VectorSize++;
	}
	else
	{
		pTail->Next=p;
		p->Pre=pTail;
		pTail=p;
		VectorSize++;
	}
}

template<class Type>
Type Vector<Type>::At(int Index)
{
	Node* p=GetNodeFromIndex(Index);
	return p->type;
}

template<class Type>
Vector<Type>::~Vector()
{

}

template<class Type>
Vector<Type>::Vector()
{
	pHead=NULL;
	pTail=NULL;
	VectorSize=0;
}

#endif