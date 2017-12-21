#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementSubst{

public:

  // Constructeur prenant le nom fichier contenant les decalages a utiliser
  ChiffrementSubst(const string& nomFichier)
    :m_table()
  {
    ifstream fichier(nomFichier.c_str());

    for( int i(0); i<26; ++i)
      {
	char lettre, substitut;
	fichier >> lettre;
	fichier >> substitut;

	// On cree une nouvelle case dans la table
	m_table[lettre] = substitut;
      }
  }

  // L'operateur() qui effectue le chiffrement
  char operator()(char lettre)
  {
    // On transforme uniquement les caracteres majuscules
    if(isupper(lettre))
      {
	// On cherche la lettre dans la table
	return m_table[lettre];
      }
    else
      {
	return lettre;
      }
  }

private:

  map<char, char> m_table;  // La table contenant les caracteres cryptes
  
};


int main()
{

  // Le message a crypter
  string texte("BIENVENUE SUR LE MOOC C++ D'OCR !!");

  // Demande du decalage a l'utilisateur
  cout << "Quel fichier contenant la cle voulez-vous utiliser ? ";
  string nomFichier;
  cin >> nomFichier;

  // Creation du foncteur
  ChiffrementSubst foncteur(nomFichier);

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

