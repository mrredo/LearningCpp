#include <iostream>
#include <iterator>
#include <map>
#include <string> 
#include <ctime>
using namespace std;

class Snake {
    private:



    public:
    void move(string rlud);
    int  RandU(int nMax);
    string GridToString();
    void setGrid();


    Snake();
    

    // map<string, string[]> snakePosition;
    string grid[5][5];
};
