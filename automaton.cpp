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
	
	vector<int> ruleDigits = digitize(decToBin(rule));
	printVector(ruleDigits);
	
	_rule = vector<bool>(8-ruleDigits.size(),false);
	for (int elem : ruleDigits)
		_rule.push_back(elem);	
	
	
	
}

Automaton::Automaton(int rule, vector<bool> initialConfig){
	_cellConfig = initialConfig;

	//Defend against invalid rule codes
	if (0 > rule || rule > 255)
		rule = 0;

	//Transform decimal rule code to a more confortable vector form
	
	vector<int> ruleDigits = digitize(decToBin(rule));
	printVector(ruleDigits);
	
	_rule = vector<bool>(8-ruleDigits.size(),false);
	for (int elem : ruleDigits)
		_rule.push_back(elem);	
	


}

vector<bool> Automaton::getRule() const {
	return _rule;
}

vector<bool> Automaton::getConfig() const {
	return _cellConfig;
}
int Automaton::getSize() const {
	return _cellConfig.size();
}

bool Automaton::read(int cell) const {
	return _cellConfig[cell];
}


bool Automaton::_evolve(int cell, vector<bool>& previous) const {
	int size = _cellConfig.size();
	int center = cell;
	int left = center - 1; left += size; left %= size;
	int rite = center + 1; rite += size; rite %= size;
		
	int check = previous[left] * 4 + previous[center] * 2 + previous[rite];
	//cout << check << endl;
	return _rule[7-check];
}

void Automaton::tick(){
	vector<bool> previous = _cellConfig;

	for (int i = 0; i<_cellConfig.size(); i++)
		_cellConfig[i] = _evolve(i, previous);

}

