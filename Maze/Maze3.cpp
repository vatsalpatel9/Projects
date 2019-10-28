///////////////////////////////////////////////////////////////////////////////
//
//  Vatsal Patel
//
//  Description: This Program gets the maze from the user and uses loop to
//  find a path from the entry point to the exit point in the maze. Where 
//  entry point is marked with 'm' and exit point marked with 'e'. The passage 
//  is denoted by '0' and wall denoted by '1'. The path is found by going
//  visiting each row and col in a stack and marking it with '.' to show it is 
//  a passage. This file adds on the maze2 by showing the direction in the path
//  by using '-' for side ways and '|' for vertical movements.
//
//  Input: The maze pattern is optained from the user and store in a stack.
//
//  Output: The maze is outputed with the path with directions from entry to 
//  exit by '-' and '|' to denote the direction need to take.
//  
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

template <class T>
class Stack : public stack<T>{
    public:
        // modify the STL stack pop() function to return the poped value.
        T pop(){
            T tmp = stack<T>::top();
            stack<T>::pop();
            return tmp;
        }
};

// intializes the the row and column in the stack
class Cell{
    public:
        Cell(int i = 0, int j = 0){
            x = i;
            y = j;
        }
        // overload == operator to preform checks
        bool operator==(const Cell &c) const{
            return x == c.x && y == c.y;
        }

    private:
        int x, y;
        friend class Maze;
};

class Maze{
    public:
        Maze();
        void exitMaze();

    private:
        Cell currentCell, exitCell, entryCell, nextCell;
        const char exitMarker, entryMarker, visited, passage, wall; // markers
        Stack<Cell> mazeStack;
        Stack<Cell> mazePath; // Addition stack to push correct path to the exit.
        Stack<Cell> mazePathNext; // Addition stack to keep track of cell next to
                                     // the current cell.
        Stack<Cell> outputPath; // Stack used to output the path [row, col]
        char **store;
        void pushUnvisited(int, int);
        void pushDead(int, int);
        friend ostream &operator<<(ostream &, const Maze &);
        int rows, cols;
        bool work;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Maze() : exitMarker('e'), entryMarker('m'), visited('.'), 
//                     passage('0'), wall('1');
//
//  Description: This function gets the maze from the user and pushes the
//  values into the stack mazeStack. Also, outputs the instruction of creating
//  the maze.
//  
//  Preconditions: None;
//
//  Postconditions: The function terminates when user presses Ctrl-d indicating
//  user is done creating the maze;
//  
///////////////////////////////////////////////////////////////////////////////
Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1'){
    Stack<char *> mazeRows;
    char str[80], *s;
    int col, row = 0;
    cout << "Maze 3: searches path from the exit, so exit marker is necessary.\n"
         <<"Enter a rectangular maze using the following "
         << "Characters:\nm - entry\ne - exit \n1 - wall\n0 - passage\n"
         << "Enter one line at a time; end with Ctrl-d:\n";

