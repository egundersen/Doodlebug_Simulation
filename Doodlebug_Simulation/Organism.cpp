#include "Organism.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Organism::move(vector<vector<Organism*>> &grid)
{
	pair<int, int> coords = findAdjacentEmpty(grid);
	swap(grid[getY()][getX()], grid[coords.first][coords.second]);
	setPosition(coords.first, coords.second);

	// TODO: This is a good place to call 3 functions, Starve, Breed, and setFlag(true)
	// * Ant breeds at LifeTime == 3
	// * Ant can ONLY breed if adjacent cells are empty
	// * Breeding resets LifeTime to 0
	// * Ants CANNOT kill themselves. The doodlebugs eat them. 
	//   So don't worry about removing ants, because the
	//   Doodle bug code does that already.

	// * TIP: this loop may move the same ant twice!
	//   To prevent this, try setting the flag to true (shown below)
	//   This will prevent the ant from being moved again until the next frame
}

void Organism::breed(std::vector<std::vector<Organism*>> &grid)
{
}

void Organism::setPosition(int i_pos1, int i_pos2)
{
	pos1 = i_pos1;
	pos2 = i_pos2;
}

void Organism::setLifeTime(int i_lifeTime)
{
	lifeTime = i_lifeTime;
}

void Organism::setFlag(bool i_flag)
{
	flagged = i_flag;
}

bool Organism::getFlag()
{
	return flagged;
}

int Organism::getX()
{
	return pos2;
}

int Organism::getY()
{
	return pos1;
}

int Organism::getLifeTime()
{
	return lifeTime;
}

std::string Organism::getType()
{
	return "Empty";
}

pair<int, int> Organism::findAdjacent(vector<vector<Organism*>>& grid, string type)
{
	srand(time(0));
	vector<pair<int, int>> acceptablePositions;
	if (pos1 != 0)
	{
		if (pos2 != 0)
		{
			if (grid[pos1 - 1][pos2 - 1] != NULL)
				if (grid[pos1 - 1][pos2 - 1]->getType() == type)
					acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2 - 1));
		}
		if (grid[pos1 - 1][pos2] != NULL)
			if (grid[pos1 - 1][pos2]->getType() == type)
				acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2));
		if (pos2 != grid.size() - 1)
		{
			if (grid[pos1 - 1][pos2 + 1] != NULL)
				if (grid[pos1 - 1][pos2 + 1]->getType() == type)
					acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2 + 1));
		}
	}
	if (pos2 != grid.size() - 1)
	{
		if (grid[pos1][pos2 + 1] != NULL)
			if (grid[pos1][pos2 + 1]->getType() == type)
				acceptablePositions.push_back(pair<int, int>(pos1, pos2 + 1));
	}
	if (pos1 != grid.size() - 1)
	{
		if (pos2 != grid.size() - 1)
		{
			if (grid[pos1 + 1][pos2 + 1] != NULL)
				if (grid[pos1 + 1][pos2 + 1]->getType() == type)
					acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2 + 1));
		}
		if (grid[pos1 + 1][pos2] != NULL)
			if (grid[pos1 + 1][pos2]->getType() == type)
				acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2));
		if (pos2 != 0)
		{
			if (grid[pos1 + 1][pos2 - 1] != NULL)
				if (grid[pos1 + 1][pos2 - 1]->getType() == type)
					acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2 - 1));
		}
	}
	if (pos2 != 0)
	{
		if (grid[pos1][pos2 - 1] != NULL)
			if (grid[pos1][pos2 - 1]->getType() == type)
				acceptablePositions.push_back(pair<int, int>(pos1, pos2 - 1));
	}

	if (acceptablePositions.size() > 0)
	{
		return acceptablePositions.at(rand() % acceptablePositions.size());
	}
	else
	{
		return pair<int, int>(pos1, pos2);
	}
}

std::pair<int, int> Organism::findAdjacentEmpty(std::vector<std::vector<Organism*>>& grid)
{
	srand(time(0));
	vector<pair<int, int>> acceptablePositions;
	if (pos1 != 0)
	{
		if (pos2 != 0)
		{
			if (grid[pos1 - 1][pos2 - 1] == NULL)
				acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2 - 1));
		}
		if (grid[pos1 - 1][pos2] == NULL)
			acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2));
		if (pos2 != grid.size() - 1)
		{
			if (grid[pos1 - 1][pos2 + 1] == NULL)
				acceptablePositions.push_back(pair<int, int>(pos1 - 1, pos2 + 1));
		}
	}
	if (pos2 != grid.size() - 1)
	{
		if (grid[pos1][pos2 + 1] == NULL)
			acceptablePositions.push_back(pair<int, int>(pos1, pos2 + 1));
	}
	if (pos1 != grid.size() - 1)
	{
		if (pos2 != grid.size() - 1)
		{
			if (grid[pos1 + 1][pos2 + 1] == NULL)
				acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2 + 1));
		}
		if (grid[pos1 + 1][pos2] == NULL)
			acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2));
		if (pos2 != 0)
		{
			if (grid[pos1 + 1][pos2 - 1] == NULL)
				acceptablePositions.push_back(pair<int, int>(pos1 + 1, pos2 - 1));
		}
	}
	if (pos2 != 0)
	{
		if (grid[pos1][pos2 - 1] == NULL)
			acceptablePositions.push_back(pair<int, int>(pos1, pos2 - 1));
	}

	if (acceptablePositions.size() > 0)
	{
		return acceptablePositions.at(rand() % acceptablePositions.size());
	}
	else
	{
		return pair<int, int>(pos1, pos2);
	}
}
