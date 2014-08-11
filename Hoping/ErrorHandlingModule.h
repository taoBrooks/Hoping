//
//  ErrorHandlingModule.h
//  Hoping
//
//  Created by wangyu on 14-7-30.
//  Copyright (c) 2014年 tz. All rights reserved.
//

#ifndef __Hoping__ErrorHandlingModule__
#define __Hoping__ErrorHandlingModule__
//#include "iostream"
#include <exception>

namespace SAMSErrorHandling {
    void Initialize(void);
    int HandleNotANumberError(void);
    int HandleRuntimeError(std::runtime_error theRuntimeError);
}

#endif /* defined(__Hoping__ErrorHandlingModule__) */
