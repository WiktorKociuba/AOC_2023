#include <bits/stdc++.h>
using namespace std;

int main(){
    string linia;
    int suma = 0;
    for(int q = 0; q <1000;q++){
        getline(cin, linia);
        bool czy_pierwsza = 0;
        int pierwsza =0 , druga = 0, checksum = 0;
        for(int i = 0; i < linia.size(); i++){
            if(!czy_pierwsza){
                if(int(linia[i]) <= int('9')&& int(linia[i]) >= int('1')){
                    pierwsza = int(linia[i])-48;
                    druga = int(linia[i])-48;
                    czy_pierwsza = true;
                }
                if(linia.size() - i >=3){
                    if(linia.substr(i,3) == "one"){
                        pierwsza = 1;
                        druga = 1;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,3) == "two"){
                        pierwsza = 2;
                        druga = 2;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,3) == "six"){
                        pierwsza = 6;
                        druga = 6;
                        czy_pierwsza = true;
                    }
                }
                if(linia.size() - i >=4){
                    if(linia.substr(i,4) == "four"){
                        pierwsza = 4;
                        druga = 4;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,4) == "five"){
                        pierwsza = 5;
                        druga = 5;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,4) == "nine"){
                        pierwsza = 9;
                        druga = 9;
                        czy_pierwsza = true;
                    }
                }
                if(linia.size() - i >=5){
                    if(linia.substr(i,5) == "three"){
                        pierwsza = 3;
                        druga = 3;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,5) == "seven"){
                        pierwsza = 7;
                        druga = 7;
                        czy_pierwsza = true;
                    }
                    if(linia.substr(i,5) == "eight"){
                        pierwsza = 8;
                        druga = 8;
                        czy_pierwsza = true;
                        
                    }
                }
            }
            else{
                if(int(linia[i]) <= int('9')&& int(linia[i]) >= int('1')){
                    druga = int(linia[i])-48;
                }
                if(linia.size() - i >=3){
                    if(linia.substr(i,3) == "one"){
                        druga = 1;
                    }
                    if(linia.substr(i,3) == "two"){
                        druga = 2;
                    }
                    if(linia.substr(i,3) == "six"){
                        druga = 6;
                    }
                }
                if(linia.size() - i >=4){
                    if(linia.substr(i,4) == "four"){
                        druga = 4;
                    }
                    if(linia.substr(i,4) == "five"){
                        druga = 5;
                    }
                    if(linia.substr(i,4) == "nine"){
                        druga = 9;
                    }
                }
                if(linia.size() - i >=5){
                    if(linia.substr(i,5) == "three"){
                        druga = 3;
                    }
                    if(linia.substr(i,5) == "seven"){
                        druga = 7;
                    }
                    if(linia.substr(i,5) == "eight"){
                        druga = 8;
                    }
                }
            }
        }
        pierwsza*=10;
        checksum = pierwsza+druga;
        suma += checksum;
    }
    cout << suma;
    return 0;
}