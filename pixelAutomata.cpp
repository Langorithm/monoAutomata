#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "automaton.h"

class Automat : public olc::PixelGameEngine
{

public:

	Automat() : _autocell(Automaton(10,10))
	{
	
	}

	bool OnUserCreate() override
	{
		_autocell = Automaton(110, ScreenWidth());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);
		int i = ScreenHeight()-1;
		//print every line
		for (auto line : _lines)
		{
			_printLine(line, i);
			i--;
		}
		//update configuration
		_autocell.tick();
		
		//add new config to queue
		_lines.push_front(_autocell.getConfig());
		
		//remove oldest config from queue
		if (_lines.size() >= ScreenHeight() )
			_lines.pop_back();
			
		return true;
	}


private:
	
	list< vector<bool> > _lines;
	
	void _printLine(vector<bool> line, int screenLine)
	{
		for (int i = 0; i<line.size(); i++)
		{
			if (line[i])
				Draw(i, screenLine, olc::WHITE);
		}
	}

	Automaton _autocell;
};


int main()
{
	Automat mata;
	if (mata.Construct(800, 350, 2, 2))
		mata.Start();

	return 0;
}
