#include <bits/stdc++.h>
using namespace std;

char tablica[100][100];
int wynik = 0;

void wczytywanie(){
    string linia;
    for(int j = 0;getline(cin,linia); j++)
    {
        for(int i = 0; i < linia.size(); i++){
            tablica[j][i] = linia[i];
        }
    }
}

void obl_wyn(){
    int war_kwa = 100, ost_poz_kwa = 0, ilosc_okr = 0;
    for(int i = 0; i < 100; i++){
        ost_poz_kwa = 0;
        war_kwa = 100;
        ilosc_okr = 0;
        for(int j = 0; j < 100; j++){
            if(tablica[j][i] == '#'){
                ost_poz_kwa = j;
                ilosc_okr = 1;
            }
            else if(tablica[j][i] == 'O'){
                wynik += war_kwa - (ost_poz_kwa+ilosc_okr);
                ilosc_okr++;
            }
        }
    }
}

void north(){
    int ost_poz_kwa = 0, ilosc_okr = 0;
    for(int i = 0; i < 100; i++){
        ost_poz_kwa = 0;
        ilosc_okr = 0;
        for(int j = 0; j < 100; j++){
            if(tablica[j][i] == '#'){
                ost_poz_kwa = j;
                ilosc_okr = 1;
            }
            else if(tablica[j][i] == 'O'){
                if(ost_poz_kwa+ilosc_okr != j){
                    tablica[ost_poz_kwa+ilosc_okr][i] = 'O';
                    tablica[j][i] = '.';
                }
                ilosc_okr++;
            }
        }
    }
}

void west(){
    int ost_poz_kwa = 0, ilosc_okr = 0;
    for(int i = 0; i < 100; i++){
        ost_poz_kwa = 0;
        ilosc_okr = 0;
        for(int j = 0; j < 100; j++){
            if(tablica[i][j] == '#'){
                ost_poz_kwa = j;
                ilosc_okr = 1;
            }
            else if(tablica[i][j] == 'O'){
                if(ost_poz_kwa+ilosc_okr != j){
                    tablica[i][ost_poz_kwa+ilosc_okr] = 'O';
                    tablica[i][j] = '.';
                }
                ilosc_okr++;
            }
        }
    }
}

void south(){
    int ost_poz_kwa = 0, ilosc_okr = 0;
    for(int i = 0; i < 100; i++){
        ost_poz_kwa = 99;
        ilosc_okr = 0;
        for(int j = 99; j >= 0; j--){
            if(tablica[j][i] == '#'){
                ost_poz_kwa = j;
                ilosc_okr = 1;
            }
            else if(tablica[j][i] == 'O'){
                if(ost_poz_kwa-ilosc_okr != j){
                    tablica[ost_poz_kwa-ilosc_okr][i] = 'O';
                    tablica[j][i] = '.';
                }
                ilosc_okr++;
            }
        }
    }
}

void east(){
    int ost_poz_kwa = 0, ilosc_okr = 0;
    for(int i = 0; i < 100; i++){
        ost_poz_kwa = 99;
        ilosc_okr = 0;
        for(int j = 99; j >= 0; j--){
            if(tablica[i][j] == '#'){
                ost_poz_kwa = j;
                ilosc_okr = 1;
            }
            else if(tablica[i][j] == 'O'){
                if(ost_poz_kwa-ilosc_okr != j){
                    tablica[i][ost_poz_kwa-ilosc_okr] = 'O';
                    tablica[i][j] = '.';
                }
                ilosc_okr++;
            }
        }
    }
}

int main(){
    wczytywanie();
    for(int i = 0; i < 1000000000; i++){
    north();
    west();
    south();
    east();
    }
    obl_wyn();
    cout << wynik;
    return 0;
}