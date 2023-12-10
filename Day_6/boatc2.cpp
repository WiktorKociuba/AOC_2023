#include <bits/stdc++.h>
using namespace std;

long long czas = 0, rekord = 0;
vector<int> roz;

int main(){
    cin >> czas;
    cin >> rekord;
    long long wynik = 1;
    for(long long j = 1, lok = 0; j <= czas; j++){
        lok = j * (czas-j);
        if(lok > rekord){
            roz.push_back(j);
        }
    }
    wynik *= roz.end() - roz.begin();
    cout << wynik;
}