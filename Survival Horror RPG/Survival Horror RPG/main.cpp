//Main

//Includes
using namespace std;
#include <iostream>
#include <string>

#include "HealingItem.h"

int main() {
	HealingItem herb = HealingItem("Herb", 1);
	string name = herb.getName();
	cout << "Hello World!" << name << endl;
}//main