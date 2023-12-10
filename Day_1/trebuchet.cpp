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
            if(int(linia[i]) <= int('9')&& int(linia[i]) >= int('1') && !czy_pierwsza){
                czy_pierwsza = true;
                pierwsza = int(linia[i])-48;
                druga = int(linia[i])-48;
                
            }
            else if(int(linia[i]) <= int('9')&& int(linia[i]) >= int('1')){
                druga = int(linia[i])-48;
            }
            
        }
        pierwsza*=10;
        checksum = pierwsza+druga;
        suma += checksum;
    }
    cout << suma;
    return 0;
}