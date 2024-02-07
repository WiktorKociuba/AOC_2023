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
//tablica odw
/*void znajdz(pair<int,int> pozycja, int wynik,int kierunek,bool odw[][141]){
    cout << pozycja.first << " " << pozycja.second << endl;
    if(pozycja == koniec){
        wynik_koc = max(wynik,wynik_koc);
        return;
    }
    odw[pozycja.first][pozycja.second] = true;
    /*if(mapa[pozycja.first+1][pozycja.second] == '.'){// && odw[pozycja.first+1][pozycja.second] == 0){
        znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1,odw);
    }
    if(mapa[pozycja.first-1][pozycja.second] == '.'){// && odw[pozycja.first-1][pozycja.second] == 0){
        znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2,odw);
    }
    if(mapa[pozycja.first][pozycja.second-1] == '.'){// && odw[pozycja.first][pozycja.second-1] == 0){
        znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3,odw);
    }
    if(mapa[pozycja.first][pozycja.second+1] == '.'){//&& odw[pozycja.first][pozycja.second+1] == 0){
        znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4,odw);
    }
    if(kierunek == 1){
        if(mapa[pozycja.first+1][pozycja.second] == '.'){// && odw[pozycja.first+1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1,odw);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.'){// && odw[pozycja.first][pozycja.second-1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3,odw);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.'){// && odw[pozycja.first][pozycja.second+1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4,odw);
        }
    }
    else if(kierunek == 2){
        if(mapa[pozycja.first-1][pozycja.second] == '.'){// && odw[pozycja.first-1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2,odw);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.'){// && odw[pozycja.first][pozycja.second-1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3,odw);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.'){// && odw[pozycja.first][pozycja.second+1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4,odw);
        }
    }
    else if(kierunek == 3){
        if(mapa[pozycja.first+1][pozycja.second] == '.'){// && odw[pozycja.first+1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1,odw);
        }
        if(mapa[pozycja.first-1][pozycja.second] == '.'){// && odw[pozycja.first-1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2,odw);
        }
        if(mapa[pozycja.first][pozycja.second-1] == '.'){// && odw[pozycja.first][pozycja.second-1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second-1),wynik+1,3,odw);
        }
    }
    else if(kierunek == 4){
        if(mapa[pozycja.first+1][pozycja.second] == '.'){// && odw[pozycja.first+1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first+1,pozycja.second),wynik+1,1,odw);
        }
        if(mapa[pozycja.first-1][pozycja.second] == '.'){// && odw[pozycja.first-1][pozycja.second] == 0){
            znajdz(make_pair(pozycja.first-1,pozycja.second),wynik+1,2,odw);
        }
        if(mapa[pozycja.first][pozycja.second+1] == '.'){// && odw[pozycja.first][pozycja.second+1] == 0){
            znajdz(make_pair(pozycja.first,pozycja.second+1),wynik+1,4,odw);
        }
    }
}*/

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
    bool odw[141][141];
    for(int i = 0; i < 141;i++){
        for(int j = 0; j < 141;j++){
            odw[i][j] = 0;
        }
    }
    cout << "tu" << endl;
    //znajdz(start,0,1,odw);//mozliwe ze wynik na 1 trzeba ustawic
} 