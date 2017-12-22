#include "Inventory.h"

void Inventory::show_inventory()
{
	if (is_empty() == false)
	{
		for (int counter = 0; counter < items.size(); counter++)
		{
			cout << counter << " TYPE:" << items[counter].get_type();
			cout << counter << " HEALTH:" << items[counter].get_health();
			cout << counter << " ENERGY:" << items[counter].get_energy();
			cout << counter << " WEIGHT:" << items[counter].get_weight();
			cout << counter << " ARMOR:" << items[counter].get_armor();
			cout << counter << " DAMAGE:" << items[counter].get_damage();
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
	empty = true;
}
Inventory::~Inventory()
{
}
