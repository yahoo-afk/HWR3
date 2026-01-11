#pragma once
#include<string>

class Item
{
private:
	int price_  ;
	std::string name_  ;
public:
	Item(const std::string name = "yahoo", int price = 1);
	void Clear();
	int GetPrice()const;
	const std::string& GetName()const;
};

