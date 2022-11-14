#include "snake.h"
void Snake::move(string rldf) {
    if (rldf == "u") {
        XY xy = this->sPos["head"];
        this->grid[xy.Y][xy.X] = "O";
        if (xy.Y == 5) {
            cout << "cant move up" << endl;
            return;
        } 
        this->grid[xy.Y + 1][xy.X] = "M";
    } else if(rldf == "d") {

    } else if(rldf == "r") {
        
    } else if(rldf == "l") {
        
    }
}

int Snake::RandU(int nMax)
{
    srand((unsigned) time(NULL));
    int random = rand();

    return random % nMax;
}
XY newPos(int x, int y) {
    XY pos;
    pos.X = x;
    pos.Y = y;
    return pos;
};
Snake::Snake() {
    int width = 5, height = 5;
    
    for (int i = 0; i < height; ++i)
    {
        
        for (int j = 0; j < width; ++j)
        {
            this->grid[i][j] = "O";
            
        }
        //std::cout << std::endl;
    }
    int sIX = this->RandU(5);
    int DIY = this->RandU(5);
    if(DIY == 5) DIY -=1;
    if(DIY == 1) DIY +=1;
    if(DIY <4) DIY +=2;
    if(DIY >4) DIY -=2;
    this->grid[DIY][sIX] = "M";
    this->sPos["head"] = newPos(sIX, DIY);
    
    // cout << this->grid[1][2] << endl;
    // char* sn[5] = {"◻️", "◻️", "◻️", "◻️", "◻️"};
    // this->grid.insert(pair<string, char*>("1", sn));
};

string Snake::GridToString() {
    string grid;
    for(int i = 0; i < (sizeof(this->grid)/sizeof(this->grid[0])); i++) {
        for(int j = 0; j < (sizeof(this->grid[i])/sizeof(this->grid[i][0])); j++) {
            grid += this->grid[i][j];
        }
        grid += "\n";

    }

    
    return grid;
}