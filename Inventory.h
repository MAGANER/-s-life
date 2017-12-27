#pragma once
#include<vector>
#include"Object.h"
class Inventory
{
private:
	vector<Object> items;
	bool empty;
	int weight;
public:
	void add_created_object(int energy, int weight, int damage, int health, int armor, string item_type,string type);
	void take_reagents(string object);
	int get_invt_weight();
	string get_type(int item_number);
	void set_equipedness(int item_number);
	bool is_equiped(int item_number);
	int get_weight(int item_number);
	int get_damage(int item_number);
	int get_armor(int item_number);
	int get_energy(int item_number);
	int get_health(int item_number);
	void delete_item(int item_number);
	int get_inventory_size();
	void show_inventory();
	void add_item(vector<Object>& creatures, int item_number);
	bool is_empty();
	Inventory();
	~Inventory();
};

