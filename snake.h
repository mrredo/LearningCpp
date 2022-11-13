#include <iostream>
#include <iterator>
#include <map>
#include <string> 
using namespace std;
class Snake {
    private:



    public:
    void move(string rlud);
    int  RandU(int nMin, int nMax);

    Snake();
    


    // map<string, string[]> snakePosition;
    string grid[5][5];
};
