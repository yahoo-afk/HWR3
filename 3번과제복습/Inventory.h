#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

bool compareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}
template<typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10)
		:pItems_(new T[capacity]), capacity_(capacity), size_(0)
	{
		if (capacity <= 0)
		{
			capacity = 1;
		}
	}
	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++)
		{
			pItems_[i] = other.pItems_[i];
		}
		std::cout << "인벤토리 복사" << std::endl;
	}
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}
	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다" << std::endl;
		}
		else
		{
			size_--;
		}
	}
	void  AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
			/*std::cout << "인벤토리가 꽉찾습니다." << std::endl;*/
		}
		pItems_[size_] = item;
		size_++;
	}
	int GetSize()const
	{
		return size_;
	}
	int GetCapacity()const
	{
		return capacity_;
	}
	void PrintAllItems()const
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << "[이름:" << pItems_[i].GetName() << ",가격:" << pItems_[i].GetPrice() << "G]" << std::endl;
		}
	}
	void Resize(int newCapacity)
	{
		if (newCapacity <= 0 || newCapacity < size_)
		{
			return;
		}
		T* a = new T[newCapacity];
		for (int i = 0; i < size_; i++)
		{
			a[i] = pItems_[i];
		}
		delete[] pItems_;
		pItems_ = a;
		a = nullptr;
		capacity_ = newCapacity;
	}

	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
	}
};
