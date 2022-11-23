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
    cout << to_string(snakeLength) << "\n";
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
    this->snakeLength = 1;
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
    grid[head.Y][head.X] = "O";
    if(nextIsApple(xy)) {
        cout << "Snake tail\n";
        addTail(head);
    }
    grid[xy.Y][xy.X] = "M";
    
    
    // cout << snakeLength << "\n";
    if(snakeLength > 1) {

        for(int i = 2; i < snakeLength + 2; i++) {
            // if(snakeLength != 2) {
                // XY ele = sPos[to_string(i)];
                XY preEle = sPos[to_string(i - 1)];
                grid[preEle.Y][preEle.X] = "V";
                sPos[to_string(i)] = preEle;
            // } 
            // else {
            //     grid[head.Y][head.X] = "V";
            //     sPos["2"] = head;
            // }

                        // XY aboveEl = sPos[tostring(i - 1)];
            // grid[aboveEl.Y][aboveEl.X] = "V";
        }
        
        XY eleSS = sPos[to_string(snakeLength)];
        grid[eleSS.Y][eleSS.X] = "O";
        XY el = sPos["2"];
        cout << el.Y << " : " << el.X << " : " <<  grid[el.Y][el.X] << endl;
        // XY tailLast = this->sPos[to_string(this->snakeLength)];
        // XY tailFirst = this->sPos["2"];
        // this->sPos["2"] = tailLast;
    }
    sPos["1"] = xy;
    
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
        
        if(this->grid[yp][xp] != "M" || this->grid[yp][xp] != "C") success = true; grid[yp][xp] = "H";
    }
    // this->grid[]
}


bool Snake::Dead(XY xy) {
    return false;
}

void Snake::addTail(XY newPos) {
    // if(this->nextIsApple(newPos)) {
        this->sPos[to_string(this->snakeLength + 1)] = newPos;
        // cout << to_string(this->snakeLength + 1) << endl;
        snakeLength += 1;
        this->grid[newPos.Y][newPos.X] = "V";
    // }
}
bool Snake::nextIsApple(XY newPos) {
    cout << this->grid[newPos.Y][newPos.X] << "\n";
    if(this->grid[newPos.Y][newPos.X] == "H") return true;
    return false;
}