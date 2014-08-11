//
//  AccumulatorModule.cpp
//  Hoping
//
//  Created by wangyu on 14-8-1.
//  Copyright (c) 2014年 tz. All rights reserved.
//
#include <exception>
#include <ios>

#include "AccumulatorModule.h"

namespace SAMSCalculator {
    using namespace std;
    
    float(const anOperator theOperator, const float theOperand)
    {
        static float myAccumulator = 0;
        
        switch(theOperator)
        {
            case add:
                myAccumulator += theOperand;
                break;
            case subtract:
                myAccumulator -= theOperand;
                break;
            case multiply:
                myAccumulator *= theOperand;
                break;
            case divide:
                myAccumulator /= theOperand;
                break;
            case reset:
                myAccumulator = theOperand;
                break;
            case query:
                break;
            default:
                throw runtime_error("Error - Invalid operator");
        }
        return myAccumulator;
    }
}