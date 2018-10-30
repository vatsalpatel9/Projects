/* 
   TestCommandWindow.cc  -- Program to  Test the methods implemented in CommandWindow.h

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
#include "CommandWindow.h"

CommandWindow commandWindow;
int main () {
   initscr();
   cbreak();

   string msg;
   msg = "Press Any Key to Continue";
   addstr(msg.c_str());
   refresh();
   getch();

   move(0,0);
   clear();
   refresh();

   commandWindow = CommandWindow();
   
   //Test 1 to check write(int) method.
   addstr("Test 1: Tests the write(int) method. \n");
   addstr("7868 should appear in command window");
   addstr("\n");
   addstr("Hit enter to see next number which should be 1234560");
   refresh();
   commandWindow.write(7868);// write 73 to debug window.
   commandWindow.pause();
   commandWindow.clear();
   commandWindow.write(1234560);

   // Test 2 to check write(ch) method.
   addstr("\n");
   addstr("Hit enter to see the next test");
   refresh();
   commandWindow.pause();
   clear();
   addstr("Test 2: Tests the write(ch) method. \n");
   addstr("The character 'g' should appear in command window");
   addstr("\n");
   addstr("Hit enter to see the next character, which should be 'm'");
   refresh();
   commandWindow.clear();
   commandWindow.write('g');
   commandWindow.pause();
   commandWindow.clear();
   commandWindow.write('m');
 
   // Test 3 check the write(string) method.
   addstr("\n");
   addstr("Hit enter to see the next test");
   refresh();
   commandWindow.pause();
   clear();
   addstr("Test 3: Tests the write(string) method.\n");
   addstr("The string \"Good\" should appear in command window");
   addstr("\n");
   addstr("Hit enter to see the next string, which should be \"Morning\"");
   refresh();
   commandWindow.clear();
   commandWindow.write("Good");
   commandWindow.pause();
   commandWindow.clear();
   commandWindow.write("Morning");
   addstr("\n");
   addstr("Hit enter to see the next test");
   refresh();
   commandWindow.pause();
   clear();

   // Test 4 Check the readInt() method.
   addstr("Test 4: Tests the readInt() method.\n");
   addstr("Enter in any integer in the command window - followed by the enter key");
   refresh();
   commandWindow.clear();
   int n = commandWindow.readInt();
   string a = to_string(n);
   addstr("\nThe integer you entered was: ");
   addstr(a.c_str());
   refresh();
   commandWindow.clear();
   addstr("\nEnter in one more integer");
   refresh();
   n = commandWindow.readInt();
   a = to_string(n);
   addstr("\nThe Integer you entered was: ");
   addstr(a.c_str());
   addstr("\nHit enter to proceed to next test");
   refresh();
   commandWindow.pause();

   // Test 5 Check the readDouble() method.
   clear();
   addstr("Test 5: Tests the readDouble() method.\n");
   addstr("Enter in any Decimal number - followed by the enter key");
   refresh();
   commandWindow.clear();
   double x = commandWindow.readDouble();
   a = to_string(x);
   addstr("\nThe decimal you entered was: ");
   addstr(a.c_str());
   refresh();
   addstr("\nEnter in any Decimal number - followed by the enter key");
   refresh();
   commandWindow.clear();
   x = commandWindow.readDouble();
   a = to_string(x); 
   addstr("\nThe decimal you entered was: ");
   addstr(a.c_str());
   addstr("\nHit Enter to proceed to next test");
   refresh();
   commandWindow.pause();

   // Test 6 Check the readString() method.
   clear();
   addstr("Test 6: Tests the readString() method.");
   addstr("\nEnter in any string - followed by the enter key");
   refresh();
   commandWindow.clear();
   a = commandWindow.readString();
   addstr("\nThe string you entered was: ");
   addstr(a.c_str());
   refresh();
   addstr("\nEnter in any string - followed by the enter key");
   refresh();
   commandWindow.clear();
   a = commandWindow.readString();
   addstr("\nThe string you entered was: ");
   addstr(a.c_str());
   refresh();

   // end
   addstr("\n\nEnd of The Test - press any key to exit");

   getch();
   endwin();
   return 0;
}

