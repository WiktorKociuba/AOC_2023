#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> karty,rank1,rank2,rank3,rank4,rank5,rank6,rank7,reka;
//vector<int> bid,bid1,bid2,bid3,bid4,bid5,bid6,bid7;
int rank_number = 1;

void jaka_karta(char karta, int numer,int nrkr){
    if(karta == 'A'){
        karty[numer][0]++;
        reka[numer][nrkr] = 0;
    }
    else if(karta == 'K'){
        karty[numer][1]++;
        reka[numer][nrkr] = 1;
    }
    else if(karta == 'Q'){
        karty[numer][2]++;
        reka[numer][nrkr] = 2;    
    }
    else if(karta == 'T'){
        karty[numer][3]++;
        reka[numer][nrkr] = 3;
    }
    else if(karta == '9'){
        karty[numer][4]++;
        reka[numer][nrkr] = 4;    
    }
    else if(karta == '8'){
        karty[numer][5]++;
        reka[numer][nrkr] = 5;    
    }
    else if(karta == '7'){
        karty[numer][6]++;
        reka[numer][nrkr] = 6;    
    }
    else if(karta == '6'){
        karty[numer][7]++;
        reka[numer][nrkr] = 7;    
    }
    else if(karta == '5'){
        karty[numer][8]++;
        reka[numer][nrkr] = 8;    
    }
    else if(karta == '4'){
        karty[numer][9]++;
        reka[numer][nrkr] = 9;    
    }
    else if(karta == '3'){
        karty[numer][10]++;
        reka[numer][nrkr] = 10;    
    }
    else if(karta == '2'){
        karty[numer][11]++;
        reka[numer][nrkr] = 11;}
    else if(karta == 'J'){
        karty[numer][12]++;
        reka[numer][nrkr] = 12;
    }
}

void sprawdzanie_typu(int numer){
    bool czy_piec = 0, czy_cztery = 0, full = 0, three_of_kind = 0, high_card = 0, two_pair = 0, one_pair = 0;
    int najmniej = 10, najwiec = 0, ile_par = 0;
    for(int i = 0; i < 12; i++){
        if(karty[numer][i] > 0){
            if(karty[numer][i] == 2){
                ile_par++;
            }
            najmniej = min(najmniej,karty[numer][i]);
            najwiec = max(najwiec,karty[numer][i]);
        }
    }
    //cout << najmniej << " " << najwiec<< endl;
    if(najwiec + karty[numer][12]== 5){
        czy_piec = 1;
    }
    else if(najwiec + karty[numer][12]== 4){
        czy_cztery = 1;
    }
    else if((najwiec == 3 && najmniej == 2 )||(najwiec == 2 && najmniej == 2 && karty[numer][12] == 1)){
        full = 1;
    }
    else if(najwiec == 3 && najmniej == 1||(najwiec == 2 && najmniej == 1 && karty[numer][12] == 1)|| (najwiec == 1 && najmniej == 1 && karty[numer][12] == 2||karty[numer][12] == 3)){
        three_of_kind = 1;
    }
    else if(ile_par + karty[numer][12] == 2){
        two_pair = 1;
    }
    else if((ile_par + karty[numer][12] == 1 && najwiec == 1 && najmniej == 1 )||(ile_par == 1 && najwiec == 2 && najmniej == 1)){
        one_pair = 1;
    }
    else if(najwiec == 1 && najmniej == 1 && karty[numer][12] ==0){
        high_card = 1;
    }
    //cout << "tu" << endl;
    if(high_card){
        rank1.push_back(reka[numer]);
    }
    else if(one_pair){
        rank2.push_back(reka[numer]);
    }
    else if(two_pair){
        rank3.push_back(reka[numer]);
    }
    else if(three_of_kind){
        rank4.push_back(reka[numer]);
    }
    else if(full){
        rank5.push_back(reka[numer]);
    }
    else if(czy_cztery){
        rank6.push_back(reka[numer]);
    }
    else if(czy_piec){
        rank7.push_back(reka[numer]);
    }
}

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{   
    if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2] && v1[3] == v2[3])
        return v1[4] > v2[4];
    else if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2])
        return v1[3] > v2[3];
    else if(v1[0] == v2[0] && v1[1] == v2[1])
        return v1[2] > v2[2];
    else if(v1[0] == v2[0])
        return v1[1] > v2[1];
    else
        return v1[0] > v2[0];
}


int main(){
    string linia;
    for(int i = 0; i < 1000; i++){
        karty.push_back({0,0,0,0,0,0,0,0,0,0,0,0,0});
        reka.push_back({0,0,0,0,0});
    }
    for(int i = 0; i < 1000; i++){
        getline(cin,linia);
        //rece.push_back(linia.substr(0,5));
        for(int j = 0; j < 5; j++){
            jaka_karta(linia[j],i,j);
        }
        
        int temp = 0;
        for(int j = linia.size()-7, k = 6; k < linia.size()-1 && j >= 1;j--,k++){
            temp += (linia[k]-'0')*pow(10,j);
        }
        temp += linia[linia.size()-1]-'0';
        //bid.push_back(temp);
        reka[i].push_back(temp);
       /*for (int j = 0; j < 5; j++){
            cout << reka[i][j] << " ";
        }
        cout << endl;*/
    }
    for(int i = 0; i < 1000; i++){
        sprawdzanie_typu(i);
    }
    sort(rank1.begin(), rank1.end(), sortcol);
    sort(rank2.begin(), rank2.end(), sortcol);
    sort(rank3.begin(), rank3.end(), sortcol);
    sort(rank4.begin(), rank4.end(), sortcol);
    sort(rank5.begin(), rank5.end(), sortcol);
    sort(rank6.begin(), rank6.end(), sortcol);
    sort(rank7.begin(), rank7.end(), sortcol);
    /*for(int i = 0; i < rank6.size();i++){
        for (int j = 0; j < 6; j++)
        {
            cout << rank6[i][j] << " ";
        }
        cout << endl;
    }*/
    long long wynik = 0;
    for (int i = 0; i < rank1.size(); i++)
    {
        wynik += rank1[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank1[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank2.size(); i++)
    {
        wynik += rank2[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank2[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank3.size(); i++)
    {
        wynik += rank3[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank3[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank4.size(); i++)
    {
        wynik += rank4[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank4[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank5.size(); i++)
    {
        wynik += rank5[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank5[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank6.size(); i++)
    {
        wynik += rank6[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank6[i][j] << " ";
        cout << endl;
    }
    cout << "koniec" << endl;
    for (int i = 0; i < rank7.size(); i++)
    {
        wynik += rank7[i][5] * rank_number;
        rank_number++;
        for(int j = 0; j < 6; j++)
        cout << rank7[i][j] << " ";
        cout << endl;
    }
    cout << rank_number << " ";
    cout << wynik;
}