#include <bits/stdc++.h>
using namespace std;

vector<char> kierunek;
vector<int> dlugosc;
vector<string> kolor;
const int najw = 800;
char lava_lake[najw][najw];

void wczytywanie(){
    string linia;
    while(getline(cin,linia)){
        kierunek.push_back(linia[0]);
        if(!isdigit(linia[3])){
            dlugosc.push_back(linia[2]-'0');
            kolor.push_back(linia.substr(5,7));
        }
        else{
            dlugosc.push_back((linia[2]-'0')*10+linia[3]-'0');
            kolor.push_back(linia.substr(6,7));
        }
    }
}

int main(){
    wczytywanie();
    for(int i = 0; i < najw;i++){
        for(int j = 0; j < najw;j++){
            lava_lake[i][j] = '.';
        }
    }
    int x = najw/2, y = najw/2;
    for(int i = 0; i < kierunek.size(); i++){
        if(kierunek[i] == 'R'){
            for(int j = 0; j < dlugosc[i];j++,y++){
                lava_lake[x][y] = '#';
            }
        }
        if(kierunek[i] == 'D'){
            for(int j = 0; j < dlugosc[i];j++,x++){
                lava_lake[x][y] = '#';
            }
        }
        if(kierunek[i] == 'U'){
            for(int j = 0; j < dlugosc[i];j++,x--){
                lava_lake[x][y] = '#';
            }
        }
        if(kierunek[i] == 'L'){
            for(int j = 0; j < dlugosc[i];j++,y--){
                lava_lake[x][y] = '#';
            }
        }
    }
    bool czy_w_srodku = 0, czy_bylo = 0;
    int wynik = 0;
    for(int i = 0; i < najw; i++){
        czy_w_srodku = 0;
        bool czy_na_gorze = 0, czy_na_gorze2 = 0, czy_na_dole = 0, czy_na_dole2 = 0;
        for(int j = 0; j < najw; j++){
            if(lava_lake[i][j] == '#' && lava_lake[i][j-1] == '.'){
                if(lava_lake[i+1][j] == '#')
                    czy_na_dole = 1;
                if(lava_lake[i-1][j] == '#')
                    czy_na_gorze = 1;
            }
            if(lava_lake[i][j] == '#' && lava_lake[i][j+1] == '.'){
                if(lava_lake[i+1][j] == '#')
                    czy_na_dole2 = 1;
                if(lava_lake[i-1][j] == '#')
                    czy_na_gorze2 = 1;
                if(czy_na_gorze == 1 && czy_na_gorze2 == 1 && czy_na_dole == 0 && czy_na_dole2 == 0){
                    czy_na_dole2 = 0; czy_na_dole = 0; czy_na_gorze2 = 0; czy_na_gorze = 0;
                    wynik++;
                    cout << lava_lake[i][j];
                    continue;
                }
                if(czy_na_gorze == 0 && czy_na_gorze2 == 0 && czy_na_dole == 1 && czy_na_dole2 == 1){
                    czy_na_dole2 = 0; czy_na_dole = 0; czy_na_gorze2 = 0; czy_na_gorze = 0;
                    wynik++;
                    cout << lava_lake[i][j];
                    continue;
                }
                czy_na_dole2 = 0; czy_na_dole = 0; czy_na_gorze2 = 0; czy_na_gorze = 0;
            }
            if(lava_lake[i][j] == '#' && lava_lake[i][j+1] != '#' && czy_w_srodku == 0){
                czy_w_srodku = 1;
            }
            else if(lava_lake[i][j] == '#' && lava_lake[i][j+1] != '#' && czy_w_srodku == 1)
                czy_w_srodku = 0;
            if(czy_w_srodku || lava_lake[i][j] == '#')
                wynik++;
            cout << lava_lake[i][j];
        }
        cout << endl;
    }
    cout << wynik;
}