/* 
   TestDebugWindow.cc  -- Program to  Test the methods implemented in DebugWindow.h

   Author: Vatsal Patel

   Modification History
   Date        Action
   10/20/18  -- Original version
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>
#include "DebugWindow.h"

DebugWindow debugWindow;
int main () {
   initscr();
   cbreak();
   bool dodebug;
   string msg;
   msg = "Press Any Key to Continue";
   addstr(msg.c_str());
   refresh();
   getch();

   move(0,0);
   clear();
   refresh();

   debugWindow = DebugWindow();
   //Test dodebug()
   dodebug = debugWindow.off();
   if(dodebug == false)
   {
      addstr("The Debug Window is currently off\n");
      refresh();
   }
   else
   {
      addstr("The Debug Window is currently on\n");
      refresh();
   }
   addstr("Press enter to turn debug window on!\n");
   refresh();
   debugWindow.pause();
   dodebug = debugWindow.on();
   
   if(dodebug == true){
      addstr("Debug Window is on - Press Enter to continue");
      refresh();
      debugWindow.pause();
      //Test 1 to check write(int) method.
      clear();
      addstr("Test 1: Tests the write(int) method.\n");
      addstr("73 should appear in debug window");
      addstr("\n");
      addstr("Hit enter to see next number which should be 83");
      refresh();
      debugWindow.clear();
      debugWindow.write(73);// write 73 to debug window.
      debugWindow.pause();
      debugWindow.clear();
      debugWindow.write(83);
      addstr("\n");
      addstr("Hit enter to see the next test");
      refresh();
      debugWindow.pause();

      // Test 2 to check write(ch) method.
      clear();
      addstr("Test 2: Tests the write(ch) method.\n");
      addstr("The character 'v' should appear in debug window");
      addstr("\n");
      addstr("Hit enter to see the next character, which should be 'x'");
      refresh();
      debugWindow.clear();
      debugWindow.write('v');
      debugWindow.pause();
      debugWindow.clear();
      debugWindow.write('x');
      addstr("\n");
      addstr("Hit enter to see the next test");
      refresh();
      debugWindow.pause();

      // Test 3 check the write(string) method.
      clear();
      addstr("Test 3: Tests the write(string) method.\n");
      addstr("The string \"Hello\" should appear in debug window");
      addstr("\n");
      addstr("Hit enter to see the next string, which should be \"World\"");
      refresh();
      debugWindow.clear();
      debugWindow.write("Hello");
      debugWindow.pause();
      debugWindow.clear();
      debugWindow.write("World");   
      addstr("\n");
      addstr("Hit enter to see the next test");
      refresh();
      debugWindow.pause();

      //Test 4 check write(string, int) method.
      clear();
      addstr("Test 4: Tests the write(string,int) method.\n");
      addstr("The string \"abcde\" should appear followed by integer 2203");
      addstr("\n");
      addstr("Hit enter to see the next test, which should be string \"fghig\" followed by int 12345");
      refresh();
      debugWindow.clear();
      debugWindow.write("abcde",2203);
      debugWindow.pause();
      debugWindow.clear();
      debugWindow.write("fghig",12345);

      // end
      addstr("\n\nEnd of the Tests - Press any key to exit");
      refresh();
   }
   getch();
   endwin();
   return 0;
}

