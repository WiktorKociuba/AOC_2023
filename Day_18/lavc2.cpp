#include<bits/stdc++.h>
using namespace std;

#define ll __intmax_t

vector<ll> dlugosc,kierunek;
vector<pair<ll,ll>> rogi;
ll wynik = 0, bokii = 0;

void wczytywanie(){
    ll dl = 0, ki = 0;
    while(cin >> hex >> dl >> dec >> ki){
        dlugosc.push_back(dl);
        kierunek.push_back(ki);
        cout << dlugosc[dlugosc.size()-1] << " " << kierunek[kierunek.size()-1] << endl;
    }
}

void poligon(){
    pair<ll,ll> pozycja = {1,1};
    for(int i = 0; i < kierunek.size(); i++){
        if(kierunek[i] == 0){
            pozycja = {pozycja.first,pozycja.second+dlugosc[i]};
            rogi.push_back(pozycja);
        }
        else if(kierunek[i] == 1){
            pozycja = {pozycja.first+dlugosc[i],pozycja.second};
            rogi.push_back(pozycja);
        }
        else if(kierunek[i] == 2){
            pozycja = {pozycja.first,pozycja.second-dlugosc[i]};
            rogi.push_back(pozycja);
        }
        else if(kierunek[i] == 3){
            pozycja = {pozycja.first-dlugosc[i],pozycja.second};
            rogi.push_back(pozycja);
        }
    }
}

void sznurowanie(){
    for(int i = 0; i < rogi.size()-1; i++){
        wynik += (rogi[i].first*rogi[i+1].second)-(rogi[i+1].first*rogi[i].second);
        cout << wynik << endl;
    }
    wynik += (rogi[rogi.size()-1].first*rogi[0].second)-(rogi[0].first*rogi[rogi.size()-1].second);
    cout << wynik << endl;
    wynik *= 0.5;
}

void boki(){
    for(int i = 0; i < rogi.size()-1; i++){
        if(rogi[i].first == rogi[i+1].first){
            bokii += max(rogi[i].second,rogi[i+1].second) - min(rogi[i].second,rogi[i+1].second);
        }
        if(rogi[i].second == rogi[i+1].second){
            bokii += max(rogi[i].first,rogi[i+1].first) - min(rogi[i].first,rogi[i+1].first);
        }
    }
    if(rogi[rogi.size()-1].first == rogi[0].first){
        bokii += max(rogi[rogi.size()-1].second,rogi[0].second) - min(rogi[rogi.size()-1].second,rogi[0].second);
    }
    if(rogi[rogi.size()-1].second == rogi[0].second){
        bokii += max(rogi[rogi.size()-1].first,rogi[0].first) - min(rogi[rogi.size()-1].first,rogi[0].first);
    }
}

int main(){
    wczytywanie();
    poligon();
    sznurowanie();
    boki();
    cout << bokii/2+1 + abs(wynik);
}