#include "DoodleBug.h"
#include <iostream>
#include <string>
using namespace std;

void DoodleBug::starve(std::vector<std::vector<Organism*>> &grid)
{
	if (hunger == 3)
	{
		grid[getY()][getX()] = new Organism();
	}
}

void DoodleBug::move(std::vector<std::vector<Organism*>>& grid)
{
	pair<int, int> coords = findAdjacent(grid, "Ant");
	// Use same movement as ant
	if (coords.first == getY() && coords.second == getX())
	{
		pair<int, int> coords2 = findAdjacentEmpty(grid);
		swap(grid[getY()][getX()], grid[coords2.first][coords2.second]);
		setPosition(coords2.first, coords2.second);
	}
	// If there is an adjacent ant, eat it
	else
	{
		int oldX = getX();
		int oldY = getY();

		swap(grid[getY()][getX()], grid[coords.first][coords.second]);
		setPosition(coords.first, coords.second);

		delete grid[oldY][oldX];
		grid[oldY][oldX] = 0;
		hunger = -1; // -1 instead of 0 because hunger is called right after this anyway
	}
	hunger++;
	setLifeTime(getLifeTime() + 1);
	breed(grid);
	setFlag(true);
	starve(grid);
}

void DoodleBug::breed(std::vector<std::vector<Organism*>>& grid)
{
	if (getLifeTime() == 8)
	{
		pair<int, int> coords = findAdjacentEmpty(grid);
		// Do not breed
		if (coords.first == getY() && coords.second == getX())
		{
			// Do nothing
		}
		// Empty space found, breeding allowed
		else
		{
			grid[coords.first][coords.second] = new DoodleBug(coords.first, coords.second);
		}
		setLifeTime(0);
	}
}

std::string DoodleBug::getType()
{
	return "DoodleBug";
}
