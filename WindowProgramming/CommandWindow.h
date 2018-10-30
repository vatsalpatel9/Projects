/* 
   CommandWindow.h  -- Program to create command window and read and write to the window.

   Author: Vatsal Patel

   Modification History
   Date        Action
   10/15/18  -- Original version

*/
#ifndef COMMAND_WINDOW
#define COMMAND_WINDOW
#include <ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class CommandWindow{
 private:
    WINDOW *command;
    string contents;

 public:
    //Creates a Command window at the bottom of the screen
    CommandWindow(){
      contents = "Command: ";
      int r,c;
      getmaxyx(stdscr, r, c);
      command = newwin(1,c,r-2,0); // create command window of size row 1 and c cols. at pos r-2,0.
      waddstr(command, contents.c_str());
      wrefresh(command);
    }

    // append string to the command window string
    void write(string s){
      waddstr(command,s.c_str());
      wrefresh(command);
    }

    // append character to the command window string
    void write (char ch) {
       waddch(command,ch);
       wrefresh(command);
    }

    // append integer to the command window string
    void write (int n) {
       string s = to_string(n);
       waddstr(command, s.c_str());
       wrefresh(command);
    }

    // Clear the Command window
    void clear() {
       wmove(command,0,0); // Move to (0,0) of Command Window
       wclrtoeol(command); // Clear to end of the line.
       waddstr(command, contents.c_str()); // write Command: to the command window.
       wrefresh(command);
    }

    // Pause the program by waiting for input
    void pause() {
       wrefresh(command);
       wgetch(command);
    }

    // Read an integer from the command window
    int readInt() {
       char line[100];
       wgetnstr(command,line,99);
       int value = atoi(line);
       return value;
    }

    // Read a double from the command window
    double readDouble() {
       char line[100];
       wgetnstr(command,line,99);
       double value = atof(line);
       return value;
    }

    // Read a string from the command window
    string readString() {
        char line[100];
        wgetnstr(command,line,99);
        return line;
    }

};
#endif
