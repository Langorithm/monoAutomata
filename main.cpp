#include "automaton.h"
#include <ncurses.h>
#include <iostream>
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
		
	//Init ncurses
	initscr(); cbreak(); noecho();
	scrollok(stdscr, true);
	Automaton autocell(110, COLS);

	char input = ' ';
	
	move(LINES-1, 0);

	while (input != 'q'){
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
