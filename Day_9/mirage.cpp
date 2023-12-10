#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<long long>> odczyty;
    int wynik = 0;
    for(int z = 0; z < 200; z++){
        odczyty.clear();
        long long pom = 0;
        odczyty.push_back(vector<long long>());
        for (int j = 0; j < 21; j++)
        {
            cin >> pom;
            odczyty[0].push_back(pom);
        }
        bool czy_zera = false;
            for(int i = 1; i < 21;i++){
                odczyty.push_back(vector<long long>());
                int zera = 0;
                for (int j = 0; j < odczyty[i-1].size() - 1; j++){
                    odczyty[i].push_back(odczyty[i-1][j+1] - odczyty[i-1][j]);
                    cout << odczyty[i][j] << " ";
                    if(odczyty[i][j] == 0)
                        zera++;
                }
                cout << endl;
                if(zera == odczyty[i].size())
                    break;

            }
        
        odczyty[odczyty.size()-1].push_back(0);
        for (int i = odczyty.size()-2; i >= 0; i--)
        {
            odczyty[i].push_back(odczyty[i+1][odczyty[i+1].size()-1] + odczyty[i][odczyty[i].size()-1]);
            cout << odczyty[i][odczyty[i].size()-1] << " ";
        }
        wynik += odczyty[0][odczyty[0].size()-1];
    }
    cout << wynik;
}