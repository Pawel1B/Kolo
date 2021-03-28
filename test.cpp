#include <iostream>
#include <string>

using namespace std;

class gameRules{
    public:

    int rozmiarPlanszy;
    int iloscBic;
    bool AI;
    const int defRozmiar=3;
    const int maxRozmiar=31;
    const int defilosc=3;
    const int defAI=false;//zmienić jak będzie prawdziwe AI, a nie "AI"
    void dodajZasady(){
        cout<<"Podaj rozmiar planszy (min 3): "<<endl;
        try {
            cin>>rozmiarPlanszy;
            if (rozmiarPlanszy < defRozmiar){
                cout<<"Było napisane min 3!!!"<<endl;
                rozmiarPlanszy = defRozmiar;
            }
            if (rozmiarPlanszy > maxRozmiar){
                cout<<"Bez przesady max 31x31. wpisuj od nowa"<<endl;
                rozmiarPlanszy = maxRozmiar;
            }
            cout<<"Podaj ilość w rzędzie dla wygranej: "<<endl;
            cin>>iloscBic;
            if (iloscBic < defilosc){
                cout<<"Za mało. Best I can give you is 3. wpisuj od nowa."<<endl;
                iloscBic = defilosc;
            }
            if (iloscBic > rozmiarPlanszy){
                cout<<"Nie możesz mieć więcej w rzędzie dla wygranej niż jest rzędów ... Jest ich teraz tyle samo"<<endl;
                iloscBic = rozmiarPlanszy;
            }
            if ((rozmiarPlanszy != defRozmiar)){
                cout<<"nie ma AI w tym trybie"<<endl;
            }
            else{
                cout<<"Gram przeciw AI [true] [false]"<<endl;
                cin>>AI;
            }
        }
        catch (...){
            cout<<"Error"<<endl;
        }
    }
};

class board{
    public:
    int rozmiarPlanszy;
    void initBoard(){
        int x=0;
        char numeracjaPul[rozmiarPlanszy][rozmiarPlanszy];
        for (int i=0;i<rozmiarPlanszy;i++){
            for (int j=0;j<rozmiarPlanszy;j++){
                numeracjaPul[i][j]=x;
                x++;
            }
        }
    }
    void gameBoard(int wstawianie, int gracz){
        int x=0;
        char numeracjaPul[rozmiarPlanszy][rozmiarPlanszy];
        for (int i=0;i<rozmiarPlanszy;i++){
            for (int j=0;j<rozmiarPlanszy;j++){
                if((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]=char(wstawianie))){
                    if(gracz=1){
                        numeracjaPul[i][j]='X';
                    }
                    if(gracz=2){
                        numeracjaPul[i][j]='O';
                    }
                }
                if(((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]!=char(wstawianie)))){
                    numeracjaPul[i][j]=x;
                }
                cout<<numeracjaPul[i][j];
                x++;
            }
            cout<<endl;
        }
    }
};



int main(){
    gameRules Zasady1;
    Zasady1.rozmiarPlanszy=3;
    int x=0;
    int gracz;
    board plansza;
    int rozmiarPlanszy=Zasady1.rozmiarPlanszy;
    char numeracjaPul[Zasady1.rozmiarPlanszy][Zasady1.rozmiarPlanszy];
    for (int i=0;i<Zasady1.rozmiarPlanszy;i++){
        for (int j=0;j<Zasady1.rozmiarPlanszy;j++){
            numeracjaPul[i][j]=x;
            x++;
        }
    }
    char wybierz;
    while(1){
        cout<<"Wybierz pole X: "<<endl;
        gracz=1;
        cin>>wybierz;
        int x=0;
        
        for (int i=0;i<rozmiarPlanszy;i++){
            for (int j=0;j<rozmiarPlanszy;j++){
                if((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]==wybierz)){
                    numeracjaPul[i][j]='X';
                }
                if(((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]!=wybierz))){
                    numeracjaPul[i][j]=x;
                }
                cout<<numeracjaPul[i][j];
                x++;
            }
            cout<<endl;
        }
        gracz=2;
        cout<<"Wybierz pole O: "<<endl;
        cin>>wybierz;
        x=0;
        
        for (int i=0;i<rozmiarPlanszy;i++){
            for (int j=0;j<rozmiarPlanszy;j++){
                if((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]==wybierz)){
                    numeracjaPul[i][j]='O';
                }
                if(((numeracjaPul[i][j]!='X')&&(numeracjaPul[i][j]!='O')&&(numeracjaPul[i][j]!=wybierz))){
                    numeracjaPul[i][j]=x;
                }
                cout<<numeracjaPul[i][j];
                x++;
            }
            cout<<endl;
        }
    }


//    int z;
//    cin >> z;
    return 0;

}
