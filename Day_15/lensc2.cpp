#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<string,int>>> box(256);

int hashing(string linia){
    int wynik_lok = 0;
    for(int i = 0; i < linia.size(); i++){
        wynik_lok += int(linia[i]);
        wynik_lok = wynik_lok * 17;
        wynik_lok = wynik_lok % 256;
    }
    return wynik_lok;
}

int main(){
    string linia;
    getline(cin,linia);
    int ost_przec = 0,wynik = 0;
    for(int i = 0; i < linia.size();i++){
        if(linia[i] == ',' && i != 0){
            string pom = linia.substr(ost_przec+1,i-ost_przec-1);
            if(pom[pom.size()-1] == '-'){
                int pud = hashing(pom.substr(0,pom.size()-1));
                for(int j = 0; j < box[pud].size();j++){
                    if(box[pud][j].first.substr(0,box[pud][j].first.size()) == pom.substr(0,pom.size()-1)){
                        box[pud].erase(box[pud].begin()+j);
                        break;
                    }
                }
            }
            if(isdigit(pom[pom.size()-1])){
                int pud = hashing(pom.substr(0,pom.size()-2));
                bool czy = 1;
                for(int j = 0; j < box[pud].size();j++){
                    if(box[pud][j].first.substr(0,box[pud][j].first.size()) == pom.substr(0,pom.size()-2)){
                        box[pud][j].second = pom[pom.size()-1]-'0';
                        czy = 0;
                        break;
                    }
                }
                if(czy)
                    box[pud].push_back(make_pair(pom.substr(0,pom.size()-2),pom[pom.size()-1]-'0'));
            }
            ost_przec = i;
        }
    }
    for(int i = 0; i < box.size();i++){
        for(int j = 0; j < box[i].size();j++){
            wynik += (i+1) * (j+1) * box[i][j].second;
        }
    }
    cout << wynik;
}