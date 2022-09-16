#pragma once

template<typename T>
struct ListNode
{
	T value;
	ListNode* next;

	ListNode()
	{

	}

	ListNode(const T& inValue)
	{
		value = inValue;
	}
	
};

template<typename T> 
class SList
{
	ListNode<T> *head;
	int32_t size;

public:

	SList();
	SList(int32_t size, T element);
	~SList();
	SList& operator=(const SList& other);
	void assign(int32_t size, T element);
	bool empty() const noexcept;
	//size_type max_size() const noexcept;
	void clear() noexcept;
	T& front();
	void push_front(const T& value);
	void pop_front();
	void swap(SList& other);
	void reverse() noexcept;

	//get_allocator
	//before_begin
	//begin
	//end
	//insert_after
	//emplace_after
	//erase_after
	//resize
	//swap
	//merge
	//splice_after
	//remove
	//reverse
	//unique
	//sort
	
	//FOR DEBUG PURPOSES:
	void printlist();
};