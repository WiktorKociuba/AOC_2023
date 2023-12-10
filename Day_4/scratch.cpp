#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> wyg;
    vector<int> liczb;
    string linia;
    int wynik = 0;
    for(int i = 0; i < 186; i++){
        wyg.clear();
        liczb.clear();
        getline(cin,linia);
        int j = 0;
        if(i < 9){
            j = 8;
        }
        else{
            j = 9;
        }
        while(linia[j] != '|')
        {
            if(!isdigit(linia[j]))
                j++;
            else{
                if(isdigit(linia[j+1])){
                    int liczba =  (linia[j]-'0')*10+linia[j+1]-'0';
                    
                    wyg.push_back(liczba);
                    j+=2;
                }
                else{
                    wyg.push_back(linia[j]-'0');
                    j++;
                }
            }
        }
        
        while(j < linia.size()){
            if(!isdigit(linia[j]))
                j++;
            else{
                if(isdigit(linia[j+1])){
                    int liczba =  (linia[j]-'0')*10+linia[j+1]-'0';
                    liczb.push_back(liczba);
                    j+=2;
                }
                else{
                    liczb.push_back(linia[j]-'0');
                    j++;
                }
            }
        }
        int wygrane = 0;
        for(int t = 0; t < liczb.size();t++){
            for(int h = 0; h < wyg.size();h++){
                if(wyg[h] == liczb[t]){
                    wygrane++;
                    //cout << wyg.size();
                }
            }
        }
        int wartosc = 0;
        if(wygrane > 0){
            wartosc = 1;
            for(int o = 1; o < wygrane; o++){
                wartosc *= 2;
            }
        }
        wynik += wartosc;
    }
    cout << wynik;
}