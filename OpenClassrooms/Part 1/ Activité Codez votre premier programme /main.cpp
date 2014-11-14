/*
 * By Sébastien Malissard
 * On 9 October 2014
 * http://fr.openclassrooms.com/informatique/cours/programmez-avec-le-langage-c
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>

#define NB_TRIES 5
#define DICO "dictionaire.txt" //Comment this line to use the manual mode

using namespace std;

int main(){
    string wordToFind, word, wordRandom, stringTemp;
    int nbRandom, i;
    bool end = 0;

    srand(time(0));

#ifdef DICO
    //Open the dictionary
    ifstream dico(DICO);
    if(!dico){
        cerr << "Error to open : " << DICO << endl;
        exit(-1);
    }

    //Counts the number of lines
    int nblines = count( istreambuf_iterator<char>(dico), istreambuf_iterator<char>(), '\n' );
#endif

    //Welcome to the user
    cout << "Bienvenue" << endl;

    do{
        //Clear string
        wordToFind.clear();
        wordRandom.clear();

#ifdef DICO
        //Initialization at the beginning of the file
        dico.clear();
        dico.seekg(0, ios::beg);

        //Word choice
        nbRandom = rand() % nblines;
        //cout << nbRandom << endl; //print the line of the world choose
        for(i = 0 ; i < nbRandom ; i++){
            getline(dico, wordToFind);
        }

#else
        //Word choice
        cout << "Saisissez un mot" << endl;
        cin >> wordToFind ;
#endif

        //Mix for letters of the word selected
        word = wordToFind;
        while(word.size() > 0){
            nbRandom = rand() % word.size();
            wordRandom += word[nbRandom];
            word.erase(nbRandom, 1);
        }

        //The user is trying to find the word
        for(i = NB_TRIES ; i > 0  ; i--){
            cout << "Quel est ce mot ? " << wordRandom << endl;
			cout << "Solution : " << wordToFind << endl;
            cin >> word;
            if(word == wordToFind){
                cout << "Bravo !" << endl << endl;
                break;
            }
            else{
                cout << "Ce n'est pas le bon mot ! Il vous reste " << i - 1 << " essais" << endl << endl;
            }
        }

        //The user doesn't found the word
        if(i == 0) cout << "Solution : " << wordToFind << endl << endl;

        //The user chooses to continue or quit the game
        while(1){
            cout << "Voulez-vous faire une autre partie ? (o/n)" << endl;
            cin >> stringTemp;
            if(!stringTemp.compare("o") ||  !stringTemp.compare("O"))break;
            else if(!stringTemp.compare("n") ||  !stringTemp.compare("N") ||  !stringTemp.compare("\n")){ end = 1 ; break;}
            else cout << "Choix non valide !" << endl;
        }

    } while(end == 0);

    //Bye to the user
    cout << "Bye ..." << endl;

    return 0;
}
