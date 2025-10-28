#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class DataType>
class clsDblLinkedList
{


public:
	class Node
	{
	public:

		Node* Next;
		Node* Prev;
		DataType value;



	};

private:
	Node* Head = NULL;
	int _Size = 0;
public:


	void InsertAtBeginning(DataType value)
	{

		Node* New_Node = new Node();




		New_Node->Next = Head;
		New_Node->Prev = NULL;
		New_Node->value = value;


		if (Head != NULL)
		{
			Head->Prev = New_Node;
		}

		Head = New_Node;
		_Size++;


	};


	void PrintList()
	{
		Node* Temp;
		Temp = Head;

		while (Temp != NULL)
		{

			cout << Temp->value << " ";
			Temp = Temp->Next;

		}

		cout << endl;
	};
	Node* Find(DataType value)
	{

		Node* Temp = Head;
		while (Temp != NULL)
		{

			if (Temp->value == value)
			{
				return Temp;
			}
			Temp = Temp->Next;
		}
		return NULL;
	};
	void InsertAfter(Node* InsertAfterThisNode, DataType value)
	{
		Node* Temp = Head;
		Node* New_Node = new Node();
		New_Node->value = value;
		Temp = InsertAfterThisNode;

		if (InsertAfterThisNode == NULL)
		{
			return;
		}

		if (Head == NULL)
		{
			Head = New_Node;
			_Size++;

			return;
		}


		if (Temp->Next == NULL)
		{
			Temp->Next = New_Node;
			New_Node->Prev = Temp;
			_Size++;

			return;
		}


		New_Node->Next = Temp->Next;
		Temp->Next->Prev = New_Node;
		Temp->Next = New_Node;
		_Size++;


	}
	void InsertAtEnd(DataType value)
	{

		Node* Temp = Head;
		Node* New_Node = new Node();
		New_Node->value = value;


		if (Head == NULL)
		{
			Head = New_Node;
			_Size++;

			return;
		}

		while (Temp != NULL)
		{

			if (Temp->Next == NULL)
			{
				Temp->Next = New_Node;
				New_Node->Prev = Temp;
				_Size++;

				return;
			}
			Temp = Temp->Next;

		}








	}
	void DeleteNode(Node* NodeTarget)
	{

		Node* Temp = NodeTarget;

		if (NodeTarget == NULL)
		{
			return;
		}


		if (Temp->Prev == NULL || Temp->Next == NULL)
		{
			if (Temp->Prev == NULL)
			{
				Temp = Temp->Next;
				Temp->Prev = NULL;
				Head = Temp;
			};

			if (Temp->Next == NULL)
			{
				Temp = Temp->Prev;
				Temp->Next = NULL;

			};
			_Size++;

			delete NodeTarget;
			return;
		}



		Temp->Prev->Next = Temp->Next;
		Temp->Next->Prev = Temp->Prev;
		delete NodeTarget;
		_Size++;

		return;


	}
	void DeleteFirstNode()
	{



		if (Head == NULL) {
			return;
		}
		Node* temp = Head;
		Head = Head->Next;
		if (Head != NULL)
		{
			Head->Prev = NULL;
		};
		_Size--;

		delete temp;

	}
	void DeleteLastNode()
	{

		Node* Temp;
		Temp = Head;

		while (true)
		{

			if (Temp->Next->Next == NULL)
			{
				delete Temp->Next;
				Temp->Next = NULL;
				_Size--;

				return;
			}
			Temp = Temp->Next;

		}






	}
	DataType Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{


		return (Head == NULL) ? true : false;

	}
	void Clear()
	{


		while (Head != NULL)
			DeleteFirstNode();

	}
	void Reverse()
	{

		 


		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current != nullptr)
		{

			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;
			Current = Current->Prev;

		};

		if (Temp != nullptr)
		{
			Head = Temp->Prev;
		}

	};
	Node* GetNode(int Index)
	{
		Node* Current = Head;
		int Counter = 0;
		if (Index >= _Size || Index < 0)
		{
			return NULL;
		};


		while ((Current->Next != NULL) &&Current != NULL)
		{


			if (Counter == Index)
				break;
		

			Counter++;
			Current = Current->Next;

		};

		return Current;
};
	DataType GetItem(int Index)
	{
	
		Node *Current =  GetNode(Index);
		if (Current != NULL)
		{
			return Current->value;
	
		}
		else
		{
			return NULL;
		}
		
	}
	bool UpdateNode(int Index,DataType Value)
	{
	
		Node* Current = GetNode(Index);
		if (Current != NULL)
		{
			Current->value = Value;
			return true;
		}
		else
		{
			return false;
		}


	
	
	}
	bool InsertAfter(int Index, DataType value)
	{
		Node* Current = Head;
		Node* New_Node = new Node();
		New_Node->value = value;
		Current = GetNode(Index);
		if (Current != NULL)
		{
			InsertAfter(Current, value);
			return true;
		}
		else
		{
			return false;
		};


	};






};

