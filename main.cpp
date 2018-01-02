#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include"Map.h"
#include"Player.h"
#include<vector>
#include"Object.h"
#include"Inventory.h"
#include"Enemy.h"
#include<Windows.h>

Inventory invt;
Player hero;

int deads = 0;
int turn = 0;
bool GAME = true;
bool clear_screen = true;

void monsters_move(vector<Enemy>& enemies);
void draw_hero();
void draw_monsters(vector<Enemy>& enemies);
void draw_objects(vector<Object>& creatures);
void enter_command(vector<Object>& creatures, vector<Enemy>& enemies);
void draw_game_info();
void draw_game_screen();
void main()
{
	SetConsoleTitle("Roguelike");

	///   ITEM CREATING          ///
	// 1.get number of creatures
	// 2.create them
	srand(time(0));
	int creat_numb = 500 + rand() % 1000;
	vector<Object> creatures(creat_numb, Object());
	for (int counter = 0; counter < creatures.size(); counter++)
	{
		creatures[counter].generate();
	}
	///   MONSTER CREATING     ///
	srand(time(0));
	int monster_numb = 100 + rand() % 300;
	vector<Enemy> enemies(monster_numb, Enemy());
	for (int counter = 0; counter < enemies.size(); counter++)
	{
		enemies[counter].generate();
	}

	// game cycle
	while (GAME)
	{
		// play if hero is alive
		if (hero.return_health() > 0)
		{
			if (clear_screen)
			{
				draw_hero();
				draw_monsters(enemies);
				draw_objects(creatures);
				draw_game_info();
				draw_game_screen();
				enter_command(creatures, enemies);
                // check monsters' energy
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					if (enemies[counter].get_energy() == 0)
					{
						enemies[counter].fuck_away();
						deads++;
					}
				}
				// check monsters' lifes
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					if (enemies[counter].get_health() <= 0)
					{
						enemies[counter].fuck_away();
						deads++;
					}
				}
				// monsters detect hero
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					enemies[counter].detect_target(hero.return_x(), hero.return_y());

				}
				monsters_move(enemies);
				system("cls");
			}
			// die if hero hasn't energy else decrease energy
			if (hero.energy > 0)
			{
				hero.energy = hero.energy - 1 - hero.taken_items_weight;
			}
			else {
				hero.die();
			}

			// every 5 turn increase hero strength, energy
			int start_turn = 0; 
			int now_turn = turn;
			if (start_turn + 5 == turn)
			{
				start_turn = turn;
				hero.increase_strength();
				hero.increase_energy();
			}
		}
		else {
			cout << "                          GAME OVER!";
			break;
		}
		
		turn++;
	}

	_getch();
}
void draw_hero()
{
	map[hero.return_y()][hero.return_x()] = hero.return_hero();
}
void draw_monsters(vector<Enemy>& enemies) 
{
	for (int counter = 0; counter < enemies.size(); counter++)
	{
		map[enemies[counter].return_y()][enemies[counter].return_x()] = enemies[counter].return_hero();
	}
}
void draw_objects(vector<Object>& creatures)
{
	for (int counter = 0; counter < creatures.size(); counter++)
	{
		if (creatures[counter].show == true)
		{
			map[creatures[counter].get_y_pos()][creatures[counter].get_x_pos()] = creatures[counter].get_view();
		}
		else {
			map[creatures[counter].get_y_pos()][creatures[counter].get_x_pos()] = ' ';
		}
	}
}
void draw_game_screen()
{
	for (int line = 0; line < 59; line++)
	{
		for (int colomn = 0; colomn < 175; colomn++)
		{
			cout << map[line][colomn];
		}
		cout << endl;
	}
}
void draw_game_info()
{
	cout << "                             " << "PERSONAL INFORMATION" << endl;
	cout << "HEALTH:" << hero.return_health()<<endl;
	cout << "DAMAGE:" << hero.return_damage() << endl;
	cout << "ARMOR:" << hero.return_armor() << endl;
	cout << "MANA:" << hero.return_mana() << endl;
	cout << "ENERGY:" << hero.energy << endl;
	cout << "STRENGTH:" << hero.get_strength() << endl;
	cout << "INTELLECT:" << hero.get_intellect() << endl;
	cout << "SPEED:" << hero.get_speed() << endl;
	cout << "TAKEN ITEMS' WEIGHT:" << hero.taken_items_weight << endl;
	cout << "TURN:" << turn << endl;
	cout << "DEADS:" << deads << endl;
}
void enter_command(vector<Object>& creatures, vector<Enemy>& enemies)
{
	cout << endl;
	cout << "COMMANDS:" << endl;
	string command, old_command;
	cin >> command;
	if (command == "go_up")
	{
		hero.set_y(hero.return_y() - hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_down")
	{
		hero.set_y(hero.return_y() + hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_right")
	{
		hero.set_x(hero.return_x() + hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_left")
	{
		hero.set_x(hero.return_x() - hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "take")
	{
		// character can take item if this item beside its
		for (int counter = 0; counter < creatures.size(); counter++)
		{
			if (hero.return_x() + 1 == creatures[counter].get_x_pos() && hero.return_y() == creatures[counter].get_y_pos())
			{
				hero.taken_items_weight = hero.taken_items_weight + creatures[counter].get_weight();
				invt.add_item(creatures, counter);
				creatures[counter].fuck_away();
				clear_screen = true;
			}
		}
	}
	else if (command == "show_invt")
	{
		invt.show_inventory();
		clear_screen = false;
		enter_command(creatures,enemies);
	}
	else if (command == "continue")
	{
		clear_screen = true;
	}
	else if (command == "use")
	{
		string using_type;
		int item_number;
		cout << "enter number of item you want to use:";
		cin >> item_number;
		cout << "enter what do you want to do with that:";
		cin >> using_type;
		if (invt.get_inventory_size() < item_number)
		{
			cout << "you have no " << item_number << "th item!" << endl;
		}
		else 
		{
			if (using_type == "eat")
			{
				if (invt.get_type(item_number) == " stone" || invt.get_type(item_number) == "iron")
				{
					cout << "you can not eat " << invt.get_type(item_number) << "!";
					enter_command(creatures,enemies);
				}
				else {
					hero.set_energy(invt.get_energy(item_number));
					hero.set_health(invt.get_health(item_number));
					// if we eat armor or weapon
					// so armor and weapon must be deleted
					// and their weight too
					if (invt.is_equiped(item_number))
					{
						hero.set_armor(-hero.return_armor());
						hero.set_damage(-hero.return_damage() + 1);
					}
					hero.taken_items_weight = hero.taken_items_weight - invt.get_weight(item_number);
					invt.delete_item(item_number);
				}
				if (invt.get_type(item_number) == "speed_potion")
				{
					hero.set_energy(invt.get_energy(item_number));
					hero.set_health(invt.get_health(item_number));
					hero.increase_energy();
					hero.taken_items_weight = hero.taken_items_weight - invt.get_weight(item_number);
					invt.delete_item(item_number);
				}
			}
			if (using_type == "equip")
			{
				string equipment_type;
				cout << "you want to use that as weapon or as armor:";
				cin >> equipment_type;
				if (equipment_type == "weapon")
				{
					hero.set_damage(invt.get_damage(item_number));
				}
				if (equipment_type == "armor")
				{
					hero.set_armor(invt.get_armor(item_number));
				}
				invt.set_equipedness(item_number);
			}
		}
		clear_screen = true;
	}
	else if (command == "throw")
	{
		int item_number;
		cout << "enter item number you want to throw:";
		cin >> item_number;
		if (invt.get_inventory_size() < item_number)
		{
			cout << "you have no " << item_number << "!";
			enter_command(creatures, enemies);
		}
		else {
			string direct;
			cout << "enter direction:";
			cin >> direct;
			if(direct == "up")
			{
				vector<int> x_poses;
				vector<int> y_poses;
				int enemy_count = 0;
				for (int counter = 0; counter < enemies.size();counter++)
				{
					if (hero.return_x() == enemies[counter].return_x() && hero.return_y() > enemies[counter].return_y() && enemies[counter].get_health() > 0)
					{
						enemy_count++;
						x_poses.push_back(enemies[counter].return_x());
						y_poses.push_back(enemies[counter].return_y());
					}
				}
				if (enemy_count > 0)
				{
					cout << " at this direction you have " << enemy_count << endl;
					int enemy_number;
					cout << "enter enemy number you want to attack:";
					cin >> enemy_number;
					if (enemy_number > enemy_count)
					{
						cout << "there is not so much enemies!" << endl;
						enter_command(creatures, enemies);
					}
					else 
					{
						int target_number;
						for (int counter = 0; counter < enemies.size(); counter++)
						{
							int x = x_poses[enemy_number];
							int y = y_poses[enemy_number];
							if (x == enemies[counter].return_x() && y == enemies[counter].return_y())
							{
								target_number = counter;
								break;
							}
						}
						int target_x = enemies[target_number].return_x();
						int target_y = enemies[target_number].return_y();
						unsigned int range = target_y - hero.return_y();
						int damage = (invt.get_damage(item_number) + hero.get_strength()) - (range %2);
						enemies[target_number].set_health(damage);
						invt.delete_item(item_number);
						if (enemies[target_number].get_health() <= 0)
						{
							deads++;
						}
					}
				}
				else {
					cout << " at this direction no enemies!" << endl;
					enter_command(creatures, enemies);
				}
			}
			else if(direct=="down")
			{ 
				vector<int> x_poses;
				vector<int> y_poses;
				int enemy_count = 0;
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					if (hero.return_x() == enemies[counter].return_x() && hero.return_y() < enemies[counter].return_y() && enemies[counter].get_health() > 0)
					{
						enemy_count++;
						x_poses.push_back(enemies[counter].return_x());
						y_poses.push_back(enemies[counter].return_y());
					}
				}
				if (enemy_count > 0)
				{
					cout << " at this direction you have " << enemy_count << endl;
					int enemy_number;
					cout << "enter enemy number you want to attack:";
					cin >> enemy_number;
					if (enemy_number > enemy_count)
					{
						cout << "there is not so much enemies!" << endl;
						enter_command(creatures, enemies);
					}
					else
					{
						int target_number;
						for (int counter = 0; counter < enemies.size(); counter++)
						{
							int x = x_poses[enemy_number];
							int y = y_poses[enemy_number];
							if (x == enemies[counter].return_x() && y == enemies[counter].return_y())
							{
								target_number = counter;
								break;
							}
						}
						int target_x = enemies[target_number].return_x();
						int target_y = enemies[target_number].return_y();
						unsigned int range = target_y - hero.return_y();
						int damage = (invt.get_damage(item_number) + hero.get_strength()) - (range %2);
						enemies[target_number].set_health(-damage);
						invt.delete_item(item_number);
						if (enemies[target_number].get_health() <= 0)
						{
							deads++;
						}
					}
				}
				else {
					cout << " at this direction no enemies!" << endl;
					enter_command(creatures, enemies);
				}
					
			}
			else if(direct=="right")
			{
				vector<int> x_poses;
				vector<int> y_poses;
				int enemy_count = 0;
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					if (hero.return_x() < enemies[counter].return_x() && hero.return_y() == enemies[counter].return_y() && enemies[counter].get_health() > 0)
					{
						enemy_count++;
						x_poses.push_back(enemies[counter].return_x());
						y_poses.push_back(enemies[counter].return_y());
					}
				}
				if (enemy_count > 0)
				{
					cout << " at this direction you have " << enemy_count << endl;
					int enemy_number;
					cout << "enter enemy number you want to attack:";
					cin >> enemy_number;
					if (enemy_number > enemy_count)
					{
						cout << "there is not so much enemies!" << endl;
						enter_command(creatures, enemies);
					}
					else
					{
						int target_number;
						for (int counter = 0; counter < enemies.size(); counter++)
						{
							int x = x_poses[enemy_number];
							int y = y_poses[enemy_number];
							if (x == enemies[counter].return_x() && y == enemies[counter].return_y())
							{
								target_number = counter;
								break;
							}
						}
						int target_x = enemies[target_number].return_x();
						int target_y = enemies[target_number].return_y();
						unsigned int range = target_x - hero.return_x();
						int damage = (invt.get_damage(item_number) + hero.get_strength()) - (range % 2);
						enemies[target_number].set_health(-damage);
						invt.delete_item(item_number);
						if (enemies[target_number].get_health() <= 0)
						{
							deads++;
						}
					}
				}
				else {
					cout << " at this direction no enemies!" << endl;
					enter_command(creatures, enemies);
				}
			}
			else if(direct =="left")
			{
				vector<int> x_poses;
				vector<int> y_poses;
				int enemy_count = 0;
				for (int counter = 0; counter < enemies.size(); counter++)
				{
					if (hero.return_x() > enemies[counter].return_x() && hero.return_y() == enemies[counter].return_y() && enemies[counter].get_health() > 0)
					{
						enemy_count++;
						x_poses.push_back(enemies[counter].return_x());
						y_poses.push_back(enemies[counter].return_y());
					}
				}
				if (enemy_count > 0)
				{
					cout << " at this direction you have " << enemy_count << endl;
					int enemy_number;
					cout << "enter enemy number you want to attack:";
					cin >> enemy_number;
					if (enemy_number > enemy_count)
					{
						cout << "there is not so much enemies!" << endl;
						enter_command(creatures, enemies);
					}
					else
					{
						int target_number;
						for (int counter = 0; counter < enemies.size(); counter++)
						{
							int x = x_poses[enemy_number];
							int y = y_poses[enemy_number];
							if (x == enemies[counter].return_x() && y == enemies[counter].return_y())
							{
								target_number = counter;
								break;
							}
						}
						int target_x = enemies[target_number].return_x();
						int target_y = enemies[target_number].return_y();
						unsigned int range = target_x - hero.return_x();
						int damage = (invt.get_damage(item_number) + hero.get_strength()) - (range %2);
						enemies[target_number].set_health(-damage);
						invt.delete_item(item_number);
						if (enemies[target_number].get_health() <= 0)
						{
							deads++;
						}
					}
				}
				else {
					cout << " at this direction no enemies!" << endl;
					enter_command(creatures, enemies);
				}
			}
		}
	}
	else {
		cout << "no " << command << " command!";
		clear_screen = false;
		enter_command(creatures,enemies);
	}

}
void monsters_move(vector<Enemy>& enemies)
{
	for (int counter = 0; counter < enemies.size(); counter++)
	{
		if (enemies[counter].get_health() > 0)
		{
			enemies[counter].go();
			map[enemies[counter].return_old_y()][enemies[counter].return_old_x()] = ' ';
		}
	}
}
