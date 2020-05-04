#include "automaton.h"
#include <ncurses.h>	
#include <iostream>		//Cout
#include "dieRoll.h" 		//d4
using namespace std;

void myPrint(vector<bool> vb){
	
	cout << '.';
	for (bool b : vb){
		cout << b ? '1' : '0';
		cout << '.';
	}
	cout << endl;
}

void duplicateLine(WINDOW* w, int to, int from){

}

void printAutomaton(Automaton& a){
	char c;
	for (int i = 0; i < a.getSize(); i++){
		c = a.read(i) ? 'x' : ' ';
		addch(c);
	}
}

int main(){

	char input = ' ';
	cout << "Rule: ";
	int rule;
	cin >> rule; 

	//Init ncurses
	initscr(); cbreak(); noecho();
	scrollok(stdscr, true);
		Automaton autocell(rule, COLS);
	
	cout << "Press R for random configuration" << endl;
	cin >> input;
	if (input == 'r' || input == 'R'){
		vector<bool> initialConfig(COLS);
		for (int i=0; i<COLS; i++)
			initialConfig[i] = bool(d4.roll()%2);
		
			autocell = Automaton(rule, initialConfig);
	}


	move(LINES-1, 0);

	bool noPause = false;
	while (input != 'q'){
		if (input == 'p' ) noPause = !noPause;
		nodelay(stdscr, noPause);
		refresh();
		


		printAutomaton(autocell);
		autocell.tick();
		input = getch();
	}
	endwin();
	
	myPrint(autocell.getRule());	

	//for (int i = 0; i < 10; i++){
	//	myPrint(autocell.getConfig());
	//	autocell.tick();
	//}
	

	
	return 0;
}
