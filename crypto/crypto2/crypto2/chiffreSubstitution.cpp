#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementSubst{

public:

  // Constructeur prenant le nom fichier contenant les substitutions a utiliser
  ChiffrementSubst(const string& nomFichier)
  {
    fstream flux(nomFichier);
    // création d'un conteneur map pour stocker clé->valeur
    istream_iterator<char> it(flux);
    istream_iterator<char> end;         //Le signal de fin

    do {
      char cle(*it);
      ++it;
      char val(*it);
      
      m_cle[cle] = val;
      ++it;
    } while (it != end);
  }
    
    
    char operator()(char c) 
    {
      
      if(isupper(c)) // on test si le caractère est une lettre majuscule
      {
        // chercher chaque char dans le dico clé de reference
        map<char, char>::iterator trouve = m_cle.find(c);
      
        if(trouve == m_cle.end()) // si la lettre n'est pas dans le dico
        {
          //cout << "La lettre "<< c <<" n'a pas ete trouvee" << endl;
          return c;
        }
        else
        {
          return trouve->second ;
        }
        
      }
      else
      {
        return c;
      }
      
    }
    
    void AfficherCle() //permet d'afficher le contenu du containeur alphabet
    {
      //Et on l'affiche
      
      for(map<char, char>::iterator it_m_cle=m_cle.begin(); it_m_cle!=m_cle.end(); ++it_m_cle)
        
      {
        
        cout << "Element[" << it_m_cle->first << "] = " << it_m_cle->second << endl;
        
      }

    }

  
private:
  map<char, char> m_cle; // le conteneur des clé valeur

};


int main()
{

  // Le message a crypter
  string texte("BIENVENUE SUR LE MOOC C++ D'OCR !!");

  // Demande de la cle a l'utilisateur
  cout << "Quel fichier contenant la cle voulez-vous utiliser ? ";
  string nomFichier;
  cin >> nomFichier;

  // Creation du foncteur
  ChiffrementSubst foncteur(nomFichier);

  // Chaine de caracteres pour le message crypter
  string texte_crypte;
  back_insert_iterator<string> it(texte_crypte);
  
  //foncteur.AfficherCle();
  transform(texte.begin(), texte.end(), it, foncteur);
  copy(texte_crypte.begin(), texte_crypte.end(), ostream_iterator<char>(cout, ","));
  cout << endl;

  return 0;
}

