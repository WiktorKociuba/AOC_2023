#include <bits/stdc++.h>
using namespace std;

int main(){
    int czer = 12, ziel = 13, nieb = 14;
    string linia;
    int wynik = 0;
    for (int i = 1; i < 101; i++)
    {
        cout << i << " ";
        getline(cin, linia);
        int j = 0;
        if(i < 10){
            j = 8;
        }
        else
            j = 9;
        int pierwsza = 0, druga = 0, czer_lok = 0, ziel_lok = 0, nieb_lok = 0;
        bool czy_mozliwe = 1;
        for(; j < linia.size();j++){
            if(linia[j] == ';' || j + 1 == linia.size()){
                if(czer_lok > czer || ziel_lok > ziel || nieb_lok > nieb){
                    czy_mozliwe = 0;
                    break;
                }
                ziel_lok = 0; czer_lok = 0; nieb_lok = 0;
            }
            if(linia.size() - j >= 3){
                if(linia.substr(j+2,3) == "red"){
                    if(linia[j-1] - 48 >= 0 && linia[j-1] - 48 <= 9){
                        pierwsza = (linia[j-1] - 48)*10;
                        druga = linia[j] - 48;
                        czer_lok += pierwsza + druga;
                    }
                    else{
                        czer_lok += linia[j] - 48;
                    }
                }
            }
            if(linia.size() - j >= 4){
                if(linia.substr(j+2,4) == "blue"){
                    if(linia[j-1] - 48 >= 0 && linia[j-1] - 48 <= 9){
                        pierwsza = (linia[j-1] - 48)*10;
                        druga = linia[j] - 48;
                        nieb_lok += pierwsza + druga;
                    }
                    else{
                        nieb_lok += linia[j] - 48;
                    }
                }
            }
            if(linia.size() - j >= 5){
                if(linia.substr(j+2,5) == "green"){
                    if(linia[j-1] - 48 >= 0 && linia[j-1] - 48 <= 9){
                        pierwsza = (linia[j - 1] - 48)*10;
                        druga = linia[j] - 48;
                        ziel_lok += pierwsza + druga;
                    }
                    else{
                        ziel_lok += linia[j] - 48;
                    }
                }
            }
        }
        if(czy_mozliwe){
            wynik += i;
        }
        cout << czy_mozliwe<< " " << i << endl;
    }
    cout << wynik;
    return 0;
}