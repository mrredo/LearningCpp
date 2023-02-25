#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



/*
virkne ar cipariem
sortot ( 1 )
paņem ciparu no magn virknes pirmos 3 ciparus]


*/
auto findAndRemoveALLItems(vector<int> mag, int val) {
    bool find = false;
    while (find == false) {
        auto it = std::find(mag.begin(), mag.end(), val);
        if (it != mag.end()) mag.erase(it);
        else find = true;
    }

    return mag;
}
auto findAndRemoveItem(vector<int> mag, int val) {
    auto it = std::find(mag.begin(), mag.end(), val);
    if (it != mag.end())
        mag.erase(it);
    return mag;
}
bool isEven(int val) {
    return (val % 2) == 0;
}
auto TestData(vector<int> magn, int nulluSkaits) {
    vector <int> magnBezNullem;
    vector<int> nulluArr;
    string p, o; // pirmais un otrais cipars

    std::sort(magn.begin(), magn.end());

    magnBezNullem = findAndRemoveALLItems(magn, 0);
    p = to_string(magnBezNullem[0]);
    o = to_string(magnBezNullem[1]);
    magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
    magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);

    for (int i = 1; i < (nulluSkaits + 1); i++) {
        if (isEven(i)) p += "0";
        else o += "0";
    }

    

   

    int len = magnBezNullem.size();
    for (int i = 0; i < len; i++) {
        if (isEven(magnBezNullem.size()) && !isEven(nulluSkaits)) {
            p += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
            p += to_string(magnBezNullem[1]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[1]);
        } else if(!isEven(magnBezNullem.size()) && isEven(nulluSkaits)) {
            p += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
        } else if (isEven(magnBezNullem.size()) && isEven(nulluSkaits)) {
            o += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
        }
        else if(!isEven(magnBezNullem.size()) && !isEven(nulluSkaits)) {
            p += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
        }
    }

    cout << "\n1. skaitlis: " + p<< "\n 2.skaitlis: " + o << endl;
}
int main() {
    vector<int> m = {0,0,0,0,0,0,5,6,8,7,8,1,3 }; // 1. tests | magnēti
    int nSK = 6; // 1. tests | nullu skaits
        TestData(m, nSK);



}
