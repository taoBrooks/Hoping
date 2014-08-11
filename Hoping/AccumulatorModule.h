//
//  AccumulatorModule.h
//  Hoping
//
//  Created by wangyu on 14-8-1.
//  Copyright (c) 2014年 tz. All rights reserved.
//

#ifndef Hoping_AccumulatorModule_h
#define Hoping_AccumulatorModule_h

namespace SAMSCalculator {
    enum anOperator{
        add, subtract, mutiply, divide, reset, query
    };
    
    float Accumulator(const anOperator theOperator, const float theOperand = 0);
}

#endif
