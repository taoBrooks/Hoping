//
//  PromptModule.cpp
//  Hoping
//
//  Created by wangyu on 14-7-30.
//  Copyright (c) 2014年 tz. All rights reserved.
//
#include <iostream>
#include "PromptModule.h"

using namespace std;

void PauseForUserAcknowledgement(void)
{
    char StopCharacter;
    cout << endl << "Press a key and \"ENTER\": ";
    
    cin >> StopCharacter;
}

bool UserWantsToContinue(const char *theThingWeAreDoing)
{
    char DoneCharacter;
    bool InvalidCharacterWasEntered = false;

    do
    {
        cout<<endl<<theThingWeAreDoing<<"Press \"n\" and \"Enter\" to stop: ";
        cin>>DoneCharacter;
        
        InvalidCharacterWasEntered = !((DoneCharacter == 'y') || (DoneCharacter == 'n'));
        if (InvalidCharacterWasEntered) {
            cout<<"Error - "<< "Please enter \"y\" or \"n\"."<<endl;
        }
    }while( InvalidCharacterWasEntered );
    
    cout<<endl<<theThingWeAreDoing<<"Press \"n\" and \"Enter\" to stop: "<<endl;
    
    //cin>>DoneCharacter;
    
    return (DoneCharacter != 'n');
}