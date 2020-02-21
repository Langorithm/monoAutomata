#include<vector>
using namespace std;

class Automaton{
	public:
		Automaton(int rule, int size);
		
		vector<bool> getRule() const ;
		int getSize() const ;
		bool read(int cell) const;
		
		void tick();
		vector<bool> getConfig() const;
	private:
		vector<bool> _cellConfig;
		vector<bool> _rule;
		
		bool _evolve(int cell, vector<bool>& previous) const;
};
