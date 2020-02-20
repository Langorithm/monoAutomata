#include"automaton.h"
#include"langUtils.h"

Automaton::Automaton(int rule, int size){
	//Construct the cell configuration according to size and the 'Single 1' initial state
	_cellConfig = vector<bool>(size, false);
	_cellConfig[size/2] = true;

	//Defend against invalid rule codes
	if (0 > rule || rule > 255)
		rule = 0;

	//Transform decimal rule code to a more confortable vector form
	_rule = vIntTovBool(digitize(decToBin(rule)));
	while (_rule.size() < 9)	//Fill with zeroes
		_rule.push_back(0);
	
}

int Automaton::getRule() const {
	return 0;
}

bool Automaton::read(int cell) const {
	return _cellConfig[cell];
}


bool Automaton::_evolve(int cell, vector<bool>& previous) const {
	int size = _cellConfig.size();
	int center = cell;
	int left = center - 1; left += size; left %= size;
	int rite = center + 1; rite += size; rite %= size;
		
	int check = previous[left] * 100 + previous[center] * 10 + previous[rite];

	return _rule[check];
}

void Automaton::tick(){
	vector<bool> previous = _cellConfig;

	for (int i = 0; i<_cellConfig.size(); i++)
		_cellConfig[i] = _evolve(i, previous);

}

