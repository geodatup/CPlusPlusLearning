#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementDecal{

public:

  // Constructeur prenant le decalage voulu en argument
    ChiffrementDecal(int decalage):m_decalage(decalage)
  { 
      // A vous de jouer...
      // generer un conteneur de lettre majuscule de l'alphabet
      //for (int i = 0; i < 26; i++) {
      //   m_alphabet.push_back((char)(65 + (i/26)*6 + i));
      //    cout << "'" << m_alphabet[i] << "'" << "," ;
      //}
      m_alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  }
    
    char operator()(char c)
    {
        // comparer chaque char avec l'alphabet de ref
        vector<char>::iterator trouve = find(m_alphabet.begin(), m_alphabet.end(), c);
        
        if(trouve == m_alphabet.end())
        {
            //cout << "La lettre "<< c <<" n'a pas ete trouvee" << endl;

            return c;
        }
        else
        {
            while (trouve - m_alphabet.begin() + m_decalage > 25)
        { // tant que le décalage donne un résultat en dehors de l'alphabet on soustrait le décalage d'un alphabet
            
           trouve -= 26;

        };
            
            return trouve[0+m_decalage];
        }

    }
    
    void AfficherAlphabet() //permet d'afficher le contenu du containeur alphabet
    {
        for( unsigned int i = 0; i < m_alphabet.size(); i++ )
        {
            std::cout << "Element[" << i << "] = " << m_alphabet[i] << std::endl;
        }
        std::cout << std::endl;
    }

private:
 
  int m_decalage; // Le decalage a appliquer au text
  vector<char> m_alphabet; // un alphabet

    
};



int main()
{
  
  // Le message a crypter
  string texte("BIENVENUE SUR LE MOOC C++ D'OCR !!");
  
  // Demande du decalage a l'utilisateur
  cout << "Quel decalage voulez-vous utiliser ? ";
  int decalage;
  cin >> decalage;

    

  // A vous de jouer....
    
    // Creation du foncteur
    ChiffrementDecal foncteur(decalage);
    
    //foncteur.AfficherAlphabet();
    

    transform(texte.begin(), texte.end(), texte.begin(), foncteur);

    for(vector<char>::iterator it=texte.begin(); it!=texte.end(); ++it)
    {
        // on affiche le texte crypté avec la mise en forme demandé
        cout << *it << ", " ;
    }

    
    return 0;
}

