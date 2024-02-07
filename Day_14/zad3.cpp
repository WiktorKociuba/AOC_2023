#include <bits/stdc++.h>
using namespace std;

char tablica[100][100];
char historia[1000][100][100];
int wynik = 0;
int temp_j = 0;

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
    int war_kwa = 100;
    wynik = 0;
    for(int i = 0; i < 100; i++){
        war_kwa = 100;
        for(int j = 0; j < 100; j++){
            if(tablica[j][i] == 'O'){
                wynik += war_kwa - j;
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
    //bool czy_to_samo = 1;
    for(int i = 0; i < 128; i++){
    //czy_to_samo = 1;
    north();
    west();
    south();
    east();
    /*temp_j = 0;
    for(int j = temp_j+1; j < i;j++){
        czy_to_samo =1;
        for(int k = 0; k < 100;k++){
            for(int l = 0; l < 100;l++){
                if(tablica[k][l] != historia[j][k][l]){
                    czy_to_samo = 0;
                    break;
                }
            }
            if(!czy_to_samo)
               break;
        }
        if(czy_to_samo && i != 0){
            cout << j << " " << i << endl;
            temp_j = j;
            break;
        }
    }
    for(int j = 0; j < 100;j++){
        for(int k = 0; k < 100; k++){
            historia[i][j][k] = tablica[j][k];
        }
    }*/
    
    }
    obl_wyn();
    cout << wynik;
    return 0;
}