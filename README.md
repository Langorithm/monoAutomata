# monoAutomata

This is an implementation of Wolfram's Elementary Automata.
Currently it uses ncurses to run, so before compiling you must install ncurses.

### Getting ready
Install ncurses. In ubuntu do:
    
    apt install libncurses5-dev libncursesw5-dev

Compile. There is no makefile yet, so run:

    g++ main.cpp monoAutomata.cpp -lncurses
    
---

### Controls
On running you will be asked to enter the rule [0,255] to be computed.

* **R**: Run with a **R**andom initial state (Before starting).
* **Q**: Quit
* **P**: Toggle auto-step
* Pressing any other key will advance a game 1 step
