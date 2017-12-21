#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

// Foncteur qui effectue un chiffrement par decalage
class ChiffrementDecal{

public:

	// Constructeur prenant le decalage voulu en argument
	ChiffrementDecal(int decalage) : m_decalage(decalage % 26)
	{
		// A vous de jouer...
	}

	// A vous de jouer...
	char operator()(char c) const
	{
		//Si c'est une lettre, on incrémente de m_decalage
		if (isalpha(c))
		{
			//c doit être dans un intervalle de 65 à 90
			return (c + m_decalage > 90 ? c + m_decalage - 26 : c + m_decalage);
		}
		else
		{
			//c n'est pas une lettre, on retourne donc le même caractère
			return c;
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

	// A vous de jouer....
	texte_crypte = texte;
	//Appel de «transform» avec le foncteur «foncteur»
	transform(texte.begin(), texte.end(), texte_crypte.begin(), foncteur);
	//Affichage du résultat sur la sortie standard séparé par des virgules
	copy(texte_crypte.begin(), texte_crypte.end(), ostream_iterator<char>(cout, ","));

return 0;
}
