#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ten5 = 100000;
struct sportists {
    int nr;
    int punkti;
};
struct test {
    int nr, pn;
};
bool compare_person(const test &person1, const test &person2)
{
    if(person2.pn > person1.pn)
    return 1;
    if(person2.pn == person1.pn)
    {
        if(person2.nr > person1.nr)
        return 1;
    } 
    return false;
}
test NewTe(int nr, int punkti) {
    test sports;
    sports.nr = nr;
    sports.pn = punkti;
    return sports;
};
sportists NewSPR(int nr, int punkti) {
    sportists sports;
    sports.nr = nr;
    sports.punkti = punkti;
    return sports;
};


int main() {
    int demo[12] = {44, 16, 14, 45, 41, 20, 40, 41, 37, 45, 45, 30};
    test dem[3] = {NewTe(1, 2), NewTe(2, 5), NewTe(3, 1)};
    int len = sizeof(dem)/sizeof(dem[0]);
    cout <<"Before sorting array : ";
    for(int i=0; i<len; i++)
    {
        cout<<" "<<dem[i].pn;
    }
     
    stable_sort(dem, dem+len, &compare_person);//Sorting demo array
     
    cout<<"\n\nAfter sorting array : ";
    for(int i=0; i<len; i++)
    {
        cout<<" "<<dem[i].pn;
    }
    return 0;
    // int nr[12];
    
    // int punkti[12] = {44, 16, 14, 45, 41, 20, 40, 41, 37, 45, 45, 30};
    // for(int i = 0; i < 12; i++) {
    //     nr[i] = i;
    // }
    // int n = sizeof(nr) / sizeof(nr[0]);
    // int np = sizeof(punkti) / sizeof(punkti[0]);
    // vector<int> nrv (nr, nr+12);    
    // sort(nrv.end(), nrv.begin());
    // cout << nrv.begin()[11] << endl;
    
}

