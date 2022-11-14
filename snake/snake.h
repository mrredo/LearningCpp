#include <iostream>
#include <iterator>
#include <map>
#include <string> 
#include <ctime>
using namespace std;
struct XY {
  int X;
  int Y;
};
class Snake {
    private:



    public:
    void move(string rlud);
    int  RandU(int nMax);
    string GridToString();
    void setGrid();
    void inputMovement();

    Snake();
    

    // map<string, string[]> snakePosition;
    map<string, XY> sPos;
    string grid[5][5];
};
