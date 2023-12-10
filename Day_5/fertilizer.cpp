#include <bits/stdc++.h>
using namespace std;

long long potrzeb_nas[20];
long long do_nas[20];

int main(){
    for(int i = 0; i < 20; i++){
        long long y;
        cin >> y;
        //cout << y << " ";
        potrzeb_nas[i] = y;
        do_nas[i] = y; 
    }
    for (int i = 0; i < 7; i++){
        for(int i = 0; i < 20; i++){
        potrzeb_nas[i] = do_nas[i];
        }
        long long pierwsza = 0, druga = 0, trzecia = 0;
        string linia,cz1,cz2,cz3;
        int p_sp = 0, d_sp = 0;
        getline(cin,linia);
        while(getline(cin,linia)){
            //cout << "tu" << endl;
            if(linia.empty())
                break;
            p_sp = 0, d_sp = 0;
            pierwsza = 0, druga = 0, trzecia = 0;
            for(int u = 0; u < linia.size();u++){
                if(linia[u] == ' '){
                    if(p_sp == 0){
                        p_sp = u;
                    }
                    else{
                        d_sp = u;
                    }
                }
            }
            cz1 = linia.substr(0,p_sp);
            cz2 = linia.substr(p_sp+1,d_sp-p_sp-1);
            cz3 = linia.substr(d_sp+1,linia.size() - d_sp);
            //cout << cz1.substr(0,cz1.size()) << "x" << cz2.substr(0,cz2.size()) << "y" << cz3.substr(0,cz3.size()) << p_sp << " " << d_sp <<endl;
            for(int f = 0,d = cz1.size()-1; f < cz1.size()-1;f++,d--){
                pierwsza += (cz1[f]-'0')*pow(10,d);
            }
            pierwsza += cz1[cz1.size()-1]-'0';
            for(int f = 0,d = cz2.size()-1; f < cz2.size()-1;f++,d--){
                druga += (cz2[f]-'0')*pow(10,d);
            }
            druga += cz2[cz2.size()-1]-'0';
            for(int f = 0,d = cz3.size()-1; f < cz3.size()-1;f++,d--){
                trzecia += (cz3[f]-'0')*pow(10,d);
            }
            trzecia += cz3[cz3.size()-1]-'0';
            cout << pierwsza << " " << druga << " " << trzecia << endl;
            int pom = 0;
            for(int j = 0; j < 20; j++){
                if(potrzeb_nas[j] >= druga && potrzeb_nas[j] < druga+trzecia){
                    pom = potrzeb_nas[j] - druga;
                    do_nas[j] = pierwsza + pom;
                }
            }
        
        }
        //cout << "koniec" << endl;

    }
    long long pom = LONG_LONG_MAX;
    for(int i = 0; i < 20; i++){
        pom = min(pom, do_nas[i]);
    }
    cout << pom;
}