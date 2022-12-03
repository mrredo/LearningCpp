#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 450;
    int m1 = 21;
    int m2 = 30;
    int G = 2;
    int *zetoni = new int(1);
    vector<int> zeton;
    vector<int> JNzeton;
    int gajieni[2][2] = {
        { 375, 500},
        {20, 345},
        // {111, 132},
        // {33, 33},
        // {122, 144},
        // {276, 284},
        // {6, 45},
        // {128, 143},
        // {60, 71},
        // {250, 259},
    }; 
    for(int i = 1; i < N + 1; i++) { 
        if((i % m1) == 0 || (i % m2) == 0) {
            zeton.push_back(i);
        }

    }

    cout << "Sakums Zetonu skaits: " << zeton.size() << endl;

    for(int j = 0; j < (sizeof(gajieni)/sizeof(gajieni[0])); j++) {
        for(int i = 0; i < zeton.size(); i++) {
            if((gajieni[j][0] <= (zeton[i]) && (zeton[i]) <= gajieni[j][1]) == false) {
                JNzeton.push_back((zeton[i]));
            }
        }
        cout << j + 1 << ". gajiena palikusi zetoni: " << JNzeton.size() << endl;
        zeton = JNzeton;
        JNzeton.clear();
    }

    cout << "Speles beigas palika zetoni: " << zeton.size();
}

