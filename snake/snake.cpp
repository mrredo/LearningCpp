

#include "snake.h"

int main() {
    Snake snake = Snake();
    cout << snake.GridToString() << endl;
    cout << snake.sPos["head"].X<< "\n"<<snake.sPos["head"].Y << endl;
}






