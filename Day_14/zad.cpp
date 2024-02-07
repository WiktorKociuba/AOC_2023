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

void przesuwanie(){
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
            cout << wynik << " ";
        }
        cout << endl;
    }
}

int main(){
    wczytywanie();
    przesuwanie();
    cout << wynik;
    return 0;
}