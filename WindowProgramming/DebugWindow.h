/* 
   DebugWindow.h  -- Program to set up class which will write to debug window.

   Author: Vatsal Patel

   Modification History
   Date        Action
   10/15/18  -- Original version
*/
#ifndef DEBUG_WINDOW
#define DEBUG_WINDOW
#include <ncurses.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class DebugWindow{
 private:
    WINDOW *debug;
    string contents;
    bool dodebug;

 public:
    //Creates a Debug window at the bottom of the screen
    DebugWindow(){
      contents = "Debug: ";
      int r,c;
      getmaxyx(stdscr, r, c);
      debug = newwin(1,c,r-1,0); // creates a window of size 1 row and c cols at pos r-1,0.
      waddstr(debug, contents.c_str());
      wrefresh(debug);
    }

    //Turn debugging off
    bool off() {
       dodebug = false;
       return false;
    }

    //Turn debugging on
    bool on() {
       dodebug = true;
       return true;
    }

    // Print a string to the debug window
    void write(string s){
       waddstr(debug, s.c_str());
       wrefresh(debug);
    }

    // Print a character to the debug window
    void write (char ch) {
       waddch(debug, ch);
       wrefresh(debug);
    }

    // Print an integer to the debug window
    void write (int n) {
       string s = to_string(n);
       waddstr(debug, s.c_str());
       wrefresh(debug);
    }

    // Print a string followed by an integer to the debug window
    void write(string s, int n) {
      waddstr(debug,s.c_str());
      string a = to_string(n);
      waddstr(debug,a.c_str());
      wrefresh(debug);
    }

    // Clear the debug window
    void clear() {
      contents = "Debug: ";
      wmove(debug, 0, 0); // move to (0,0) of DebugWindow
      wclrtoeol(debug); // Clear the entire line.
      waddstr(debug, contents.c_str()); // rewrite the Debug: to the window.
      wrefresh(debug);
    }

    // Pause the program by waiting for input
    void pause() {
      wrefresh(debug);
      wgetch(debug);
    }
};
#endif
