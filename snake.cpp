
#include <iostream>
#include <string> 

// #include "snake.h"
using namespace std;
int main() {
    // Snake snake = Snake();
    string arr[5][5];

    int width = 5, height = 5;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            arr[i][j] = "x: " + std::to_string(j)+ ", y: " + std::to_string(i);
           // std::cout << arr[i][j] << ' ';
        }
        //std::cout << std::endl;
    }
    cout << arr[4][1];
    // for (int i = 0; i < height; ++i)
    // {
    //     for (int j = 0; j < width; ++j)
    //     {
    //         std::cout << arr[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }
}
