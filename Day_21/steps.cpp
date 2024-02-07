#include <bits/stdc++.h>
using namespace std;

vector<string> mapa;
int wynik = 0;
const int roz = 131;
bool odw[roz][roz];

void wczytywanie(){
    string linia;
    for(int j = 0; getline(cin,linia); j++){
        mapa.push_back(linia);
        for(int i = 0; i < linia.size();i++){
            odw[j][i] = 0;
        }
    }
}

void kroki(pair<int,int> pozycja, int krok){
    if(krok == 64 && !odw[pozycja.first][pozycja.second]){
        wynik++;
        odw[pozycja.first][pozycja.second] = true;
        return;
    }
    else if(krok == 64 && odw[pozycja.first][pozycja.second]){
        return;
    }
    if(pozycja.first+1 < mapa.size())
    if(mapa[pozycja.first+1][pozycja.second] == '.'){
        kroki({pozycja.first+1,pozycja.second},krok+1);
    }
    if(pozycja.first-1 >= 0)
    if(mapa[pozycja.first-1][pozycja.second] == '.'){
        kroki({pozycja.first-1,pozycja.second},krok+1);
    }
    if(pozycja.second+1 < mapa[0].size())
    if(mapa[pozycja.first][pozycja.second+1] == '.'){
        kroki({pozycja.first,pozycja.second+1},krok+1);
    }
    if(pozycja.second-1 >= 0)
    if(mapa[pozycja.first][pozycja.second-1] == '.'){
        kroki({pozycja.first,pozycja.second-1},krok+1);
    }
}

int main(){
    wczytywanie();
    pair<int,int> start;
    for(int i = 0; i < mapa.size();i++){
        for(int j = 0; j < mapa[0].size();j++){
            if(mapa[i][j] == 'S'){
                start = {i,j};
                break;
            }
        }
    }
    kroki(start,0);
    /*for(int i = 0; i < roz; i++){
        for(int j = 0; j < roz; j++){
            cout << odw[i][j];
        }
        cout << endl;
    }*/
    cout << endl;
    cout << wynik;
}