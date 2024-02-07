#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int roz = 5;
vector<pair<int,ll>> graf[(roz*roz)+1];
bool odw[(roz*roz)+1];
ll odl[(roz*roz)+1];
int schemat[roz][roz];

//kierunki: 1 - w lewo, 2 - w prawo, 3 - w gore, 4 - w dol
//odleglosc,nr_wierzcholka,dlugosc,kierunek

void dijkstra(){
    odl[1] = 0;
    priority_queue<pair<ll,pair<int,pair<int,int>>>> q;
    q.push(make_pair(0,make_pair(1,make_pair(1,0))));
    while(q.size()){
        int wierzcholek = q.top().second.first, dlugosc = q.top().second.second.first, kierunek = q.top().second.second.second;
        q.pop();
        if(odw[wierzcholek] || dlugosc > 3){
            continue;
        }
        odw[wierzcholek] = true;
        for(auto i : graf[wierzcholek]){
            if(kierunek == 0 && odl[i.first] > odl[wierzcholek] + i.second){
                odl[i.first] = odl[wierzcholek] + i.second;
                if(i.first == wierzcholek+1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,2))));
                }
                if(i.first == wierzcholek+roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,4))));
                }
            }
            if(kierunek == 1 && i.first != wierzcholek+1 && odl[i.first] > odl[wierzcholek] + i.second){
                odl[i.first] = odl[wierzcholek] + i.second;
                if(i.first == wierzcholek-1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,1))));
                }
                if(i.first == wierzcholek+roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,4))));
                }
                if(i.first == wierzcholek-roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,3))));
                }
            }
            if(kierunek == 2 && i.first != wierzcholek-1 && odl[i.first] > odl[wierzcholek] + i.second){
                odl[i.first] = odl[wierzcholek] + i.second;
                if(i.first == wierzcholek+1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,2))));
                }
                if(i.first == wierzcholek+roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,4))));
                }
                if(i.first == wierzcholek-roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,3))));
                }
            
            }
            if(kierunek == 3 && i.first != wierzcholek+roz && odl[i.first] > odl[wierzcholek] + i.second){
                odl[i.first] = odl[wierzcholek] + i.second;
                if(i.first == wierzcholek+1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,2))));
                }
                if(i.first == wierzcholek-1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,1))));
                }
                if(i.first == wierzcholek-roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,3))));
                }
            
            }
            if(kierunek == 4 && i.first != wierzcholek-roz && odl[i.first] > odl[wierzcholek] + i.second){
                odl[i.first] = odl[wierzcholek] + i.second;
                if(i.first == wierzcholek+1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,2))));
                }
                if(i.first == wierzcholek-1){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(1,1))));
                }
                if(i.first == wierzcholek+roz){
                    q.push(make_pair(-odl[i.first],make_pair(i.first,make_pair(dlugosc+1,4))));
                }
            }
        }

    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string linia;
    for(int i = 0; i < roz; i++){
        getline(cin,linia);
        for(int j = 0; j < roz; j++){
            schemat[i][j] = linia[j]-'0';
        }
    }
    int wierzcholek = 1;
    for(int i = 0; i<roz;i++){
        for(int j = 0; j < roz; j++,wierzcholek++){
            odw[wierzcholek] = false;
            odl[wierzcholek] = LONG_LONG_MAX;
            if(i+1 < roz)
                graf[wierzcholek].push_back(make_pair(wierzcholek+roz,schemat[i+1][j]));
            if(i-1 >=0)
                graf[wierzcholek].push_back(make_pair(wierzcholek-roz,schemat[i-1][j]));
            if(j+1 < roz)
                graf[wierzcholek].push_back(make_pair(wierzcholek+1,schemat[i][j+1]));
            if(j-1 >= 0)
                graf[wierzcholek].push_back(make_pair(wierzcholek-1,schemat[i][j-1]));
        }
    }
    dijkstra();
    int pom = 0;
    for(int i = 1; i <=roz*roz;i++,pom++ ){
        cout << odl[i] << " ";
    }
}