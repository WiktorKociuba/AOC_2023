#include <bits/stdc++.h>
using namespace std;

vector<string> mapa;
int wynik_koc = 0;
pair<int,int> start,koniec;

void wczytywanie(){
    string linia;
    while(getline(cin,linia)){
        mapa.push_back(linia);
    }
}
//1-dol 2-gora 3-lewo 4-prawo
void znajdz(pair<int,int> pozycja, int wynik,int kierunek){
    if(pozycja == koniec){
        wynik_koc = max(wynik,wynik_koc);
        return;
    }
    /*if(mapa[pozycja.first+1][pozycja.second] == '.' || mapa[pozycja.first+1][pozycja.second] == 'v'){
        znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1);
    }
    if(mapa[pozycja.first-1][pozycja.second] == '.' || mapa[pozycja.first-1][pozycja.second] == '^'){
        znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2);
    }
    if(mapa[pozycja.first][pozycja.second-1] == '.' || mapa[pozycja.first][pozycja.second-1] == '<'){
        znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3);
    }
    if(mapa[pozycja.first][pozycja.second+1] == '.' || mapa[pozycja.first][pozycja.second+1] == '>'){
        znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4);
    }*/
    if(kierunek == 1){
        if(mapa[pozycja.first+1][pozycja.second] == '.' || mapa[pozycja.first+1][pozycja.second] == 'v'){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.' || mapa[pozycja.first][pozycja.second-1] == '<'){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.' || mapa[pozycja.first][pozycja.second+1] == '>'){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4);
        }
    }
    else if(kierunek == 2){
        if(mapa[pozycja.first-1][pozycja.second] == '.' || mapa[pozycja.first-1][pozycja.second] == '^'){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.' || mapa[pozycja.first][pozycja.second-1] == '<'){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.' || mapa[pozycja.first][pozycja.second+1] == '>'){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4);
        }
    }
    else if(kierunek == 3){
        if(mapa[pozycja.first+1][pozycja.second] == '.' || mapa[pozycja.first+1][pozycja.second] == 'v'){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1);
        }
        if(mapa[pozycja.first-1][pozycja.second] == '.' || mapa[pozycja.first-1][pozycja.second] == '^'){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.' || mapa[pozycja.first][pozycja.second-1] == '<'){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3);
        }
    }
    else if(kierunek == 4){
        if(mapa[pozycja.first+1][pozycja.second] == '.' || mapa[pozycja.first+1][pozycja.second] == 'v'){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1);
        }
        if(mapa[pozycja.first-1][pozycja.second] == '.' || mapa[pozycja.first-1][pozycja.second] == '^'){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.' || mapa[pozycja.first][pozycja.second+1] == '>'){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4);
        }
    }
}

int main(){
    wczytywanie();
    for(int i = 0;i < mapa[0].size();i++){
        if(mapa[0][i] == '.'){
            start = make_pair(0,i);
            break;
        }
    }
    for(int i = 0; i < mapa[mapa.size()-1].size(); i++){
        if(mapa[mapa.size()-1][i] == '.'){
            koniec = make_pair(mapa.size()-1,i);
            break;
        }
    }
    znajdz(start,0,1);//mozliwe ze wynik na 1 trzeba ustawic
    cout << wynik_koc;
} 