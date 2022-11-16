#include "snake.h"
void Snake::move(string rldf) {
    
    if (rldf == "u") {
        XY xy = this->sPos["1"];
        string msg = "";
        if (xy.Y == 0) {
            msg = "cant move up";
            this->inputMovement(msg);
            return;
        }
        this->SetSnakePos(xy.X, xy.Y - 1);
        // cout << this->sPos["1"].X << " , " << this->sPos["1"].Y << " : " << this->sPos["2"].X << " , " << this->sPos["2"].Y << endl;
        this->inputMovement(msg);
    } else if(rldf == "d") {
        string msg = "";
        XY xy = this->sPos["1"];
        
        if (xy.Y == 4) {
            msg = "cant move down";
            this->inputMovement(msg);
            return;
        } 
        this->SetSnakePos(xy.X, xy.Y + 1);
        this->inputMovement(msg);
    } else if(rldf == "r") {
        string msg = "";
        XY xy = this->sPos["1"];
        
        if (xy.X == 4) {
            msg = "cant move right";
            this->inputMovement(msg);
            return;
        } 
        this->SetSnakePos(xy.X + 1, xy.Y);
        this->inputMovement(msg);
    } else if(rldf == "l") {
                string msg = "";
        XY xy = this->sPos["1"];
        
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
    int DX = this->RandU(1)+this->RandU(3)+this->RandU(1);
    int DIY = this->RandU(4)+this->RandU(1);
    // if(DIY == 4) DIY -=1;
    // if(DIY == 1) DIY +=1;
    // if(DIY <4) DIY +=2;
    // if(DIY >4) DIY -=2;
    this->snakeLength += 1;
    this->grid[DIY][DX] = "M";
    this->sPos["1"] = this->newPos(DX, DIY);
    this->CreateApple();
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
    XY head = this->sPos["1"];
    this->grid[head.Y][head.X] = "O";
    if(this->nextIsApple(xy)) {
        this->addTail(head);
    }
    this->grid[xy.Y][xy.X] = "M";
    this->sPos["1"] = xy;
}

void Snake::CreateApple() {
    bool success = false;
    while(!success) {
        int xp = this->RandU(4);
        int yp = this->RandU(4);
        if(yp == 4) yp -=1;
        if(yp == 1) yp +=1;
        if(yp <4) yp +=2;
        if(yp >4) yp -=2;
        
        if(this->grid[yp][xp] != "M" || this->grid[yp][xp] != "C") success = true;this->grid[yp][xp] = "H";
    }
    // this->grid[]
}


bool Snake::Dead(XY xy) {
    
}

void Snake::addTail(XY newPos) {
    // if(this->nextIsApple(newPos)) {
        this->sPos[to_string(this->snakeLength + 1)] = newPos;
        cout << to_string(this->snakeLength + 1) << endl;
        this->grid[newPos.Y][newPos.X] = "V";
    // }
}
bool Snake::nextIsApple(XY newPos) {
    cout << this->grid[newPos.Y][newPos.X] << endl;
    if(this->grid[newPos.Y][newPos.X] == "H") return true;
    return false;
}