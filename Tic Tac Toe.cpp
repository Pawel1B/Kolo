#include <iostream>
using namespace std;

char Plansza[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int checkwin()
{
       for(int i=1;i<7;i=i+3){
              if (Plansza[i] == Plansza[i+1] && Plansza[i+1] == Plansza[i+2])
              return 1;
       }
       for(int i=1;i<4;i=i+1){
              if (Plansza[i] == Plansza[i+3] && Plansza[i+3] == Plansza[i+6])
              return 1;
       }
       
       if (Plansza[1] == Plansza[5] && Plansza[5] == Plansza[9])
              return 1;
       else if (Plansza[3] == Plansza[5] && Plansza[5] == Plansza[7])
              return 1;
       else if (Plansza[1] != '1' && Plansza[2] != '2' && Plansza[3] != '3' && Plansza[4] != '4' && Plansza[5] != '5' && Plansza[6] != '6' && Plansza[7] != '7' && Plansza[8] != '8' && Plansza[9] != '9')
              return 0;
       else
              return -1;
}
void board()
{
       system("cls");
       cout << "Gracz 1 [X]  -  Gracz 2 [O]" << endl ;
       cout << endl;
       cout << "     |     |     " << endl;
       cout << "  " << Plansza[1] << "  |  " << Plansza[2] << "  |  " << Plansza[3] << endl;
       cout << "_____|_____|_____" << endl;
       cout << "     |     |     " << endl;
       cout << "  " << Plansza[4] << "  |  " << Plansza[5] << "  |  " << Plansza[6] << endl;
       cout << "_____|_____|_____" << endl;
       cout << "     |     |     " << endl;
       cout << "  " << Plansza[7] << "  |  " << Plansza[8] << "  |  " << Plansza[9] << endl;
       cout << "     |     |     " << endl << endl;
}
int main()
{
       int player = 1, i, choice;
       char mark;
       do
       {
              board();
              player = (player % 2) ? 1 : 2;
              cout << "Gracz " << player << ", wpisz pozycje:  ";
              cin >> choice;
              mark = (player == 1) ? 'X' : 'O';
              int sent=0;
              for (int i=1;i<10;i++){
                     if (choice==i&&Plansza[i]==char(i+48)) {
                            Plansza[i] = mark;sent=1;
                            }
              }
              if(sent==0)
              {
                     cout << "Niepoprawny ruch ";
                     player--;
                     cin.ignore();
                     cin.get();
              }
              i = checkwin();
              player++;
       } while (i == -1);
       board();
       if (i == 1)
              cout << "==>\aGracz " << --player << " wygrywa ";
       else
              cout << "==>\aRemis";
       cin.ignore();
       cin.get();
       return 0;
}





