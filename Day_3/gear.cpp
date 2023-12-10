#include <bits/stdc++.h>
using namespace std;

char silnik[142][142];

bool czy_znak(int i, int j){
    if(!isdigit(silnik[i][j+1]) && silnik[i][j+1] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i][j-1]) && silnik[i][j-1] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i+1][j]) && silnik[i+1][j] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i-1][j]) && silnik[i-1][j] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i-1][j-1]) && silnik[i-1][j-1] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i+1][j-1]) && silnik[i+1][j-1] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i+1][j+1]) && silnik[i+1][j+1] != '.'){
        return true;
    }
    else if(!isdigit(silnik[i-1][j+1]) && silnik[i-1][j+1] != '.'){
        return true;
    }
    return false;
}

int main(){
    
    for (int i = 0; i < 142; i++){
        for (int j = 0; j < 142; j++){
            cin >> silnik[i][j];
        }
    }

    int pierwsza = 0, druga = 0, trzecia = 0;
    int wynik = 0;
    for (int i = 1; i < 141; i++){
        for (int j = 1; j < 141; j++){
            pierwsza = 0; druga = 0; trzecia = 0;
            if(isdigit(silnik[i][j])){//czy dana linijka to liczba
                if(isdigit(silnik[i][j]) && isdigit(silnik[i][j+1]) && isdigit(silnik[i][j+2])){
                    if(czy_znak(i,j) || czy_znak(i,j+1) || czy_znak(i,j+2)){
                        pierwsza = silnik[i][j] - 48;
                        druga = silnik[i][j+1] - 48;
                        trzecia = silnik[i][j+2] - 48;
                        int pom = pierwsza*100+druga*10+trzecia;
                        wynik += pom;
                        j+=2;
                        //cout << pom << " ";
                    }
                }
                else if(isdigit(silnik[i][j]) && isdigit(silnik[i][j+1])){
                    if(czy_znak(i,j) || czy_znak(i,j+1)){
                        pierwsza = silnik[i][j] - 48;
                        druga = silnik[i][j+1] - 48;
                        int pom = pierwsza*10+druga;
                        wynik += pom;
                        j+=1;
                        //cout << pom << " ";
                    }
                }
                else if(isdigit(silnik[i][j])){//czy jednocyfrowa;
                    if(czy_znak(i,j)){
                        wynik += silnik[i][j] -48;
                        //cout << silnik[i][j] << " ";
                    }
                }
            
            }
            
        }
    }
    cout << wynik;
}