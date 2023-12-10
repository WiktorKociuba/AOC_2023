#include <bits/stdc++.h>
using namespace std;

int czas[4], rekord[4];
vector<int> roz;

int main(){
    for(int i = 0; i < 4; i++){
        cin >> czas[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> rekord[i];
    }
    int wynik = 1;
    for(int i = 0; i < 4; i++){
        roz.clear();
        for(int j = 1, lok = 0; j <= czas[i]; j++){
            lok = j * (czas[i]-j);
            if(lok > rekord[i]){
                roz.push_back(j);
            }
        }
        wynik *= roz.end() - roz.begin();
    }
    cout << wynik;
}