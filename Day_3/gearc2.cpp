#include <bits/stdc++.h>
using namespace std;

char silnik[142][142];
vector<int> cor;

bool czy_dwa(int i, int j){
    int ile_liczb = 0;
    //cout << 1 << " ";
    if(isdigit(silnik[i][j+1])){
        ile_liczb++;
    }
    if(isdigit(silnik[i][j-1])){
        ile_liczb++;
    }
    if(isdigit(silnik[i+1][j-1]) && !isdigit(silnik[i+1][j]) && isdigit(silnik[i+1][j+1])){
        ile_liczb += 2;
    }
    else{
        if(isdigit(silnik[i+1][j-1])){
            ile_liczb++;
        }
        else if(isdigit(silnik[i+1][j])){
            ile_liczb++;
        }
        else if(isdigit(silnik[i+1][j+1])){
            ile_liczb++;
        }
    }
    if(isdigit(silnik[i-1][j-1]) && !isdigit(silnik[i-1][j]) && isdigit(silnik[i-1][j+1])){
        ile_liczb += 2;
    }
    else{
        if(isdigit(silnik[i-1][j-1])){
            ile_liczb++;
        }
        else if(isdigit(silnik[i-1][j])){
            ile_liczb++;
        }
        else if(isdigit(silnik[i-1][j+1])){
            ile_liczb++;
        }
    }
    if(ile_liczb == 2){
        return true;
    }
    return false;

}

void liczba(int i, int j){
    if(isdigit(silnik[i][j+1])){
        cor.push_back(i);
        cor.push_back(j+1);
    }
    if(isdigit(silnik[i][j-1])){
        cor.push_back(i);
        cor.push_back(j-1);
    }
    if(isdigit(silnik[i-1][j-1]) && isdigit(silnik[i-1][j+1]) && silnik[i-1][j] == '.'){
        cor.push_back(i-1);
        cor.push_back(j-1);
        cor.push_back(i-1);
        cor.push_back(j+1);
    }
    else if(isdigit(silnik[i-1][j])){
        cor.push_back(i-1);
        cor.push_back(j);
    }
    else if(isdigit(silnik[i-1][j-1])){
        cor.push_back(i-1);
        cor.push_back(j-1);
    }
    else if(isdigit(silnik[i-1][j+1])){
        cor.push_back(i-1);
        cor.push_back(j+1);
    }
    if(isdigit(silnik[i+1][j-1]) && isdigit(silnik[i+1][j+1]) && silnik[i+1][j] == '.'){
        cor.push_back(i+1);
        cor.push_back(j-1);
        cor.push_back(i+1);
        cor.push_back(j+1);
    }
    else if(isdigit(silnik[i+1][j-1])){
        cor.push_back(i+1);
        cor.push_back(j-1);
    }
    else if(isdigit(silnik[i+1][j+1])){
        cor.push_back(i+1);
        cor.push_back(j+1);
    }
    else if(isdigit(silnik[i+1][j])){
        cor.push_back(i+1);
        cor.push_back(j);
    }
}

int main(){
    
    for (int i = 0; i < 142; i++){
        for (int j = 0; j < 142; j++){
            cin >> silnik[i][j];
        }
    }

    int pierwsza = 0, druga = 0, trzecia = 0,p = 0, d = 0;
    long long wynik = 0;
    for (int i = 1; i < 142; i++){
        for (int j = 1; j < 142; j++){
            if(silnik[i][j] == '*'){
                cor.clear();
                if(czy_dwa(i,j)){
                        liczba(i,j);
                        if(isdigit(silnik[cor[0]][cor[1]-1]) && isdigit(silnik[cor[0]][cor[1]+1])){
                            pierwsza = (silnik[cor[0]][cor[1]-1]-48)*100;
                            druga = (silnik[cor[0]][cor[1]]-48)*10;
                            trzecia = silnik[cor[0]][cor[1]+1]-48;
                            p = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[0]][cor[1]-1]) && isdigit(silnik[cor[0]][cor[1]-2])){
                            pierwsza = (silnik[cor[0]][cor[1]-2]-48)*100;
                            druga = (silnik[cor[0]][cor[1]-1]-48)*10;
                            trzecia = silnik[cor[0]][cor[1]]-48;
                            p = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[0]][cor[1]-1])){
                            pierwsza = (silnik[cor[0]][cor[1]-1]-48)*10;
                            druga = silnik[cor[0]][cor[1]]-48;
                            p = pierwsza+druga;
                        }
                        else if(isdigit(silnik[cor[0]][cor[1]+1]) && isdigit(silnik[cor[0]][cor[1]+2])){
                            pierwsza = (silnik[cor[0]][cor[1]]-48)*100;
                            druga = (silnik[cor[0]][cor[1]+1]-48)*10;
                            trzecia = silnik[cor[0]][cor[1]+2]-48;
                            p = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[0]][cor[1]+1])){
                            pierwsza = (silnik[cor[0]][cor[1]]-48)*10;
                            druga = silnik[cor[0]][cor[1]+1]-48;
                            p = pierwsza+druga;
                        }
                        else{
                            p = silnik[cor[0]][cor[1]]-48;
                        }
                        if(isdigit(silnik[cor[2]][cor[3]-1]) && isdigit(silnik[cor[2]][cor[3]+1])){
                            pierwsza = (silnik[cor[2]][cor[3]-1]-48)*100;
                            druga = (silnik[cor[2]][cor[3]]-48)*10;
                            trzecia = silnik[cor[2]][cor[3]+1]-48;
                            d = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[2]][cor[3]-1]) && isdigit(silnik[cor[2]][cor[3]-2])){
                            pierwsza = (silnik[cor[2]][cor[3]-2]-48)*100;
                            druga = (silnik[cor[2]][cor[3]-1]-48)*10;
                            trzecia = silnik[cor[2]][cor[3]]-48;
                            d = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[2]][cor[3]-1])){
                            pierwsza = (silnik[cor[2]][cor[3]-1]-48)*10;
                            druga = silnik[cor[2]][cor[3]]-48;
                            d = pierwsza+druga;
                        }
                        else if(isdigit(silnik[cor[2]][cor[3]+1]) && isdigit(silnik[cor[2]][cor[3]+2])){
                            pierwsza = (silnik[cor[2]][cor[3]]-48)*100;
                            druga = (silnik[cor[2]][cor[3]+1]-48)*10;
                            trzecia = silnik[cor[2]][cor[3]+2]-48;
                            d = pierwsza+druga+trzecia;
                        }
                        else if(isdigit(silnik[cor[2]][cor[3]+1])){
                            pierwsza = (silnik[cor[2]][cor[3]]-48)*10;
                            druga = silnik[cor[2]][cor[3]+1]-48;
                            d = pierwsza+druga;
                        }
                        else{
                            d = silnik[cor[2]][cor[3]]-48;
                        }
                        wynik += p*d;
                }
            }
        }    
    }
    cout << wynik;
}