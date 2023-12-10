#include <bits/stdc++.h>
using namespace std;

char rury[140][140];
pair<int,int> pozycja_startu;

pair<int,int> gdzie_isc(int i, int j,int si, int sj){
    if(rury[i][j] == '|' && si == i +1 && sj == j){
        rury[i][j] = 'a';
        return {i-1,j};
    }
    else if(rury[i][j] == '|'){
        rury[i][j] = 'a';
        return {i+1,j};
    }
    else if(rury[i][j] == '-' && si == i && sj == j+1){
        rury[i][j] = 'b';
        return {i,j-1};
    }    
    else if(rury[i][j] == '-'){
        rury[i][j] = 'b';
        return {i,j+1};
    }
    else if(rury[i][j] == 'L' && si == i-1 && sj == j){
        rury[i][j] = 'd';
        return {i,j+1};
    }
    else if(rury[i][j] == 'L'){
        rury[i][j] = 'g';
        return {i-1,j};
    }
    else if(rury[i][j] == 'J' && si == i-1 && sj == j){
        rury[i][j] = 'd';
        return {i,j-1};
    }
    else if(rury[i][j] == 'J'){
        rury[i][j] = 'g';
        return {i-1,j};
    }
    else if(rury[i][j] == '7' && si == i+1 && sj == j){
        rury[i][j] = 'g';
        return {i,j-1};
    }
    else if(rury[i][j] == '7'){
        rury[i][j] = 'd';
        return {i+1,j};
    }
    else if(rury[i][j] == 'F' && si == i+1 && sj == j){
        rury[i][j] = 'g';
        return {i,j+1};
    }
    else if(rury[i][j] == 'F'){
        rury[i][j] = 'd';
        return {i+1,j};
    }
    return {i+1,j};
}

int ile_plytek(){
    int wynik = 0;
    bool czy_w_srodku = 0;
    for(int i = 0; i < 140; i++,czy_w_srodku = 0)
        for(int j = 0; j < 140; j++){
            if((rury[i][j] == 'a' && czy_w_srodku == 0) || (rury[i][j] == 'd' && rury[i][j+1] != 'b'))
                czy_w_srodku = 1;
            else if((rury[i][j] == 'a' && czy_w_srodku == 1) || (rury[i][j] == 'g' && rury[i][j+1] != 'b'))
                czy_w_srodku = 0;
            if((rury[i][j] != 'a' && rury[i][j] != 'b' && rury[i][j] != 'd' && rury[i][j] != 'g') && czy_w_srodku == 1)
                wynik++;
        }
    return wynik;
}

int main(){
    for(int i = 0; i < 140; i++)
        for(int j = 0; j < 140; j++){
            cin >> rury[i][j];
            if(rury[i][j] == 'S')
                pozycja_startu = {i,j};
        }
    pair<int,int> pozycja = {pozycja_startu.first,pozycja_startu.second-1}, pozycja_wcze = pozycja_startu;
    int wynik = 1;
    while(pozycja != pozycja_startu){
        pair<int,int> pom;
        pom = pozycja;
        pozycja = gdzie_isc(pozycja.first,pozycja.second,pozycja_wcze.first,pozycja_wcze.second);
        pozycja_wcze = pom;
        wynik++;
    }
    rury[pozycja_startu.first][pozycja_startu.second] = 'g';
    cout << ile_plytek();
    return 0;
}