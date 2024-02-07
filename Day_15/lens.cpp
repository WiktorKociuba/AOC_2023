#include <bits/stdc++.h>
using namespace std;

int hashing(string linia){
    int wynik_lok = 0;
    for(int i = 0; i < linia.size(); i++){
        wynik_lok += int(linia[i]);
        wynik_lok = wynik_lok * 17;
        wynik_lok = wynik_lok % 256;
    }
    return wynik_lok;
}

int main(){
    string linia;
    getline(cin,linia);
    int ost_przec = 0,wynik = 0;
    for(int i = 0; i < linia.size();i++){
        if(linia[i] == ',' && i != 0){
            wynik += hashing(linia.substr(ost_przec+1,i-ost_przec-1));
            ost_przec = i;
        }
    }
    cout << wynik;
}