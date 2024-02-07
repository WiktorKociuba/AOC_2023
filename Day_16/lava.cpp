#include <bits/stdc++.h>
using namespace std;

char schemat[110][110];
bool czy_odwiedzone[110][110];
// 1 - w prawo, 2 - w dół, 3 - w lewo, 4 - w górę

void laser(int kierunek,pair<int,int> pozycja){
    if(kierunek == 1){
        for(int i = pozycja.first, j = pozycja.second; j < 110; j++){
            if(pozycja.first == 0 && pozycja.second == 0){
            }
            if(schemat[i][j] == '|'){
                if(czy_odwiedzone[i][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(2,make_pair(i+1,j));
                laser(4,make_pair(i-1,j));
                return;
            }
            if(schemat[i][j] == '/'){
                if(schemat[i][j] == 1 && schemat[i-1][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(4,make_pair(i-1,j));
                return;
            }
            if(schemat[i][j] == 'l'){
                if(schemat[i][j] == 1 && schemat[i+1][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(2,make_pair(i+1,j));
                return;
            }
            czy_odwiedzone[i][j] = 1;
        }
    }
    else if(kierunek == 2){
        for(int i = pozycja.first, j = pozycja.second; i < 110; i++){
            if(schemat[i][j] == '-'){
                if(czy_odwiedzone[i][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(1,make_pair(i,j+1));
                laser(3,make_pair(i,j-1));
                return;
            }
            if(schemat[i][j] == '/'){
                if(schemat[i][j] == 1 && schemat[i][j-1] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(3,make_pair(i,j-1));
                return;
            }
            if(schemat[i][j] == 'l'){
                if(schemat[i][j] == 1 && schemat[i][j+1] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(1,make_pair(i,j+1));
                return;
            }
            czy_odwiedzone[i][j] = 1;
        }
    }
    else if(kierunek == 3){
        for(int i = pozycja.first, j = pozycja.second; j >= 0; j--){
            if(schemat[i][j] == '|'){
                if(czy_odwiedzone[i][j] == 1){
                    break;
                }
                czy_odwiedzone[i][j] = 1;
                laser(4,make_pair(i-1,j));
                laser(2,make_pair(i+1,j));
                return;
            }
            if(schemat[i][j] == '/'){
                if(schemat[i][j] == 1 && schemat[i+1][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(2,make_pair(i+1,j));
                return;
            }
            if(schemat[i][j] == 'l'){
                if(schemat[i][j] == 1 && schemat[i-1][j] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(4,make_pair(i-1,j));
                return;
            }
            czy_odwiedzone[i][j] = 1;
        }
    }
    else if(kierunek == 4){
        for(int i = pozycja.first, j = pozycja.second; i >= 0; i--){
            if(schemat[i][j] == '-'){
                if(czy_odwiedzone[i][j] == 1){
                    break;
                }
                czy_odwiedzone[i][j] = 1;
                laser(1,make_pair(i,j+1));
                laser(3,make_pair(i,j-1));
                return;
            }
            if(schemat[i][j] == '/'){
                if(schemat[i][j] == 1 && schemat[i][j+1] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(1,make_pair(i,j+1));
                return;
            }
            if(schemat[i][j] == 'l'){
                if(schemat[i][j] == 1 && schemat[i][j-1] == 1){
                    return;
                }
                czy_odwiedzone[i][j] = 1;
                laser(3,make_pair(i,j-1));
                return;
            }
            czy_odwiedzone[i][j] = 1;
        }
    }
}

int main(){
    char pom;
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            czy_odwiedzone[i][j] = 0;
            cin >> pom;
            schemat[i][j] = pom;
        }
    }
    czy_odwiedzone[0][0] = 1;
    laser(1,make_pair(0,0));
    int wynik = 0;
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            if(czy_odwiedzone[i][j] == 1)
                wynik++;
        }
    }
    cout << wynik;
    
}