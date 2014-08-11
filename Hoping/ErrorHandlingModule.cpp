//
//  ErrorHandlingModule.cpp
//  Hoping
//
//  Created by wangyu on 14-7-30.
//  Copyright (c) 2014年 tz. All rights reserved.
//
#include <iostream>
#include "ErrorHandlingModule.h"

namespace SAMSErrorHandling
{
    using namespace std;
    
    void Initialize(void)
    {
        cin.exceptions(cin.failbit);
    }
    
    int HandleNotANumberError(void)
    {
        cerr << "Input Error - not a number?" <<endl;
        cin.clear();
        
        char BadInput[5];
        cin >> BadInput;
        
        return 1;
    }
    int HandleRuntimeError(runtime_error theRuntimeError)
    {
        cerr << theRuntimeError.what() << endl;
        
        return 1;
    }
}