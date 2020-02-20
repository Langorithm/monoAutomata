#include<vector>

class automaton{
	public:
		bool read(int cell);
		
		void tick();

		automaton(int size);

	private:
		vector<bool> cellConfig;

};
