#include "snake.h"

void Snake::move(string rldf) {

}
int Snake::RandU(int nMin, int nMax)
{
    int r;
    do {
        r = rand();
    } while (r < ((unsigned int)(RAND_MAX) + 1) % (nMax + 1 - nMin));
    return r % (nMax + 1 - nMin) + nMin;
}
Snake::Snake() {
    int width = 5, height = 5;
    string arr[5][5];

    
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            arr[i][j] = "◻️";
           // std::cout << arr[i][j] << ' ';
        }
        //std::cout << std::endl;
    }
    
    // char* sn[5] = {"◻️", "◻️", "◻️", "◻️", "◻️"};
    // this->grid.insert(pair<string, char*>("1", sn));
};
