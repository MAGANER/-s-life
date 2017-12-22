#pragma once
#include<vector>
#include"Object.h"
class Inventory
{
private:
	vector<Object> items;
	bool empty;
public:
	void show_inventory();
	void add_item(vector<Object>& creatures, int item_number);
	bool is_empty();
	Inventory();
	~Inventory();
};

