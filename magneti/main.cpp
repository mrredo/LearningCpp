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
        if (isEven(magnBezNullem.size())) {
            o += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
        }
        else {
            p += to_string(magnBezNullem[0]);
            magnBezNullem = findAndRemoveItem(magnBezNullem, magnBezNullem[0]);
        }
    }

    cout << "\n1. skaitlis: " + p<< "\n 2.skaitlis: " + o << endl;
}
int main() {
    vector<int> m = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 }; // 1. tests | magnēti
    int nSK = 1; // 1. tests | nullu skaits
    cout << "1. Tests: ";
    TestData(m, nSK);
    m = { 1,2,3,4,5,0,0,0 }; // 2. tests | magnēti
    nSK = 3; // 2. tests | nullu skaits
    cout << "2. Tests: ";
    TestData(m, nSK);

    m = { 0,0,0,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,0,0,0 }; // 3. tests | magnēti
    nSK = 14; // 3. tests | nullu skaits
    cout << "3. Tests: ";
    TestData(m, nSK);
        m = { 0,0,0,1,12,2,3,4 }; // 3. tests | magnēti
    nSK = 3; // 3. tests | nullu skaits
    cout << "3. Tests: ";
    TestData(m, nSK);


}
