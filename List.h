#pragma once
#include"MyData.h"

template<class T, int size>
class List
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int length = 0;

public:
	~List()
	{

	}

	void push_front(T val);
	void push_back(T val);
	void push_at(T val, int pos);
	T pop_front();
	T pop_back();
	T pop_at(int pos);
	T peek_front();
	T peek_back();
	T peek_at(int pos);
	void print();
	int getSize();
	void clear();
	bool isEmpty();
	bool isFull();
};

template<class T, int size>
inline void List<T, size>::push_front(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = first;
			first = temp;
		}
		length++;
	}
	else
		cout << "List full" << endl;
}

template<class T, int size>
inline void List<T, size>::push_back(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			last->next = temp;
			last = temp;
		}
		length++;
	}
	else
		cout << "List full" << endl;
}

template<class T, int size>
inline T List<T, size>::pop_front()
{
	if (length > 0)
	{

		T val;
		MyData<T>* temp;
		val = first->value;
		temp = first;
		first = first->next;
		delete temp;
		length--;
		return val;
		
	}
	else
	{
		cout<<"list has already empty"
	}
}

template<class T, int size>
inline T List<T, size>::pop_back()
{
	if (length > 0)
	{

		T val;
		int k = length;
		MyData<T>* temp;
		MyData<T>* priv=this->first;
		val = last->value;
		temp = last;
		
		if (length > 2)
		{
			for (size_t i = 0; i < k - 2; i++)
			{
				priv = priv->next;
			}
		}
		else
		{
			this->pop_front();
		}
		last = priv;
			
		delete temp;
		length--;
		return val;

	}
	else
	{
		cout << "list has already empty"
	}
}
