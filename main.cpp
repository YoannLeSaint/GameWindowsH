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

void gotoxy(int x, int y) {
    COORD c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

// int game_max_score(int tab[]) {
//     int totalScore = 0;

//     for (int i : tab) {
//         totalScore += tab[i];
//     }
// }

void init(int *tab[], int lenght, int row){
    default_random_engine gen(time(0));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < lenght; j++){
            tab[i][j] = 0;
        }
    }
    for (int number = 1; number < 10; number++){
        while(true){
            uniform_int_distribution<int> distr(0, row);
            int randX = distr(gen);
            uniform_int_distribution<int> distr(0, row);
            int randY = distr(gen);
            if (tab[randX, randY] != 0){
                *tab[randX, randY] = number;
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

int main(void) {

    const int lenght = 50;
    const int row = 10;
    int start_time = 2000;
    int tab[row][lenght];

    // MENU
    start(start_time);
    init(*tab[], lenght, row);
    
    



    return (0);
}