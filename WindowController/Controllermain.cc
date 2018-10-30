/* 
   main.cc  -- Program to test windowBuffer

   Author: Vatsal Patel

   Modification History
   Date        Action
   09/30/18  -- Original version

   ID code: 5ARc4N3ihjpc.
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "lab2.cc"

void check (string msg, bool cond) {
   cout << msg << ": ";
   if (cond) 
      cout << "ok";
   else
      cout << "failed!";
   cout << endl; 
}

int main () {
   // Create window buffers
   WindowBuffer wb1;
   WindowBuffer wb2(10,30);
   string msg; 

   // test 1 : check number of cols and rows.
   msg = "Test 1: After initializing a window buffer the row should be 1 and col 0";;
   check(msg, wb1.rowNumber() == 0  && wb1.colNumber() == 0); 
   check(msg, wb2.rowNumber() == 0  && wb2.colNumber() == 0);
  
   // test 1a: testing each row has x number of cols.
   for(int r = 0; r < wb2.numberOfRows() and r < wb2.numberOfCols(); ++r){
	check("test 1a: each row should have 20 chars", wb2.numberOfCols() == 30);
   }
   
   msg = "Test 1c: After initializing an empty window buffer number of rows = 1, number of cols =0";;
   check(msg, wb1.numberOfRows() == 1  && wb1.colNumber() == 0); 
   
   // test 2: after moving to (x,y), the row should be x and col y;
   msg = "Test 2: After moveto (5,7) the row = 5 and col = 7";;
   wb1.moveTo(5,7);
   wb2.moveTo(5,7);
   check(msg, wb1.rowNumber() == 5  && wb1.colNumber() == 7); 
   check(msg, wb2.rowNumber() == 5  && wb2.colNumber() == 7); 

   // You need to test the other operations in a similar fashion
   // ...
   
   // test 3: adding a string in (x,y) of z lenght the row should x and col should be y+z;
   msg = "Test 3: After writing a string of length 5 at (3,7), row = 3, col = 12";
   wb1.moveTo(3,7); wb1.write("doggy");
   wb2.moveTo(3,7); wb2.write("puppy");
   check (msg, wb1.rowNumber() == 3  && wb1.colNumber() == 12); 
   check (msg, wb2.rowNumber() == 3  && wb1.colNumber() == 12); 

   // test4
   msg = "Test 4: After inserting a string of length 5 at (3,7), row = 3, col = 12";
   check (msg, wb1.rowNumber() == 3  && wb1.colNumber() == 12); 
   check (msg, wb2.rowNumber() == 3  && wb1.colNumber() == 12); 

   // test 5
   msg = "Test 5: After inserting \"abcde\" at (4,9), row should be \"         abcde\"";
   wb1.moveTo(4,9);
   wb1.insert("abcde");
   check (msg, wb1.getRow() == "         abcde");

   // test 5a
   msg = "Test 5a: erase from (4,9) to the end of the string";
   wb1.delToEoln();
   check (msg, wb1.getRow() == "");

   
   // You should include additional tests to check other operations.
   // You know your instructor will!

   // test 6
   msg = "Test 6: insert at (2,2) and erase all the string";
   wb1.moveTo(2,2);
   wb1.insert("this is a test!");
   check(msg, wb1.getRow() == "  this is a test!");
   wb1.delToEoln();
   check(msg, wb1.getRow() == "");

   // test 6a
   msg = "Test 6a: insert at (1,1) and replace with spaces";
   wb1.moveTo(1,0);
   wb1.insert("can't be broken");
   check(msg, wb1.getRow() == "can't be broken");
   wb1.clearToEoln();
   check(msg, wb1.getRow() == "               ");

   // test 7
   msg = "Test 7: clear all lines in w2";
   wb2.moveTo(0,0);
   wb2.clear();
   for(int n = 0; n < wb2.numberOfRows(); ++n){
      check(msg, wb2.getRow() == "                              ");
   }

   // test 8
   msg = "Test 8: delete the current row";
   wb1.moveTo(2,2);
   wb1.insert("Hello");
   wb1.delRow();
   check(msg, wb1.rowNumber() == 3 && wb1.colNumber() == 0);
   wb1.moveTo(2,0);
   cout << wb1.getRow();
   check(msg, wb1.getRow() == "");

   // test 9
   msg = "Test 9: Insert a row before 4 saying hello";
   wb1.moveTo(7,0);
   wb1.insert("world");
   wb1.insertRow("hello");
   check(msg, wb1.getRow() == "hello");
   wb1.moveTo(6,0);
   check(msg, wb1.getRow() == "world");
/*
   // wb2 has 30 col so keep that in mind when checking!
   msg = "test 7: check wb2";
   wb2.moveTo(6,6);
   wb2.insert("this is a test!");
   cout << wb2.getRow();
   check(msg, wb2.getRow() == "     this is a test!");
i   wb2.delToEoln();
   check(msg, wb2.getRow() == "");
*/
   return 0;

}
