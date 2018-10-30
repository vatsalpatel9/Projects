/* 
   lab2.cc  -- Program to  Manipulate Window Buffers

   Author: Vatsal Patel

   Modification History
   Date        Action
   09/30/18  -- Original version

   ID code: 5ARc4N3ihjpc.
*/
#include <string>
#include <vector>

using namespace std;

// WindowBuffer -- implements a multi-line buffer that can be written and read
struct WindowBuffer {

   /* Data structure for holding lines for a window */
   vector <string> buffer;
   int r, c;  // current write point

   /* Operations for manipulating a WindowBuffer */

   // WindowBuffer -- create an WindowBuffer with one empty line
   WindowBuffer () {
      buffer = vector<string>(); // create the buffer, with no strings
      moveTo(0,0);  
   }

   // WindowBuffer -- create an WindowBuffer with rows lines, each with cols spaces
   WindowBuffer (int rows, int cols) {
       buffer = vector<string>(rows);
       for(int i = 0; i < rows; ++i){
	  buffer[i] = string(cols, ' ');
       }
       r = c = 0;
   }

   // moveTo  -- Expands buffer to allow writing at (row,col)
   void moveTo(int row, int col) {
     // Set reasonable boundaries
      if (row <0) row = 0;
      if (col <0) col = 0;
      else if (row > 1000 or col > 100)  {
         // Let's be reasonable; this is only an example after all!
         row = 1000; col = 100;
      }
      r = row; c = col;
      // Ensure there is a place to move to
      while(r >=buffer.size())
         buffer.push_back("");
      while (c > buffer[r].size())
         buffer[r] += " ";
      // Upon exit r will reference an existing row,
      // c will reference a existing col or will be right after the end

   }

   // insertRow -- inserts str before the current row
   void insertRow (string str) {
      string n = buffer[r];
      buffer[r].replace(c,str.size(),str);
      int a = buffer[r].size();
      buffer[r-1].erase(c,a);
      buffer[r-1].replace(c, n.size(),n);
      c = c + str.size();
       
     
   }

   // insert -- inserts str at current (r,c) location
   void insert (string str) {
       buffer[r].insert(c,str);
      // c+= str.size();i
   } 

   // write -- overwrites str at current  (r,c) location
   void write (string str) {
      buffer[r].replace(c,str.size(),str);
      c = c + str.size();
   } 

   // clear -- remove all lines from the buffer
   void clear() {
    int q = buffer[r].size();
    for(int i = 0; i < r; ++i){
     for(int n = 0; n <= q; ++n){
       buffer[i].replace(n,q," ");
     }
    }
   }

   // clearToEoln -- remove all chars from pos (r,c) to end of line
   void clearToEoln() {
    int i = buffer[r].size();
    for(int n = 0; n < i; ++n)
      buffer[1].replace(n,i," ");
   }
   // delRow -- delete current row; r then reference next row
   void delRow() {
        if (r >= 0 and r <= buffer.size()){
           buffer[r].erase(0,buffer[r].size());
           c = 0;
           if (r >= buffer.size())    
              r = r - 1;
           moveTo(r+1,c);
       }
 
   }

   // delToEoln -- delete from current column to the end of line
   void delToEoln() {
     buffer[r].erase(0,buffer[r].size());
   }

   // getRow -- get row r
   string getRow() {
     return buffer[r];
   }

   // numberOfRows -- return the number of rows in the buffer
   int numberOfRows() {
	//returns the number of rows in buffer.
	return buffer.size();  
   }

   // numberOfCols -- return the length of the current line
   int numberOfCols() { 
	// returns the number of cols in a row.
       return buffer[r].size(); 
   }

   // rowNumber -- return the row number of the current write position
   int rowNumber() {  
      return r;
   } 

   // colNumber -- return the col number of the current write position
   int colNumber() {  
      return c;
   }
};
