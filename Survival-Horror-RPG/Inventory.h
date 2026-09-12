#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include "Item.h"

class Inventory {
private:
	std::string m_name{};
	std::vector<Item> m_inventory{}; //Create an empty vector of Items

public:
	//Constructor
	Inventory(std::string_view name);

	//Add something to the inventory
	void add(const Item& item);

	//Print out the inventory
	friend std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
		out << "Printing the inventory.\n";

		for (auto& item : inventory.m_inventory) {
			out << "Item: " << item.getName() << '\n';
		}

		return out;
	}
};

#endif