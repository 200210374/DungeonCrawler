// DungeonCrawler.cpp : Defines the entry point for the console application.



#include "stdafx.h";
#include <iostream>
#include "Header.h"
#include <Windows.h>
#include <string>

using namespace std;


//structure used for player and enemies


struct hero {

	int health;
	int damage;
	int defense;
	unsigned char x;
	unsigned char y;
	int magic;
};


struct enemy {

	int health;
	int damage;
	int enemydefense;
	unsigned char x;
	unsigned char y;
};



struct dungeonKeeper {

	int health;
	int damage;
	unsigned char x;
	unsigned char y;
};

struct finalBoss {

	int health;
	int damage;
	int defense;
	unsigned char x;
	unsigned char y;
};


struct minos {

	int health;
	int damage;
	int defense;
	unsigned char x;
	unsigned char y;
};




struct trap {

	
	int damage;
	int dodgeAttempt;
	unsigned char x;
	unsigned char y;
};






void main() {



	int choice;

	bool quit = false;


	//variables used in structure

	hero player;
	player.health = 200 + rand() % 150;
	player.defense = 4 + rand() % 10;
	player.x = 38;
	player.y = 19;
	player.damage = 40 + rand() % 10;
	player.magic = rand() % 150;




	while (!quit) {
		

		do {
			PrintMenu();
			cin >> choice;
		} while (choice < 1 || choice > 4);


		if (choice == 1) {


			cout << "Welcome to the dungeon" << endl;
			
			bool hero_win = false;

			unsigned char maze[20][40] = {
				{4,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{0,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
				{0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1},
				{0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1},
				{0,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1},
				{0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,1,1},
				{0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,1,1},
				{0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,1,1},
				{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,1,0,1,1},
				{1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,1},
				{1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,0,1},
				{1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1},
				{1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,0,1},
				{1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,0,1},
				{1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1},
				{1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1},
				{1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,3,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}
			};





			
			//variables used from the structure that was created above.

			enemy hitter;
			hitter.health = 20;
			hitter.x = 18;
			hitter.y = 12;
			hitter.damage = rand() % 20 + 1;

			enemy wraith;
			wraith.health = 40;
				wraith.x = 1;
			wraith.y = 9;
			wraith.damage = rand() % 30 + 1;

		
			trap spikes;
			spikes.damage = 10;
			spikes.x = 38;
			spikes.y = 12;


			dungeonKeeper Boss;   
			Boss.health = 20;
			Boss.x = 38;
			Boss.y = 16;
			Boss.damage = 10;

			finalBoss final;
			final.health = 400 + rand() % 150;
			final.x = 0;
			final.y = 1;
			final.damage = 50;
			final.defense = 14;




			minos minotaur;
			minotaur.health = 800 + rand() % 150;
			minotaur.x = 9;
			minotaur.y = 1;
			minotaur.damage = 70;
			minotaur.defense = 20;




			char key = 0;
			while (key != 'q') {


				//this will print the map
				if (hero_win = true) {
					for (int y = 0; y < 20; y++) {
						cout << endl;

						for (int x = 0; x < 40; x++) {
							if (x == player.x && y == player.y) {
								cout << char(2);
							}

							else if (maze[y][x] == 1) {
								cout << (unsigned char)'#';
							}

							else if (maze[y][x] == 0) {
								cout << (unsigned char)' ';
							}
							else if (maze[y][x] == 2) {
								cout << (unsigned char)'M';
							}
							else if (maze[y][x] == 3) {
								cout << (unsigned char)'B';
							}
							else if (maze[y][x] == 4) {
								cout << (unsigned char)'E';
							}
							else if (maze[y][x] == 5) {
								cout << (unsigned char)'T';
							}
							hero_win = false;
						}

					}
				}

				cout << endl;

				
				// this  moves the player
				cout << "players health is: " << player.health << endl;
				cout << "players damage is: " << player.damage << endl;
				cout << "players defense is: " << player.defense << endl;
				cout << "players magic is: " << player.magic << endl;
			
				cout << "  To move use w,a,s,d keys" << endl;


				cin >> key;
				if (key == 's' && player.y < 19 && maze[player.y + 1][player.x] != 1) {
					player.y++; system("cls");
				}
				if (key == 'w' && player.y > 0 && maze[player.y - 1][player.x] != 1) {
					player.y--; system("cls");
				}
				if (key == 'a' && player.y > 0 && maze[player.y][player.x - 1] != 1) {
					player.x--; system("cls");
				}
				if (key == 'd' && player.y < 39 && maze[player.y][player.x + 1] != 1) {
					player.x++; system("cls");
				}
				//if statements are used for the player to cast magic
				if (key == 'h') {
					player.health = player.health + 25;
					player.magic = player.magic - 10;
					cout << "You cast heal and regain health "  << endl;
					
				}

				else if (player.magic <= 0) {  
					cout << "you have no more magic to cast" << endl;
				}

				if (key == 'j') {
					player.defense = player.defense + 10;
					player.magic = player.magic - 40;
					cout << "You cast armor up+ " << endl;

				}

				else if (player.magic <= 0) {
					cout << "youhave no magic to cast" << endl;
				}

				if (key == 'n') {
					player.damage = player.damage + 10;
					player.magic = player.magic - 40;
					cout << "You cast damage up+ " << endl;

				}

				else if (player.magic <= 0) {
					cout << "you have no magic to cast" << endl;
				}


				



				if (maze[player.y][player.x] == 4) {
					cout << "Player exits the dungeon" << endl;
					system("pause");
					exit(1);

				}
				string fight = "";

				if (player.x == 18 + 1 && player.y == 12) {
					cout << "Type fight to fight or resign" << endl;
					for (hitter.health = 20; hitter.health > 0; hitter.health) {
						cin >> fight;
						if (fight == "Fight" || fight == "fight") {
							hitter.health = hitter.health - player.damage;
							cout << "hitters mob health: " << hitter.health << endl;

							if (hitter.health <= 0) {
								cout << "The enemy is dead. You continue on." << endl;
								hero_win = true;

							}

							if (hitter.health > 0) {
								player.health = player.health + player.defense - hitter.damage;
								cout << "players health: " << player.health << endl;
								fight = "";
								hero_win = false;
							}
						}
						else if (fight == "Resign" || fight == "resign") {
							cout << "You lose the game" << endl;
							system("pause");
						}
					}
				}
				//for Boss


				
				if (player.x == 38 && player.y == 16 + 1) {
					cout << "Type fight to fight or resign to quit" << endl;
					for (Boss.health = 200; Boss.health > 0; Boss.health) {
						cin >> fight;
						if (fight == "Fight" || fight == "fight") {
							Boss.health = Boss.health - player.damage;
							cout << "warrior's health: " << Boss.health << endl;

							if (Boss.health <= 0) {
								cout << "The warrior is dead. The way is clear" << endl;
								hero_win = true;

							}//need to change

							if (player.health == 0) {
								cout << "You died" << endl;
								system("pause");
							}
							
							if (Boss.health > 0) {
								player.health = player.health + player.defense - Boss.damage;
								cout << "players health: " << player.health << endl;
								fight = "";
								hero_win = false;
							}
						}
						

					}
				}



				string fightWraith = "";

				if (player.x == 38 && player.y == 13 + 1) {
					cout << "Type fight to fight or resign" << endl;
					for (wraith.health = 20; wraith.health > 0; wraith.health) {
						cin >> fightWraith;
						if (fightWraith == "Fight" || fightWraith == "fight") {
							wraith.health = wraith.health - player.damage;
							cout << "Wraith mob health: " << wraith.health << endl;

							if (wraith.health <= 0) {
								cout << "The enemy is dead. You continue on." << endl;
								hero_win = true;

							}

							if (wraith.health > 0) {
								player.health = player.health + player.defense - wraith.damage;
								cout << "players health: " << player.health << endl;
								fight = "";
								hero_win = false;
							}
						}
						else if (fight == "Resign" || fight == "resign") {
							cout << "You lose the game" << endl;
							system("pause");
						}
					}
				}

		

				if (player.x == 0  && player.y == 1+1) {
					cout << "The dungeon Boss sees you stands from his throne and challenges you" << endl;
					cout << "Defend yourself!" << endl;
					cout << "Type fight to fight or Die" << endl;
					for (final.health = 400; final.health > 0; final.health) {
						cin >> fight;
						if (fight == "Fight" || fight == "fight") {
							final.health = final.health + final.defense - player.damage;
							cout << "Dungeon Boss: " << final.health << endl;

							if (final.health <= 0) {
								cout << "The Dungeon master is slain. The exit is open." << endl;
								hero_win = true;

							}

							if (final.health > 0) {
								player.health = player.health + player.defense - final.damage;
								cout << "players health: " << player.health << endl;
								fight = "";
								hero_win = false;
							}
						}
						else if (fight == "Die" || fight == "die") {
							cout << "You lose the game" << endl;
							system("pause");
							PrintMenu();
						}
					}
				}




				

				if (player.x == 38 && player.y == 12 + 1) {
					cout << "You stepped on spikes" << endl;


					player.health = player.health - spikes.damage;
					cout << "Trap damage: " << spikes.damage << endl;

					if (player.health > 0) {
						cout << "You get back on your feet and continue on" << endl;
						hero_win = true;

					}


				}

				if (player.x == 38 && player.y == 11 + 1) {
					cout << "You stepped on spikes" << endl;


					player.health = player.health - spikes.damage;
					cout << "Trap damage: " << spikes.damage << endl;

					if (player.health > 0) {
						cout << "You get back on your feet and continue on" << endl;
						hero_win = true;

					}


				}


				if (player.x == 38 && player.y == 10 + 1) {
					cout << "You stepped on spikes" << endl;


					player.health = player.health - spikes.damage;
					cout << "Trap damage: " << spikes.damage << endl;

					if (player.health > 0) {
						cout << "You get back on your feet and continue on" << endl;
						hero_win = true;

					}


				}
				else if (player.health <= 0) {
					cout << "You lose the game" << endl;
					system("pause");
				}
			

				if (player.x == 12 && player.y == 12) {
					player.damage = player.damage + 15;
					cout << "You find a better weapon and replace it with your old one" << endl;


				}

				string open = "";

				if (player.x == 34 && player.y == 10) {
					player.defense = player.defense + 15;
					cout << "You find a chest, Open it?" << endl;

					cout << "Type open to open or leave it alone" << endl;




					cin >> open;
					if (open == "open") {
						cout << "You opened the chest and find some old armor. You throw away your leather armor." << endl;
						player.defense = player.defense + 20;
					}
					string leaveIt = "";
					cin >> leaveIt;
					if (leaveIt == "leave it") {

						cout << "You decide to leave the chest alone" << endl;


					}
				}



				string take = "";

				if (player.x == 13 && player.y == 8) {
					
					cout << "You find a sword take it?" << endl;

					cout << "Type take to take or type leaveIt leave it alone" << endl;




					cin >> take;
					if (take == "take") {
						cout << "You grabbed the sword and triggered the trap \n" << endl;
						cout << "You attempt to dodge the trap\n" << endl;
						cout << "Roll the dice if its more than 5 you dodge the trap " << endl;

						const int min = 1;
						const int max = 6;


						int die1;
						int die2;
						int total = die1 + die2;

						unsigned seed = time(0);

						// random generator
						srand(seed);

						

						//this rolls a dice when the user wants to pick kup the sword

						cout << "Rolls dice\n";
						die1 = (rand() % (max - min + 1)) + min;
						die2 = (rand() % (max - min + 1)) + min;
						cout << "You rolled a " << die1 << " and " << die2 << endl;
						cout << "Your total is: " << (die1 + die2);


						if (total <= 6);
						{

							cout << "The trap is triggered and your clothes catch on fire " << endl;
							player.health = player.health - 100;
							player.defense = player.defense - player.defense;
						}
					
					}
					string leaveIt = "";
					cin >> leaveIt;
					if (leaveIt == "leave it") {

						cout << "You decide to leave it alone" << endl;


					}
				}

				if (player.x == 9 && player.y == 1) {
					cout << "A minotaur stands guard at the exit\n. The beast sees you and charges before you have time to respond\n. You cannot run from the fight" << endl;
					cout << "Defend yourself!" << endl;
					cout << "Type fight to fight or Die" << endl;
					for (minotaur.health = 800; minotaur.health > 0; minotaur.health) {
						cin >> fight;
						if (fight == "Fight" || fight == "fight") {
							minotaur.health = minotaur.health + minotaur.defense - player.damage;
							cout << "Dungeon Boss: " << minotaur.health << endl;

							if (minotaur.health <= 0) {
								cout << "The Minotaur is dead. The exit is open." << endl;
								hero_win = true;

							}

							if (minotaur.health > 0) {
								player.health = player.health + player.defense - minotaur.damage;
								cout << "players health: " << player.health << endl;
								fight = "";
								hero_win = false;
							}
						}
						else if (fight == "Die" || fight == "die") {
							cout << "You lose the game" << endl;
							system("pause");
							PrintMenu();
						}
					}
				}

			

				

						if (choice == 2) {
							


						}

						else if (choice == 3) {





						}







						else if (choice == 4) {
							quit = true;
						}
					

				}


			}
		}
	}
		