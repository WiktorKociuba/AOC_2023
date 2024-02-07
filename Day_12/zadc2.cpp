#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ile_zep;
vector<string> schemat;
long long wynik = 0;

void wczytywanie(){
    string linia, temp, temp2;
    bool czy_koniec = 0, czy_koniec2 = 0;
    for(int j = 0;getline(cin,linia);j++){
        vector<int> pom;
        ile_zep.push_back(pom);
        for(int i = 0; i < linia.size();i++){
            if(linia[i] == ' '){
                temp = linia.substr(0,i);
                schemat.push_back(temp);
                temp = linia.substr(i+1,linia.size()-i);
                for(int z = 0; z < temp.size();z++){
                    if(isdigit(temp[z]) && isdigit(temp[z+1])){
                        ile_zep[j].push_back((temp[z]-'0')*10+(temp[z+1]-'0'));
                        z++;
                    }
                    else if(isdigit(temp[z])){
                        ile_zep[j].push_back(temp[z]-'0');
                    }
                }
                break;
            }
        }
    }
}

int isvalid(string linia, int iteracja){
    int czy_hash = 0, ile_hash = 0;
    vector<int> grupy;
    for(int i = 0; i < linia.size();i++){
        if(linia[i] == '#'){
            ile_hash++;
            czy_hash = 1;
        } 
        if((linia[i] == '.' && czy_hash == 1) || (czy_hash == 1 && i == linia.size()-1)){
            grupy.push_back(ile_hash);
            ile_hash = 0;
            czy_hash = 0;
        }
    }
    bool czy_to_samo = 1;
    if(grupy.size() == ile_zep[iteracja].size()){
        for(int i = 0; i < grupy.size(); i++){
            if(grupy[i] != ile_zep[iteracja][i]){
                czy_to_samo = 0;
            }
        }
        if(czy_to_samo){
            return 1;
        } 
    }
    return 0;

}

void zliczanie(string linia, int iteracja){
    int znaki_zap = 0;
    for(int i = 0; i < linia.size();i++){
        if(linia[i] == '?')
            znaki_zap++;
    }
    if(znaki_zap == 0){
        wynik += isvalid(linia,iteracja);
        return;
    }
    for(int i = 0; i < linia.size();i++){
        if(linia[i] == '?'){
            linia[i] = '.';
            zliczanie(linia,iteracja);
            linia[i] = '#';
            zliczanie(linia,iteracja);
            return;
        }
    }
}


int main(){
    wczytywanie();
    for(int i = 0; i < schemat.size();i++){
        string pom2 = '?' + schemat[i];
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < pom2.size();k++){
                schemat[i].push_back(pom2[k]);
                }
            }
            vector<int> pom3 = ile_zep[i];
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < pom3.size();k++){
                    ile_zep[i].push_back(pom3[k]);
                }
            }
        cout << schemat[i].substr(0,schemat[i].size()) << " ";
        for(int j = 0; j < ile_zep[i].size();j++){
            cout << ile_zep[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < schemat.size(); i++){
        zliczanie(schemat[i], i);
        cout << wynik << endl;
    }
    cout << wynik;
}