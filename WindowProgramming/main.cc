/* 
   main.cc  -- Program to read from command window and writing to debug window

   Author: Vatsal Patel

   Modification History
   Date        Action
   10/15/18  -- Original version
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>
#include "DebugWindow.h"
#include "CommandWindow.h"

DebugWindow debugWindow;
int main () {
   initscr();
   cbreak();
   debugWindow = DebugWindow();
   debugWindow.on();

   CommandWindow commandWindow =  CommandWindow();
   string command = commandWindow.readString();
   while( !(command == "q" or command == "Q")) {
      debugWindow.write(command);
      commandWindow.clear();
      command = commandWindow.readString();
      debugWindow.clear();
   }
   endwin();
}

