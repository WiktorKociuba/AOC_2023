#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kosmos;
int ile_kolumn = 140, ile_wierszy = 140;
vector<pair<int,int>> galaktyki;

void wyp_kol(){
    bool czy_pusta = 1;
    for(int j = 0; j < ile_kolumn; j++){
        czy_pusta = 1;
        for(int i = 0; i < ile_wierszy; i++){
            if(kosmos[i][j] == 1)
                czy_pusta = 0;
        }
        if(czy_pusta){
            ile_kolumn++;
            for(int i = 0; i < ile_wierszy; i++){
                vector<int>::iterator it = kosmos[i].begin();
                advance(it,j);
                kosmos[i].insert(it,0);
            }
            j++;
        }
    }
}

void wyp_rz(){
    bool czy_pusta = 1;
    ile_wierszy = 140;
    for(int j = 0; j < ile_wierszy; j++){
        czy_pusta = 1;
        for(int i = 0; i < kosmos[j].size(); i++){
            if(kosmos[j][i] == 1)
                czy_pusta = 0;
        }
        if(czy_pusta){
            vector<vector<int>>::iterator it = kosmos.begin();
            advance(it,j);
            vector<int> pom;
            for(int i = 0; i < kosmos[j].size();i++){
                pom.push_back(0);
            }
            kosmos.insert(it,pom);
            ile_wierszy++;
            j++;
        }
    }
}

int main(){
    char pom;
    for(int i = 0; i < 140; i++){
        kosmos.push_back(vector<int>());
        for(int j = 0; j < 140; j++){
            cin >> pom;
            if(pom == '.')
                pom = 0;
            else
                pom = 1;
            kosmos[i].push_back(pom);
        }
    }
    wyp_kol();
    wyp_rz();
    cout << ile_kolumn << " " << ile_wierszy <<endl;
    for(int i = 0; i < ile_wierszy; i++){
        for(int j = 0; j < ile_kolumn; j++){
            if(kosmos[i][j] == 1)
                galaktyki.push_back({i,j});
        }
    }
    int wynik = 0;
    for(int i = 0; i < galaktyki.size();i++){
        for(int j = i+1; j < galaktyki.size();j++){
            int x1 = galaktyki[i].first, y1 = galaktyki[i].second,x2 = galaktyki[j].first, y2 = galaktyki[j].second;
            wynik += (max(x1,x2) - min(x1,x2))+(max(y1,y2) - min(y1,y2));
            cout << wynik << endl;
        }
    }
    cout << wynik;
}