#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> lustro;
int wynik = 0, lok = 0, wynik_lok = 0;
bool czy_poziomo = 0;

void wczytywanie(){
    lustro.clear();
    string linia;
    bool czy_puste = 0;
    for(int i = 0;!czy_puste;i++){
        getline(cin,linia);
        if(linia.empty()){
            czy_puste = 1;
            break;
        }
        vector<char> pom;
        lustro.push_back(pom);
        for(int j = 0; j < linia.size();j++){
            lustro[i].push_back(linia[j]);
        }
        
    }
}

void poziomo(){
    int srodek = 0;
    bool niesymetryczne = 0, symetryczne = 0;
    for(int i = 0; i < lustro.size()-1;i++){
        niesymetryczne = 0;
        symetryczne = 0;
        bool czy_to_samo = 1;
        for(int j = 0 ;j<lustro[i].size();j++){
            if(lustro[i][j] != lustro[i+1][j]){
                czy_to_samo = 0;
                break;
            }
        }
        if(czy_to_samo){
            srodek = i+1;
            for(int j = i, k = srodek; j >= 0 && k < lustro.size(); j--,k++){
                for(int z = 0; z < lustro[j].size();z++){
                    if(lustro[j][z] != lustro[k][z]){
                        niesymetryczne = 1;
                        break;
                    }
                }
            }
            if(!niesymetryczne){
                    symetryczne = 1;
                    break;
                    
                }
        }
    }
    if(symetryczne){
        wynik += srodek*100;
        czy_poziomo = 1;
    }
}

void pionowo(){
    int srodek = 0;
    bool niesymetryczne = 0, czy_to_samo = 1, symetryczne = 0;
    for(int i = 0; i < lustro[0].size();i++){
        czy_to_samo = 1;
        niesymetryczne =0;
        symetryczne = 0;
        for(int j = 0; j < lustro.size(); j++){
            if(lustro[j][i] != lustro[j][i+1]){
                czy_to_samo = 0;
                break; 
            }
        }
        if(czy_to_samo){
            
            srodek = i+1;
            for(int j = i, k = srodek; j >= 0 && k < lustro[0].size(); j--,k++){
                for(int z = 0; z < lustro.size();z++){
                    if(lustro[z][j] != lustro[z][k]){
                        niesymetryczne = 1;
                        break;
                    }
                }
            }
            if(!niesymetryczne){
                    symetryczne = 1;
                    break;
                }
        }
    }
    if(symetryczne){
        wynik += srodek;
    }
}

int main(){
    for(int i = 0; true;i++){
        lok = 0;
        wczytywanie();
        if(lustro.empty())
            break;
        poziomo();
        pionowo();
        cout << wynik << endl;
    }
   cout << wynik << endl;
}