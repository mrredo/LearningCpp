#include <iostream>
#include <iterator>
#include <map>
using namespace std;
class Snake {
    private:



    public:
    void move(string rlud);
    Snake();
    
    map<string, string[]> snakePosition;
    string grid[5][5];
};
