#include "snake.h"

void Snake::move(string rldf) {

}
int Snake::RandU(int nMax)
{
    srand((unsigned) time(NULL));
    int random = rand();

    return random % nMax;
}
Snake::Snake() {
    int width = 5, height = 5;

    
    for (int i = 0; i < height; ++i)
    {
        
        for (int j = 0; j < width; ++j)
        {
            this->grid[i][j] = "◻️";
            
        }
        //std::cout << std::endl;
    }
    // cout << this->grid[1][2] << endl;
    // char* sn[5] = {"◻️", "◻️", "◻️", "◻️", "◻️"};
    // this->grid.insert(pair<string, char*>("1", sn));
};

string Snake::GridToString() {
    string grid;
    for(int i = 0; i < sizeof(this->grid); i++) {
        for(int j = 0; j < sizeof(this->grid[i]); j++) {
            grid += this->grid[i][j];
            cout << this->grid[i][j] << endl;
        }
        grid += "\n";
    }
    return grid;
}