/*the implementation of double linked list*/
#include<iostream>
using namespace std;
template<class T>

class linkedList

{
private:
	/*define my data type and the pointers*/
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		/*give the values an initional valus*/
		Node()
		{
			next = NULL;
			prev = NULL;	
		}

	};

	Node* head = NULL;
	int size = 0;
    public:
	/*the function that we use to implement the linked list*/
	/*insert methods*/
    void addFirst(T val);
	void addLast(T val);
	bool insert(int index, T element);
	/*search methods*/
	int indexof(T val);
	bool contains(T val);
	/*get methods*/
	T getfirst();
	T getlast();
	T getat(int index);
	int getSize();
	/*modify methods*/
	bool update(int index, T element);
	void clear();
	void reverse();
	/*delete methods*/
	T removeFirst();
	T removelast();
	bool remove(T element);
	/*others*/
	void print();
	bool isempty();
	/*constructor & destractor*/
	linkedList();
	~linkedList();

};
template<class T>
linkedList<T>::linkedList()
{
	
}
template<class T>
linkedList<T>::~linkedList()
{
}
template<class T>
//get linked list legnth // complexity=O(1)
int linkedList<T>::getSize()
{
	return size;
};
template<class T>
//to check that the lincked list is empty or not //complexity=O(1)
bool linkedList<T>::isempty()
{
	return (head == NULL);
};
template<class T>
/*add the first element in the linked list*//*complexity=O(1)*/
void linkedList<T>::addFirst(T val)
{

	Node* newNode = new Node;
	newNode->data = val;
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		Node* temp = head;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	size++;

};
template<class T>
/*add the last element in the linked list*//*complexity=O(n)*/
void linkedList<T>::addLast(T val)
{
	Node* newNode = new Node;
	newNode->data = val;
	if (head == NULL)
		head = newNode;
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;

	}
    size++;

};
template<class T>
/*reverse the elements from the first to the last*//*complexity=O(n)*/
void linkedList<T>::reverse()
{
	Node* temp = head;
	Node* current = head;
	Node* prev = NULL;
	while (current!=NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp!=NULL)
	{
		head = temp->prev;
	}
	
};
/*anthor code to reverse with printing the values *//*complexity=O(n)*/
/*void linkedList<T>::reverse()
{
	while (temp->next != NULL)
	{
		
     temp = temp->next;
	}
	while (temp != NULL)
	{

		cout << temp->data << " ";
		temp = temp->prev;
	}
	Node* temp = NULL;
};
	
*/
template<class T>
/*to check that any values is contain or not*//*complexity=O(n)*/
bool linkedList<T>::contains(T val)
{
	Node* temp = head;
	while (temp!=NULL)
	{
		if (temp->data == val) {
			return true;
		}
		temp = temp->next;
	}
	return false;
};
template<class T>
/*to get the first value in the linked list*//*complexity=O(1)*/
T linkedList<T>::getfirst()
{
	Node* temp = head;
	return temp->data;
};
template<class T>
/*to get the last value in the linked list*//*complexity=O(1)*/
T linkedList<T>::getlast()
{
	Node* temp = head;
	while (temp->next!= NULL)
		{
			temp = temp->next;
		}
	return temp->data;
};
template<class T>
/*to get the value that the user need in the linked list*//*complexity=O(n)*/
T linkedList<T>::getat(int index)
{
	Node* temp = head;
	if (index > (size - 1))//or if (index => (size))
	{
		return false;
	}
	if (index == 0)
		return temp->data;
	else
	{
        Node* temp = head;
        for (int x = 1;temp != NULL;x++)
		{
			temp = temp->next;
			if (x == index)
				return temp->data;
		}
	}
};
template<class T>
/*to get the index of an any element *//*complexity=O(n)*/
int linkedList<T>::indexof(T element)
{
	Node* temp = head;
	
	for (int x = 0; temp != NULL;x++)
	{
		
		if (temp->data == element)
			return x;
		temp = temp->next;
	}
	return false;
};
template<class T>
/*to add avalue in the linked list*//*complexity=O(n)*/
bool linkedList<T>::insert(int index, T element)
{
	if(index > getSize())
		return false;
	else
	{
		Node* newnode = new Node;
		newnode->data = element;
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			return true;
			size++;
		}
		if (index == 0)
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
			return true;
			size++;
		}
		
		Node* temp = head;
		
		newnode->data = element;
		for (int x = 0;x < index;x++)
		{
			temp = temp->next;
		}
		temp->prev->next = newnode;
		newnode->prev = temp->prev;
		temp->prev = newnode;
		newnode->next = temp;
		size++;
		return true;

	}
	

};
template<class T>
/*to update the values in the linked list*//*complexity=O(n)*/
bool linkedList<T>::update(int index, T element)
{
	if (index+1>size)//or (index>=size)
		return false;
	else
	{
		Node* temp = head;
		for (int i = 0; temp != NULL; i++)
		{
			if (i == index)
			{
				temp->data = element;
				return true;
			}
			temp = temp->next;
		}
	}
	
};
template<class T>
/*to delete all values in linked list *//*complexity=O(n)*/
void linkedList<T>::clear()
{
	head = NULL;
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		delete temp;
	}
};
template<class T>
/*to print the values that are excist in the linked list*//*complexity=O(n)*/
void linkedList<T>::print()
{
	if (isempty())
		return;
	else {
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
};
template<class T>
/*delete the first element in the linked list*//*complexity=O(1)*/
T linkedList<T>::removeFirst()
{	if (head == NULL)
	return NULL;
	Node* temp = head;
	head = head->next;
	return temp->data;
	size--;
	delete temp;
};
template<class T>
/*delete the last element in the linked lis*//*complexity=O(n)*/
T linkedList<T>::removelast()
{
	Node* temp = head;
	if (head == NULL)
		return NULL;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		size--;
		int x = temp->data;
		delete temp;
		return x;
		
		
	}
	
};
template<class T>
/*to remove an elelment in the linked list*//*complexity=O(n)*/
bool linkedList<T>::remove(T element)
{
	Node* temp = head;
	if (head == NULL)
	{
		return false;
	}
	if (temp->data == element)
	{
		head = temp->next;
		head->prev = NULL;
		delete temp;
		return true;
	}
	while (temp != NULL && temp->data != element)
	{
		temp = temp->next;
	}
	if (temp == NULL)
		return false;
	else
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
		delete temp;
		size--;
		return 1;
	}
};
