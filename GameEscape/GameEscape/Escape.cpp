#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib> 
#include <fstream>
#include <time.h> 

using namespace std;

const int WIDTH = 10, HEIGHT = 10; //Dimensions of the map.
int choice; // Users input during the menu

class World
{
	int ExitY = 9;
	int ExitX = 9;

	int PlayerY = 8;
	int PlayerX = 1;

	int Enemy1Y = 4;
	int Enemy1X = 5;

	int Enemy2Y = 6;
	int Enemy2X = 6;

	int counter = 0;
	int counter2 = 0;

	bool gameRun = true;

	int map[HEIGHT][WIDTH] = {
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 4, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 2, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 2, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 1, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	}; //Map of the game.

public:

	void moveUp()
	{
		if (map[PlayerY - 1][PlayerX] == 0) {
			map[PlayerY][PlayerX] = 0;
			PlayerY--;
			map[PlayerY][PlayerX] = 1;
		}
	}

	void moveDown()
	{
		if (map[PlayerY + 1][PlayerX] == 0) {
			map[PlayerY][PlayerX] = 0;
			PlayerY++;
			map[PlayerY][PlayerX] = 1;
		}
	}

	void moveLeft()
	{
		if (map[PlayerY][PlayerX - 1] == 0) {
			map[PlayerY][PlayerX] = 0;
			PlayerX--;
			map[PlayerY][PlayerX] = 1;
		}
	}

	void moveRight()
	{
		if (map[PlayerY][PlayerX + 1] == 0) {
			map[PlayerY][PlayerX] = 0;
			PlayerX++;
			map[PlayerY][PlayerX] = 1;
		}
	}

	void enemy() //Everytime the player moves, the enemy will also move in a random direction.
	{
		if (counter == 0)
		{
			int choice = rand() % 4;
			switch (choice)
			{
			case 0://move up
				if (map[Enemy1Y - 1][Enemy1X] == 0 && 2) {
					map[Enemy1Y][Enemy1X] = 0;
					Enemy1Y--;
					map[Enemy1Y][Enemy1X] = 2;
				}
				break;
			case 1://move down
				if (map[Enemy1Y + 1][Enemy1X] == 0 && 2) {
					map[Enemy1Y][Enemy1X] = 0;
					Enemy1Y++;
					map[Enemy1Y][Enemy1X] = 2;
				}
				break;
			case 2:// move left
				if (map[Enemy1Y][Enemy1X - 1] == 0 && 2) {
					map[Enemy1Y][Enemy1X] = 0;
					Enemy1X--;
					map[Enemy1Y][Enemy1X] = 2;
				}
				break;
			case 3://move right
				if (map[Enemy1Y][Enemy1X + 1] == 0 && 2) {
					map[Enemy1Y][Enemy1X] = 0;
					Enemy1X++;
					map[Enemy1Y][Enemy1X] = 2;
				}
				break;
			}
		}
		if (counter2 == 0)
		{
			int choice = rand() % 4;
			switch (choice)
			{
			case 0://move up
				if (map[Enemy2Y - 1][Enemy2X] == 0 && 2) {
					map[Enemy2Y][Enemy2X] = 0;
					Enemy2Y--;
					map[Enemy2Y][Enemy2X] = 2;
				}
				break;
			case 1://move down
				if (map[Enemy2Y + 1][Enemy2X] == 0 && 2) {
					map[Enemy2Y][Enemy2X] = 0;
					Enemy2Y++;
					map[Enemy2Y][Enemy2X] = 2;
				}
				break;
			case 2:// move left
				if (map[Enemy2Y][Enemy2X - 1] == 0 && 2) {
					map[Enemy2Y][Enemy2X] = 0;
					Enemy2X--;
					map[Enemy2Y][Enemy2X] = 2;
				}
				break;
			case 3://move right
				if (map[Enemy2Y][Enemy2X + 1] == 0 && 2) {
					map[Enemy2Y][Enemy2X] = 0;
					Enemy2X++;
					map[Enemy2Y][Enemy2X] = 2;
				}
				break;
			}
		}
	}

	void draw()
	{
		while (gameRun == true) {
			system("cls");
			cout << "-----------------------" << endl;
			for (int y = 0; y < HEIGHT; y++) {
				for (int x = 0; x < WIDTH; x++) {
					if (map[y][x] == 0) {
						cout << ". "; // Changes the number "0" into "."- Board
					}
					else if (map[y][x] == 1) {
						cout << "C "; // Changes the number "1" into "+"- Player
					}
					else if (map[y][x] == 2) {
						cout << "V "; // Changes the number "2" into "Y"- Enemies
					}
					else if (map[y][x] == 3) {
						cout << "+ "; // Changes the number "3" into "#"- Boarder
					}
					else if (map[y][x] == 4) {
						cout << "O "; // Changes the number "4" into "O"- Exit
					}
				}
				cout << endl;
			}
			cout << endl;
			cout << "-----------------------" << endl;
			system("PAUSE");
			if (GetAsyncKeyState(VK_UP)) {
				moveUp();
				enemy();
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				moveDown();
				enemy();
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				moveLeft();
				enemy();
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				moveRight();
				enemy();
			}
		}
	}
};

class Rules
{
public:
	void GameRule()
	{
		system("CLS");
		cout << "------RULES------" << endl;
		cout << "1) Stay away from the enemies." << endl;
		cout << "2) Reach the exit without getting caught." << endl;
		cout << "------Press '0' to return to the menu------" << endl;
		cin >> choice;
		system("PAUSE");
	}

};

int main()
{
	srand(time(0));
	cout << "------MENU------" << endl;
	cout << "1) Start New Game" << endl;
	cout << "2) Rules" << endl;
	cout << "3) Load game" << endl;
	cout << "4) Quit game" << endl;
	cin >> choice;

	if (choice == 1) //Starts a new game
	{
		system("CLS"); // "CLS" clears the page so that the contents of the page do not interfere with the previous page.
		while (1) // Loops the game.
		{
			World world;
			world.draw();
		}
		system("PAUSE");
	}
	else if (choice == 2) //Rules page
	{
		Rules rule;
		rule.GameRule();

		if (choice == 0)
		{
			system("CLS");
			main();
		}
	}
	else if (choice == 3) // Loads game
	{
		system("CLS");
		cout << "Loading game..." << endl;
		system("PAUSE");
	}
	else if (choice == 4)
	{
		exit(0);
	}
	else {	//Quit game
		cout << "Option not found! Try again:";
		cout << endl;
		system("PAUSE");
	}
}