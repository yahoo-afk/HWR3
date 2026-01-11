#include "Item.h"

Item::Item(const std::string name,int price)
	:name_(name),price_(price)
{

}

void Item::Clear()
{
	name_ = "";
	price_ = 0;
}

int Item::GetPrice()const
{
	return price_;
}

const std::string& Item::GetName()const
{
	return name_;
}