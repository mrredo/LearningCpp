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
    public:
    void move(string rlud);
    int  RandU(int nMax);
    string GridToString();
    void setGrid();
    void inputMovement(string msg);
    void SetSnakePos(int x, int y);
    void CreateApple();
    bool Dead(XY xy);
    XY newPos(int x, int y);

    Snake();
    int Score;
    XY applePos;
    // map<string, string[]> snakePosition;
    map<string, XY> sPos;
    int snakeLength;
    string grid[5][5];
};
