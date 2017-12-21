//
//  compareString.cpp
//  OpenClassRoomLearning
//
//  Created by Zugi R on 11/12/2017.
//  Copyright © 2017 Geodatup. All rights reserved.
//

#include <iostream>

#include <string>
#include "compareString.h"

void compareString(string const& mot1, string const& mot2, int& credit)
{
    
    if (mot1 == mot2)
    {
        cout << "Gagné" << endl;   
        
    }
    else
    {

        cout << "Perdu" << endl;
        --credit;
    }
    
}