    while (cin >> str){
        row++;
        cols = strlen(str);
        s = new char[cols + 3];

        mazeRows.push(s);
        strcpy(s + 1, str);
        s[0] = s[cols + 1] = wall;
        s[cols + 2] = '\0';
        if (strchr(s, exitMarker) != 0){
            exitCell.x = row;
            exitCell.y = strchr(s, exitMarker) - s;
        }
        if (strchr(s, entryMarker) != 0){
            entryCell.x = row;
            entryCell.y = strchr(s, entryMarker) - s;
        }
    }
    rows = row;
    store = new char *[rows + 2];
    store[0] = new char[cols + 3];
    for (; !mazeRows.empty(); row--){
        store[row] = mazeRows.pop();
    }
    store[rows + 1] = new char[cols + 3];
    store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
    for (col = 0; col <= cols + 1; col++){
        store[0][col] = wall;
        store[rows + 1][col] = wall;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void pushUnvisited(int row, int col);
//
//  Description: This function is called in the exitMaze() to push the value 
//  in the mazeStack if they are a passage of exitMarker. This helps denote 
//  which cell is already visited.
//  
//  Preconditions: The row and col must be passed in and they must exist.
//
//  Postconditions: The row and col are pushed in if it is a passage '0' or
//  exitMarker 'e'.
//  
///////////////////////////////////////////////////////////////////////////////
void Maze::pushUnvisited(int row, int col){
    if (store[row][col] == passage || store[row][col] == entryMarker){
        mazeStack.push(Cell(row, col));
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void exitMaze();
//
//  Description: This function goes to each row and col to check if its a 
//  passage or exitmarker by calling pushUnvisited() to push the cell into 
//  the stack. Then it replaces the passage cell with '.' to mark the visited
//  cells and to show the path to exit. The function also check for dead ends
//  by check if the currentCell is surronded by wall. If currentCell is
//  surronded by wall it go back until different passage is found and try again.
//  Also adds directions to the path by checking the value of cell in the
//  mazePath stack.
//
//  Preconditions: The mazeStack must have value.
//
//  Postconditions: The loop runs exit cell is found. Or the mazeStack is 
//  empty, which tells the user the there was no exit found. Also, shows the
//  direction in the path.
//  
///////////////////////////////////////////////////////////////////////////////
void Maze::exitMaze(){
    int row, col;
    currentCell = exitCell;
    while(!(currentCell == entryCell)){
        row = currentCell.x;
        col = currentCell.y;
       // cout << *this;       
        if (!(currentCell == exitCell)){
            store[row][col] = visited;
            mazePath.push(Cell(row,col));
        }else{
            mazePath.push(Cell(row,col));
        }

        pushUnvisited(row - 1, col);   
        pushUnvisited(row + 1, col);
        pushUnvisited(row, col - 1);
        pushUnvisited(row, col + 1);

        if(store[row+1][col]==wall && store[row-1][col]==wall){
            if(store[row][col+1]==wall || store[row][col-1]==wall){
                if(!(store[row][col] == exitMarker)){
                    store[row][col] = '0';
                    if(store[row][col+1]==wall){   
                        //if right side wall go back placing 0 until open passage 
                        while(store[row+1][col]==wall && store[row-1][col] == wall){
                            int count = 0;
                            store[row][col-0]='0';
                            ++count;
                            --col;
                            mazePath.pop();
                            if(store[row][col]==exitMarker){
                                break;
                            }
                        }
                    }else if(store[row][col-1]==wall){
                        //if left side wall go back placing 0 until open passage 
                        while(store[row+1][col]==wall && store[row-1][col] == wall){
                            int count = 0;
                            store[row][col+count]='0';
                            ++count;
                            ++col;
                            mazePath.pop();
                            if(store[row][col]==exitMarker){
                                break;
                            }
                        }
                    }
                }
            }
        }else if(store[row][col+1]==wall && store[row][col-1]==wall){
            if(store[row+1][col] == wall || store[row-1][col] == wall){
                if(!(store[row][col] == exitMarker)){
                    store[row][col] = '0';
                    if(store[row+1][col]==wall){
                        //if up side wall go back placing 0 until open passage  
                        while(store[row-1][col-1]==wall && store[row-1][col+1] == wall){
                            int count = 1;
                            store[row][col-count]='0';
                            ++count;
                            --row;
                            mazePath.pop();
                            if(store[row][col]==exitMarker){
                                break;
                            }
                        }
                    }else if(store[row-1][col]==wall){
                        //if down side wall go back placing 0 until open passage 
                        while(!(store[row-1][col-1]==passage) || !(store[row-1][col+1] == passage)){
                            int count = 1;
                            store[row][col+count]='0';
                            count++;
                            ++row;
                            mazePath.pop();
                            if(store[row][col]==exitMarker){
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (mazeStack.empty()){
            cout << *this;
            cout << "Failure\n";
            return;
        }
        else
            currentCell = mazeStack.pop();
            
    }

    //push entrycell to the output stack.
    outputPath.push(entryCell);
    if(mazePath.top()==exitCell){
        outputPath.push(mazePath.pop());
        cout << *this;
    }

    while(!(mazePath.empty())){
        int x, y, xNext, yNext;
        currentCell = mazePath.pop();
        outputPath.push(currentCell);
        mazePathNext.push(mazePath.top());
        nextCell = mazePathNext.pop();
        x = currentCell.x;
        y = currentCell.y;
        xNext = nextCell.x;
        yNext = nextCell.y;
        if(store[x+1][y] == exitMarker){
            store[x][y] = '|';
            cout<<"Hello"<<endl;
        }
        else if(store[xNext][yNext] == store[x][y+1])
            store[x][y] = '-';
        else if(store[xNext][yNext] == store[x+1][y])
            store[x][y] = '|';
        else if(store[xNext][yNext] == store[x][y-1])
            store[x][y] = '-';
        else if(store[xNext][yNext] == store[x-1][y])
            store[x][y] = '|';
        
        if(mazePath.top()==exitCell){
            outputPath.push(mazePath.pop());
        }
        cout << *this;
    }
    //cout << *this;
    cout << "Success\n";

    //output the path [row, col]
    while (!outputPath.empty()){
        int x,y;
        currentCell = outputPath.pop();
        x = currentCell.x;
        y = currentCell.y;
        cout << "[" << x << "," << y << "]" << "  ";
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ostream &operator<<(ostream &out, const Maze &maze);
//
//  Description: This function outputs the maze on the screen by using for loop
//  to travers through the stack.
//  
//  Preconditions: There must be value in the stack.
//
//  Postconditions: The loop will stop when the count of row are less than or
//  equal to the number rows in the maze.rows.
//  
///////////////////////////////////////////////////////////////////////////////
ostream &operator<<(ostream &out, const Maze &maze){
    for (int row = 0; row <= maze.rows + 1; row++)
        out << maze.store[row] << endl;
    out << endl;
    return out;
}

// driver
int main(){
    Maze().exitMaze();
    return 0;
}