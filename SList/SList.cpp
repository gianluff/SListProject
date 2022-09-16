#include <iostream>
#include "SList.h"

template<class T>
SList<T>::SList()
{
	head = nullptr;
	size = 0;
}

template<class T>
SList<T>::SList(int32_t inSize, T element)
{
	size = inSize;
	for (int i = 0; i < size; i++)
	{
		ListNode<T>* temp = new ListNode<T>();
		temp->value = element;
		temp->next = head;
		head = temp;
	}
}

template<class T>
SList<T>::~SList()
{
	
	for (ListNode<T>* pointer = head; pointer != nullptr;)
	{
		ListNode<T>* temp = pointer;
		pointer = pointer->next;
		delete temp;
	}
}

template<class T>
bool SList<T>::empty() const noexcept
{
	if (head == nullptr)
		return true;
	else return false;
}

template<class T>
void SList<T>::clear() noexcept
{
	for (ListNode<T>* pointer = head->next; pointer != nullptr;)
	{
		ListNode<T>* temp = pointer;
		pointer = pointer->next;
		delete temp;
	}
	head = nullptr;
	size = 0;
}

template<class T>
T& SList<T>::front()
{
	return head->value;
}

template<class T>
void SList<T>::push_front(const T& value)
{
	ListNode<T>* temp = new ListNode<T>(value);
	temp->next = head;
	head = temp;
	size++;
}

template<class T>
void SList<T>::pop_front()
{
	ListNode<T>* temp = head;
	head = head->next;
	temp = head;
	delete temp;
}

template<class T>
void SList<T>::swap(SList& other)
{
	int32_t sizeTemp = size;
	ListNode<T>* temp = head;
	size = other.size;
	head = other.head;
	other.size = sizeTemp;
	other.head = temp;
	delete temp;
}

template<class T>
void SList<T>::reverse() noexcept
{
	ListNode<T>* current = head;
	ListNode<T>* reversedList = nullptr, * next = nullptr;

	while (current != NULL) {
		next = current->next;
		// Reverse current node's pointer
		current->next = reversedList;
		// Move pointers one position ahead.
		reversedList = current;
		current = next;
	}
	head = reversedList;
}

template<class T>
void SList<T>::printlist()
{
	for (ListNode<T>* pointer = head; pointer != nullptr; pointer = pointer->next)
	{
		std::cout << pointer->value << "	";
		//std::cout << "iteration" << std::endl;
	}
	std::cout << "\nlist terminated" << std::endl;
	if (head == nullptr)
		std::cout << "null list" << std::endl;
}



//main for debug purposes
int main()
{
	SList<int32_t> list1;
	SList<int> list2(6, 22);
	list1.printlist();
	list2.printlist();
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.push_front(64);
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.printlist();
	list2.push_front(89);
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.printlist();
	list2.pop_front();
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.printlist();
	list2.pop_front();
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.printlist();
	list2.pop_front();
	std::cout << "front value is: " << list2.front() << std::endl;
	list2.printlist();
	list2.clear();
	list2.printlist();
	SList<int32_t> list3;
	SList<int> list4(4, 12);
	list3.push_front(89);
	list3.push_front(12);
	list3.push_front(167);
	list4.push_front(2);
	list3.printlist();
	list4.printlist();
	list3.swap(list4);
	list3.printlist();
	list4.printlist();
	list4.reverse();
	list4.printlist();
	return 0;
}