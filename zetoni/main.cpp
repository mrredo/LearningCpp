#include <iostream>

using namespace std;

int main() {
    int N = 50;
    int m1 = 2;
    int m2 = 3;
    int G = 2;
    int *zetoni = new int(N);
    int *labieZetoni;
    int dati[2][2] = {// 2 ir gājienu skaits
        {
            23, 32
        },
        {
            10, 28
        },
    }; 
    for(int i = 1; i < N + 1; i++) { //padomāt cik ir i = 0 vai i = 1;
        zetoni[i - 1] = i;
    }
    // for (int i = 1; i < N + 1; i++) {
    //     if((zetoni[i - 1] % m1) == 0 || (zetoni[i - 1] % m2) == 0) labieZetoni[i - 1] = zetoni[i - 1];
    //     zetoni = labieZetoni;
    // }
    for(int i = 1; i < N + 1; i++) { //padomāt cik ir i = 0 vai i = 1;
        cout << zetoni[i - 1] << endl;
    }
    for(int i = 0; i < G; i ++) {

    }
}

