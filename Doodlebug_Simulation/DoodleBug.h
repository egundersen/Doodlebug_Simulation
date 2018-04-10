#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"
#include <string>
#include <vector>

class DoodleBug : public Organism
{
public:
	DoodleBug() : hunger{ 0 } {}
	DoodleBug(int i_pos1, int i_pos2) : Organism{ i_pos1, i_pos2 }, hunger{ 0 } {}
	void breed(std::vector<std::vector<Organism*>> &grid) override;
	void move(std::vector<std::vector<Organism*>> &grid) override;
	void starve(std::vector<std::vector<Organism*>> &grid);

	std::string getType() override;
private:
	int hunger;
};

#endif DOODLGEBUG_H