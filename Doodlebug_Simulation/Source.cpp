//
// 4/8/2018
// 2D Predator-Prey Simulation

#include "DoodleBug.h"
#include "Ant.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
using namespace std;

void initializeSimulation(vector<vector<Organism*>> &grid, int antSize, int doodleBugSize);
void displaySimulation(vector<vector<Organism*>> &grid);
void moveSimulation(vector<vector<Organism*>> &grid);

int main()
{
	vector<vector<Organism*>> grid(20, vector <Organism*>(20));
	bool validInput = false;
	char gameChoice = ' ';
	string enter = "";

	cout << "-----------Predator-Prey Simulator-----------\nType 'm' or 'a' to select play mode\n" <<
		"'a' will allow the simulation to move itself\n'm' will require you to press enter\n";
	while (!validInput)
	{
		cin >> gameChoice;
		if (gameChoice == 'a' || gameChoice == 'm')
			validInput = true;
		else
			cout << "Please only enter a or m!\n";
	}

	initializeSimulation(grid, 100, 5);

	if (gameChoice == 'm')
	{
		for (;;) // FYI: this is an infinite loop
		{
			getline(cin, enter);
			cout << "Press enter to move simulation!--------------\n";
			displaySimulation(grid);
			moveSimulation(grid);
		}
	}
	else
	{
		for (;;)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << "---------------------------------------------\n";
			displaySimulation(grid);
			moveSimulation(grid);
		}
	}
	return 0;
}

// Initialize positions of ants and doodle bugs
void initializeSimulation(vector<vector<Organism*>> &grid, int antSize, int doodleBugSize)
{
	srand(time(0));
	for (int i = 0; i < antSize; i++)
	{
		int rand1 = rand() % 20;
		int rand2 = rand() % 20;
		if (grid[rand1][rand2] != NULL)
			i--;
		else
		{
			grid[rand1][rand2] = new Ant(rand1, rand2);
		}
	}

	for (int i = 0; i < doodleBugSize; i++)
	{
		int rand1 = rand() % 20;
		int rand2 = rand() % 20;
		if (grid[rand1][rand2] != NULL)
			i--;
		else
		{
			grid[rand1][rand2] = new DoodleBug(rand1, rand2);
		}
	}
}

// display grid of ants and doodlebugs
void displaySimulation(vector<vector<Organism*>> &grid)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] != NULL)
			{
				if (grid[i][j]->getType() == "Ant")
					cout << "X ";
				else if (grid[i][j]->getType() == "DoodleBug")
					cout << "O ";
				grid[i][j]->setFlag(false);
			}
			else
				cout << "- ";
		}
		cout << endl;
	}
	/*int count = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] == 1)
			{
				count++;
				cout << "X ";
			}
			else if (grid[i][j] == 2)
			{
				cout << "O ";
			}
			else
				cout << "- ";
		}
		cout << endl;
	}
	cout << endl;
	cout << count;//*/
}

// calls a "step", moves ants, doodle bugs, etc...
void moveSimulation(vector<vector<Organism*>> &grid)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grid[i][j] != NULL)
			{
				// Ants: What ants do every frame
				if (grid[i][j]->getType() == "Ant" && grid[i][j]->getFlag() == false)
				{
					// TODO: Fill out what the ant does

					// Notes (which may help): 
					// * A helpful move function:		grid[i][j]->move(grid);
					// * The move function will need to be inherited from the Organism class
				}
				// DoodleBugs: What doodle bugs do every frame
				else if (grid[i][j]->getType() == "DoodleBug" && grid[i][j]->getFlag() == false)
				{
					grid[i][j]->move(grid);
				}
			}
		}
	}
}