#include"automaton.h"


Automaton::Automaton(int rule, int size){
	//Construct the cell configuration according to size and the 'Single 1' initial state
	_cellConfig = vector(size, false);
	_cellConfig[size/2] = true;

	//Defend against invalid rule codes
	if (0 > rule || rule > 255)
		rule = 0;

	//Transform decimal rule code to a more confortable vector form
		
		
}

int Automaton::getRule() const {

}

bool Automaton::read(int cell) const {

}

void Automaton::tick(){


}

