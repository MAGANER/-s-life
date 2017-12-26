#include "Inventory.h"

string Inventory::get_type(int item_number)
{
	return items[item_number].get_type();
}
void Inventory::set_equipedness(int item_number)
{
	// it means this item is equiped
	items[item_number].equiped = true;
}
bool Inventory::is_equiped(int item_number)
{
	return items[item_number].equiped;
}
int Inventory::get_weight(int item_number)
{
	return items[item_number].get_weight();
}
int Inventory::get_damage(int item_number)
{
	return items[item_number].get_damage();
}
int Inventory::get_armor(int item_number)
{
	return items[item_number].get_armor();
}
int Inventory::get_energy(int item_number)
{
	return items[item_number].get_energy();
}
int Inventory::get_health(int item_number)
{
	return items[item_number].get_health();
}
void Inventory::delete_item(int item_number)
{
	if (item_number == 0)
	{
		items.erase(items.begin());
	}
	else {
		items.erase(items.begin() + item_number);
	}
}
int Inventory::get_inventory_size()
{
	return items.size();
}
void Inventory::show_inventory()
{
	if (is_empty() == false)
	{
		for (int counter = 0; counter < items.size(); counter++)
		{
			cout << counter << " TYPE:" << items[counter].get_type()<<endl;
			cout << counter << " HEALTH:" << items[counter].get_health() << endl;
			cout << counter << " ENERGY:" << items[counter].get_energy() << endl;
			cout << counter << " WEIGHT:" << items[counter].get_weight() << endl;
			cout << counter << " ARMOR:" << items[counter].get_armor() << endl;
			cout << counter << " DAMAGE:" << items[counter].get_damage() << endl;
		}
	}
	else {
		cout << "inventory is empty..." << endl;
	}
}
bool Inventory::is_empty()
{
	return empty;
}
void Inventory::add_item(vector<Object>& creatures,int item_number)
{
	empty = false;
	items.push_back(creatures[item_number]);
}
Inventory::Inventory()
{
	// at game start invt is empty
	empty = true;
}
Inventory::~Inventory()
{
}
