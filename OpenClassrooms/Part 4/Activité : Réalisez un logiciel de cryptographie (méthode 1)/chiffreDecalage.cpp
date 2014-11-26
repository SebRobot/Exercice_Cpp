/*
 * chiffreDecalage.cpp
 *
 *  Created on: 26 nov. 2014
 *      Author: Sebastien Malissard
 */

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementDecal{
    public:
    // Constructeur prenant le decalage voulu en argument
    ChiffrementDecal(int decalage):m_decalage(decalage){};

    template <class T>
    void operator() (T &c){
        if(isupper(c)){
            c += m_decalage%('Z'-'A'+1);
            if(c > 'Z'){
                c -= ('Z'-'A');
            }
        }
    }

    private:
    int m_decalage; // Le decalage a appliquer au texte

};

int main(){
    // Le message a crypter
    string texte("BIENVENUE SUR LE MOOC C++ D'OCR !!");

    // Demande du decalage a l'utilisateur
    cout << "Quel decalage voulez-vous utiliser ? ";
    int decalage;
    cin >> decalage;

    // Creation du foncteur
    ChiffrementDecal foncteur(decalage);

    // Chaine de caracteres pour le message crypter
    string texte_crypte;

    //Application du decalage
    texte_crypte = texte;
    for_each(texte_crypte.begin(), texte_crypte.end(), foncteur);

    //Affichage dans la console avec les virgules
    ostream_iterator<char> it(cout,",");
    string::iterator itt;
    for(itt = texte_crypte.begin(); itt != texte_crypte.end(); itt++){
        *it = *itt;
    }
    cout << endl;

    return 0;
}
