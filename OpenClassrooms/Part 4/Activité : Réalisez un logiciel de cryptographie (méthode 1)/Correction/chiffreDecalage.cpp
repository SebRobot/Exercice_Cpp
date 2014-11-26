#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

//Foncteur qui effectue un chiffrement par decalage
class ChiffrementDecal{

public:

  // Constructeur prenant le decalage voulu en argument
  ChiffrementDecal(int decalage)
    :m_decalage(decalage)
  {
    // On teste que le decalage est dans [0, 26]
    while (m_decalage > 26)
      m_decalage -= 26;

    while (m_decalage < 0)
      m_decalage += 26;

    // Note, on aurait pu utiliser 
    // m_decalage %=26;
    // a la place des deux boucles 'while'
  }

  // L'operateur() qui effectue le chiffrement
  char operator()(char lettre)
  {
    // On transforme uniquement les caracteres majuscules
    if(isupper(lettre))
      {
	// On applique le decalage
	char lettre_crypte = lettre + m_decalage;

	// Si on a depasse le 'Z', on retourne au debut de l'alphabet
	if(lettre_crypte > 'Z')
	  lettre_crypte -= 26;

	return lettre_crypte;
      }
    else
      {
	return lettre;
      }
  }

private:

  int m_decalage; // Le decalage a appliquer au texte
  
};


int main()
{
  
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
  
  // Un iterateur permettant l'insertion a la fin
  back_insert_iterator<string> it(texte_crypte);

  // On applique le foncteur sur le vector pour crypter le message en utilisant 'transform'
  transform(texte.begin(), texte.end(), it, foncteur);

  // Note, on aurait pu utiliser
  // texte_crypte.resize(texte.size());
  // transform(texte.begin(), texte.end(), texte_crypte.begin(), foncteur);
  // a la place du back_insert_iterator

  // On copie le message dans cout en utilisant l'algorithme 'copy'
  copy(texte_crypte.begin(), texte_crypte.end(), ostream_iterator<char>(cout, ", "));
  cout << endl;

  return 0;
}

