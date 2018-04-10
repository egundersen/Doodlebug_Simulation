#ifndef ANT_H
#define ANT_H

#include "Organism.h"

class Ant : public Organism
{
public:
	Ant() {}
	Ant(int i_pos1, int i_pos2) : Organism{ i_pos1, i_pos2 } {}
	// TODO: Fill out the rest of this class
	// TIP: Both the move and breed functions could be
	// inherited from organism.
	std::string getType() override;
private:

};

#endif ANT_H