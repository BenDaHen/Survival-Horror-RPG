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

	void add(const Item& item); //Add something to the inventory

	void remove(const std::size_t index); //Remove something from the inventory

	std::size_t getLength() const { return m_inventory.size(); }
	std::size_t getCapacity() const { return m_inventory.capacity(); }

	//Print out the inventory
	friend std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
		out << "Printing the inventory.\n";

		int index{1};

		for (const auto& item : inventory.m_inventory) {
			out << "(" << index << ") Item: " << item.getName() << '\n';
			++index;
		}

		return out;
	}
};

#endif