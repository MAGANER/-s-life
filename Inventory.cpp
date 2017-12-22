#include "Inventory.h"


void Inventory::set_emptyness()
{
	empty = false;
}
void Inventory::show_inventory()
{
	for (int counter = 0; counter < items.size(); counter++)
	{
		cout << counter << " Type:" << items[counter].get_type() << endl;
		cout << counter << " Energy:" << items[counter].get_energy() << endl;
		cout << counter << " Health:" << items[counter].get_health() << endl;
		cout << counter << " Armor:" << items[counter].get_armor() << endl;
		cout << counter << " Weight:" << items[counter].get_type() << endl;
	}
}
bool Inventory::is_it_empty()
{
	if (empty == true)
	{
		return 1;
	}
}
void Inventory::add_item(vector<Object> items, int item_number)
{
	if (items[item_number].get_weight() < max_weight)
	{
		items.push_back(items[item_number]);
		cout << items[item_number].get_type() << endl;
	}
	else {
		cout << "it's so heavy to take! " << endl;
	}
}
int Inventory::get_weight()
{
	return weight;
}
Inventory::Inventory()
{
	max_weight = 100;
	weight = 0;
}
Inventory::~Inventory()
{
}
