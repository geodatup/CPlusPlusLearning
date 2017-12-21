//
//  main.cpp
//  OpenClassRoomLearning
//
//  Created by Zugi R on 11/12/2017.
//  Copyright © 2017 Geodatup. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime> // Obligatoire
#include <cstdlib> // Obligatoire
#include <fstream> // lib file stream
#include "melange.h"
#include "compareString.h"
using namespace std;

int main()
{
    srand( (unsigned int) time(0));
    
    bool again(false); // initialise la variable de nouvelle partie.
    
    string pathToDico;
    cout << "Où se trouve votre fichier dictionnaire.txt sur votre machine ? " << endl;
    
    cin >> pathToDico;

    
    ifstream monflux(pathToDico.c_str()); //Déclaration d'un flux permettant d'écrire dans le fichier

    
    
    
    if (monflux)
    {
    cout << "Ok, votre dictionnaire est prêts à être utilisé par le programme. " << endl;
   
        
    do {
        // cout << "saisissez un mot mystère" << endl;
        
        // cin >> motMystere:
        
        // newPage(); // saut de page
        string motMystere;
        motMystere = motAleatoireDico(monflux);
        cout << "Quel est ce mot ? " <<  melange(motMystere) << endl;
        
        string response;
        
        int credit(5);
        bool firstattempt(true); // permet d'éviter l'annonce du nombre d'essais restant au premier coup.
        
        do
        {
            if( credit != 0 && firstattempt == false)
            {
                cout << "il ne vous reste  " << credit << " essais " << endl;
            }
            cin >> response;
            
            compareString(motMystere, response, credit); // on compare les string et on modifie credit si erreur
            
            firstattempt = false; // ce n'est plus le premier coup
            
            
        } while(motMystere != response && credit != 0);
        
        bool ask(false);

        do {
            
            if (credit == 0)
            {
                
                cout << "Vous n'avez plus de crédit, la solution est " << motMystere << endl << "Good bye !" << endl;;
                ask = false;
                again = false;
            }
            else
            {
            cout << "Voulez vous rejouer ?" << " O/N " << endl;
            
            char a;
            cin >> a ;
            
            switch (a)
            {
                case 'O'| 'o':
                    cout << "OUIIII" << endl;
                    again = true;
                    ask = false;
                    break;

                case 'N' | 'n':
                    cout << "Dommage au revoir" << endl;
                    again = false;
                    ask = false;
                    break;
                
                default:
                    cout << "Nous n'avons pas compris : " << a << endl;
                    ask = true;
                    break;
            }
            }

        } while (ask == true);
    
    } while (again == true);
        
    }
    else // dans le cas ou le fichier dico ne s'ouvre pas. On ne lance pas le programme.
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier dictionnaire en lecture." << endl;
    }
    
    return 0;
}
