#include <bits/stdc++.h>
using namespace std;

int main(){
    string linia;
    int wynik = 0;
    for (int i = 1; i < 101; i++)
    {
        getline(cin, linia);
        int j = 0;
        if(i < 10){
            j = 8;
        }
        else
            j = 9;
        int pierwsza = 0, druga = 0, czer_lok = 0, ziel_lok = 0, nieb_lok = 0;
        int czer = 0, ziel = 0, nieb = 0;
        for(; j < linia.size();j++){
            if(linia[j] == ';' || j + 1 == linia.size()){
                czer = max(czer,czer_lok);
                ziel = max(ziel,ziel_lok);
                nieb = max(nieb,nieb_lok);
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
            wynik += czer*nieb*ziel;
    }
    cout << wynik;
    return 0;
}