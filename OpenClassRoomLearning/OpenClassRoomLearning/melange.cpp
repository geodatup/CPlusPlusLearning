//
//  melange.cpp
//  OpenClassRoomLearning
//
//  Created by Zugi R on 11/12/2017.
//  Copyright © 2017 Geodatup. All rights reserved.
//

#include "melange.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> // Obligatoire

#include <cstdlib> // Obligatoire

//using namespace std;

string motAleatoireDico(ifstream& flux)
{

    string motMystere = "";
    
    // taille du fichier
    // position dans le fichier
    flux.seekg(0, ios::end);  //On se déplace à la fin du fichier
    
    long taille(0);
    
    taille = flux.tellg();
    
    //On récupère la position qui correspond donc a la taille du fichier !
    

    long position(0);

    do {
        position = rand() % taille;

        flux.seekg(position,ios::beg);
        
        flux >> motMystere; // on prend la fin du mot
        flux >> motMystere; // on prend le mot suivant : il faudrait repartir du début du mot mais je ne sais pas comment faire.
        
        // removing terminate lines char
        if (!motMystere.empty() && (motMystere[motMystere.size() - 1] == '\r' || motMystere[motMystere.size() - 1] == '\r\n'))
            motMystere.erase(motMystere.size() - 1);
    } while (motMystere == "");
    
    return motMystere;
    
}
string melange(string motMystere)
{
    
    string motMelange;
    int position(0);
    do
    {
        
        position = rand() % motMystere.size();
        motMelange += motMystere[position];
        motMystere.erase (position , 1 ) ;
        
    } while ( motMystere.size() != 0 );
    
    return motMelange;
}

void newPage()
{
    int const nbr(1000);
    for(int i(0); i < nbr ; i++ )
    {
        cout << endl;
    }
}
