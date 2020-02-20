#include<vector>

using namespace std;

class Automaton{
	public:
		Automaton(int rule, int size);
		
		int getRule() const ;
		bool read(int cell) const;
		
		void tick();

	private:
		vector<bool> _cellConfig;
		vector<bool> _rule;
};
