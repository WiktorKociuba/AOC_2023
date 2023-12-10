#include <bits/stdc++.h>
using namespace std;

char rury[140][140];
pair<int,int> pozycja_startu;

pair<int,int> gdzie_isc(int i, int j,int si, int sj){
    if(rury[i][j] == '|' && si == i +1 && sj == j)
        return {i-1,j};
    else if(rury[i][j] == '|')
        return {i+1,j};
    else if(rury[i][j] == '-' && si == i && sj == j+1)
        return {i,j-1};
    else if(rury[i][j] == '-')
        return {i,j+1};
    else if(rury[i][j] == 'L' && si == i-1 && sj == j)
        return {i,j+1};
    else if(rury[i][j] == 'L')
        return {i-1,j};
    else if(rury[i][j] == 'J' && si == i-1 && sj == j)
        return {i,j-1};
    else if(rury[i][j] == 'J')
        return {i-1,j};
    else if(rury[i][j] == '7' && si == i+1 && sj == j)
        return {i,j-1};
    else if(rury[i][j] == '7')
        return {i+1,j};
    else if(rury[i][j] == 'F' && si == i+1 && sj == j)
        return {i,j+1};
    else if(rury[i][j] == 'F')
        return {i+1,j};
    return {i+1,j};
}

int main(){
    for(int i = 0; i < 140; i++)
        for(int j = 0; j < 140; j++){
            cin >> rury[i][j];
            if(rury[i][j] == 'S')
                pozycja_startu = {i,j};
        }
    pair<int,int> pozycja1 = {pozycja_startu.first,pozycja_startu.second-1}, pozycja2 = {pozycja_startu.first-1,pozycja_startu.second}, pozycja1_wcze = pozycja_startu, pozycja2_wcze = pozycja_startu;
    int wynik = 1;
    while(pozycja1 != pozycja2){
        pair<int,int> pom;
        pom = pozycja1;
        pozycja1 = gdzie_isc(pozycja1.first,pozycja1.second,pozycja1_wcze.first,pozycja1_wcze.second);
        pozycja1_wcze = pom;
        pom = pozycja2;
        pozycja2 = gdzie_isc(pozycja2.first,pozycja2.second,pozycja2_wcze.first,pozycja2_wcze.second);
        pozycja2_wcze = pom;
        wynik++;
    }
    cout << wynik;
}