#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <vector>

class Organism
{
public:
	Organism() : pos1{ 0 }, pos2{ 0 }, flagged{ false } {}
	Organism(int i_pos1, int i_pos2) : pos1{ i_pos1 }, pos2{ i_pos2 }, flagged{ false }, lifeTime{ 0 } {}
	virtual void move(std::vector<std::vector<Organism*>> &grid);
	virtual void breed(std::vector<std::vector<Organism*>> &grid);
	void setPosition(int i_pos1, int i_pos2);
	void setLifeTime(int i_lifeTime);
	void setFlag(bool i_flag);

	bool getFlag();
	int getX();
	int getY();
	int getLifeTime();
	virtual std::string getType();
	virtual std::pair<int, int> findAdjacent(std::vector<std::vector<Organism*>> &grid, std::string type);
	virtual std::pair<int, int> findAdjacentEmpty(std::vector<std::vector<Organism*>> &grid);
private:
	int lifeTime;
	bool flagged;
	int pos1;
	int pos2;
};

#endif ORGANISM_H