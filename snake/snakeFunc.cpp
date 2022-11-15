#include "snake.h"
void Snake::move(string rldf) {
    
    if (rldf == "u") {
        XY xy = this->sPos["head"];
        string msg = "";
        if (xy.Y == 0) {
            msg = "cant move up";
            this->inputMovement(msg);
            return;
        }
        this->SetSnakePos(xy.X, xy.Y - 1);
        this->inputMovement(msg);
    } else if(rldf == "d") {
        string msg = "";
        XY xy = this->sPos["head"];
        
        if (xy.Y == 4) {
            msg = "cant move down";
            this->inputMovement(msg);
            return;
        } 
        this->SetSnakePos(xy.X, xy.Y + 1);
        this->inputMovement(msg);
    } else if(rldf == "r") {
        string msg = "";
        XY xy = this->sPos["head"];
        
        if (xy.X == 4) {
            msg = "cant move right";
            this->inputMovement(msg);
            return;
        } 
        this->SetSnakePos(xy.X + 1, xy.Y);
        this->inputMovement(msg);
    } else if(rldf == "l") {
                string msg = "";
        XY xy = this->sPos["head"];
        
        if (xy.X == 0) {
            msg = "cant move left";
            this->inputMovement(msg);
            return;
        } 
        this->SetSnakePos(xy.X - 1, xy.Y);
        this->inputMovement(msg);
    } else {
        cout << "Invalid Move!";
        this->inputMovement("Invalid Move!");
    }
}


void Snake::inputMovement(string msg) {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << this->GridToString() << endl;
    string move;
    if(msg != "") cout << msg << endl;
    cout << "Movements: 'u'(up); 'd'(down); 'r'(right); 'l'(left)" << endl;
    cout << "Movement command: ";
    cin >> move;
    this->move(move);
}



int Snake::RandU(int nMax)
{
    srand((unsigned) time(NULL));
    int random = rand();

    return random % nMax;
}
XY Snake::newPos(int x, int y) {
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
    int DX = this->RandU(4);
    int DIY = this->RandU(4);
    if(DIY == 4) DIY -=1;
    if(DIY == 1) DIY +=1;
    if(DIY <4) DIY +=2;
    if(DIY >4) DIY -=2;
    this->grid[DIY][DX] = "M";
    this->sPos["head"] = this->newPos(DX, DIY);
    this->inputMovement("");
        
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

void Snake::SetSnakePos(int x, int y) {
    XY xy = newPos(x, y);
    XY head = this->sPos["head"];
    this->grid[head.Y][head.X] = "O";
    this->grid[xy.Y][xy.X] = "M";
    this->sPos["head"] = xy;
}