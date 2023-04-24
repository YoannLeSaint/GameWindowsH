/*
1) efface l'écran
2)
######################################################





                    Welcome in my game





######################################################

3) Lance

######################################################  SCORE
                                                        Joueur 1:
                                                        Joueur 2:
  00


                    10





######################################################
Joueur Humain Position x, y : 2,3

Le jeu va faire un random de 9 chiffres qu'il va mettre partout sur la gille de jeu
Quand le joueur tombe sur une coordonnée juste il gagne le nombre de point affiché
L'IA joue aussi aléatoirement
Il est possible de jouer une case déjà jouée
Le gagnant est celui qui arrive le premier à la moitier +1 de la moyenne de la somme des nombre en jeu

A chaque fois qu'un joueur joue la ligne du bas est completement réecrite
Utilisez des couleurs pour les 0 et de plus en plus chaud quand on arrive à 9

*/

#include <string>
#include <ostream>
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

const int lenght = 50;
const int row = 10;

void gotoxy(int x, int y){
    COORD c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

void displayStart(int row, int lenght){
    cout << setfill('#') << setw(lenght) << "" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < lenght; j++){
            cout << "~";
        }
        cout << endl;
    }
    cout << setfill('#') << setw(lenght) << "" << endl;
}

void init(int tab[][row], int lenght, int row){
    system("cls");
    default_random_engine gen(time(0));
    uniform_int_distribution<int> distr1(0, lenght);
    uniform_int_distribution<int> distr2(0, row);

    for (int i = 0; i < lenght; i++){
        for (int j = 0; j < row; j++){
            tab[i][j] = 0;
        }
    }
    for (int number = 1; number < 10; number++){
        while(true){
            int randX = distr1(gen);
            int randY = distr2(gen);
            if (tab[randX][randY] == 0){
                tab[randX][randY] = number;
                break;
            }
        }
    }
}


void start(int time, int lenght = 50){
    cout << setfill('#') << setw(lenght) << "" << endl;
    cout << "\n\n\n\n\n" << endl;
    cout << setfill(' ') << setw(lenght/4) << ""  <<"Welcome in the Game" << endl;
    cout << "\n\n\n\n\n" << endl;
    cout << setfill('#') << setw(lenght) << "" << endl;

    this_thread::sleep_for(chrono::milliseconds(time));
}

void end_game(int scoreJ, int scoreIA){
    system("cls");
    cout << setfill('#') << setw(lenght) << "" << endl;
    cout << "\n\n\n\n\n" << endl;
    cout << setfill(' ') << setw((lenght-8)/2) << ""  << "End game" << endl;
    cout << setfill(' ') << setw((lenght-1)/2) << "Joueur " << scoreJ << " - " << scoreIA << " IA" << endl;
    cout << "\n\n\n\n" << endl;
    cout << setfill('#') << setw(lenght) << "" << endl;

    this_thread::sleep_for(chrono::milliseconds(5000));
}

void game(int tab[][row]){
    default_random_engine gen(time(0));
    uniform_int_distribution<int> distr3(0, lenght);
    uniform_int_distribution<int> distr4(0, row-1);
    int scoreJ = 0;
    int scoreIA = 0;
    int x, y;
    int xIA, yIA;
    cout << "Joueur Humain Position x, y :";
    while (scoreJ < 24 && scoreIA < 24){
        // human play
        gotoxy(30, row+2);
        cout << "              ";
        gotoxy(30, row+2);
        scanf("%d %d", &x, &y);
        gotoxy(x, y+1);
        cout << tab[x][y];
        scoreJ += tab[x][y];

        // IA play
        xIA = distr3(gen);
        yIA = distr4(gen);
        gotoxy(xIA, yIA+1);
        cout << tab[xIA][yIA];
        scoreIA += tab[xIA][yIA];
        this_thread::sleep_for(chrono::milliseconds(500));

        //afficher score (scoreJ, scoreIA)
        gotoxy(52, 3);
        cout << "Score Joueur : " << scoreJ;
        gotoxy(52, 4);
        cout << "Score IA     : " << scoreIA;

        gotoxy(52, 6);
        cout << "                                ";
        gotoxy(52, 6);
        cout << "Joueur - x:" << x << " y:" << y ;
        gotoxy(52, 7);
        cout << "                                ";
        gotoxy(52, 7);
        cout << "IA     - x:" << xIA << " y:" << yIA ;

    }
    end_game(scoreJ, scoreIA);
}

int main(void) {
    system("cls");
    int start_time = 2000;
    //int **tab;
    int tab[lenght][row];

    // MENU
    start(start_time);
    init(tab, lenght, row);
    displayStart(row, lenght);
    game(tab);



    return (0);
}