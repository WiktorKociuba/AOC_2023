#include <bits/stdc++.h>
using namespace std;

map<string,pair<string,string>> mapa;
vector<string> indexy;
vector<bool> instrukcje;

int main(){
    string linia;
    getline(cin,linia);
    for(int i = 0; i < linia.size();i++)
        if(linia[i] == 'L')
            instrukcje.push_back(0);
        else
            instrukcje.push_back(1);
    pair<string,string> pom;
    while(getline(cin,linia)){
        pom = make_pair(linia.substr(7,3),linia.substr(12,3));
        mapa[linia.substr(0,3)] = pom;
        indexy.push_back(linia.substr(0,3));
    }
    bool czy_roz = 0;
    vector<string> akt_klucz;
    for (int i = 0; i < indexy.size(); i++)
        if(indexy[i][2] == 'A')
            akt_klucz.push_back(indexy[i]);
    long long wynik = 0, wynik_p1, wyniki[akt_klucz.size()];
    for(int k = 0; k < akt_klucz.size();k++){
        czy_roz = 0;
        wynik = 0;
        while(!czy_roz)
            for(int i = 0; i < instrukcje.size() ; i++){
                if(instrukcje[i] == 0)
                    akt_klucz[k] = mapa[akt_klucz[k]].first;
                else
                    akt_klucz[k] = mapa[akt_klucz[k]].second;
                wynik++;
                if(akt_klucz[k][2] == 'Z'){
                    wyniki[k] = wynik;
                    czy_roz = true;
                    break;
                }
            }
        if(k == 0)
            wynik_p1 = wynik;
    }
    wynik = lcm(wyniki[0],lcm(wyniki[1],lcm(wyniki[2],lcm(wyniki[3],lcm(wyniki[4],wyniki[5])))));
    cout << "Part one: " << wynik_p1 << endl << "Part two: " << wynik << endl;
    return 0;
}