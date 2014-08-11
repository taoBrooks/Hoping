#include <iostream>

#include "PromptModule.h"
#include "ErrorHandlingModule.h"

using namespace std;

float Accumulator(const char x, const float y = 0);

bool TestOK(const char theOperator, const float theOperand, const float theExpectedResult)
{
    float Result = Accumulator(theOperator, theOperand);
    if (Result == theExpectedResult) {
        cout<< theOperator << theOperand << "- succeeded." <<endl;
        return true;
    }
    else
    {
        cout<<theOperator<<theOperand<<" - failed. Expected " << theExpectedResult << ", got" << Result << endl;
        
        return false;
    }
}

float GetOperand(void)
{
    float Operand;
    
    cout<< "Operand: ";
    cin>>Operand;
    
    return Operand;
}

float GetDividend(void)
{
    float Dividend = 0;
    
    cout << "Dividend: ";
    cin >> Dividend;
    
    return Dividend;
}

char GetOperator(void)
{
    char Operator;
    cout<<"Operator: ";
    cin>>Operator;
    
    return Operator;
}

float GetDivisor(void)
{
    float Divisor = 0;
    
    cout << "Divisor: ";
    cin >> Divisor;
    
    return Divisor;
}

void Tape(const char theOperator, const float theOperand)
{
    static const int myTapeChunk = 3;
    
    static char *myOperator = new char[myTapeChunk];
    static int *myOperand = new int[myTapeChunk];
    
    static int myTapeSize = myTapeChunk;

    static int myNumberOfEntries = 0;
    
    switch (theOperator) {
        case '?':
            for (int Index; Index < myNumberOfEntries; Index++) {
                cout<<myOperator[Index]<<','<<myOperand[Index]<<endl;
            }
            break;
        case '.':
            delete []myOperator;
            delete []myOperand;
            break;
        default:
            if(myNumberOfEntries == myTapeSize)
            {
                char *ExpandedOperator = new char[myNumberOfEntries + myTapeChunk];
                int *ExpandedOperand = new int[myNumberOfEntries + myTapeChunk];
                
                char *FromOperator = myOperator;
                int *FromOperand = myOperand;
                
                char *ToOperator = ExpandedOperator;
                int *ToOperand = ExpandedOperand;
                
                for (int Index = 0; Index < myNumberOfEntries; Index++) {
                    *ToOperator++ = *FromOperator++;
                    *ToOperand++ = *FromOperand++;
                }
                //Delete the old arrays
                
                delete [] myOperator;
                delete [] myOperand;
                
                //Replace the old pointers with the new
                
                myOperator = ExpandedOperator;
                myOperand  = ExpandedOperand;
                
                myTapeSize += myTapeChunk;
            }
            
            myOperator[myNumberOfEntries] = theOperator;
            myOperand[myNumberOfEntries] = theOperand;
            myNumberOfEntries++;
            break;
    }
}


float Divide( const float theDividend, const float theDivisor )
{
    return (theDividend/theDivisor);

}

void SelfTest(void)
{
    float OldValue = Accumulator('=');
    try {
        if(TestOK('@',0,0) && TestOK('+',3,3)&&TestOK('-',2,1)&&TestOK('*',4,4)&&TestOK('/',2,2))
        {
            cout<< "Test completed successfully."<<endl;
        }
        else
        {
            cout<<"Test failed."<<endl;
        }
    } catch (...) {
        cout<<"An exception occured during self test."<<endl;
    }
    Accumulator('@', OldValue);
}

float Accumulator(const char theOperator, const float theOperand)
{
    static float myAccumulator = 0;
    
    switch (theOperator) {
        case '+':
            myAccumulator += theOperand;
            Tape(theOperator, theOperand);

            break;
        case '-':
            myAccumulator -= theOperand;
            Tape(theOperator, theOperand);

            break;
        case '*':
            myAccumulator = theOperand;
            Tape(theOperator, theOperand);

            break;
        case '/':
            myAccumulator /= theOperand;
            Tape(theOperator, theOperand);

            break;
        case '@':
            myAccumulator = theOperand;
            Tape(theOperator, theOperand);

            break;
        case '=':
            cout<<endl<<myAccumulator<<endl;
            break;
        case '?':
            Tape(theOperator, theOperand);
            break;
        default:
            throw runtime_error("Error - Invalid operator");
    };
    return myAccumulator;
}


int main(int argc, char * argv[])
{
    SAMSErrorHandling::Initialize();
    
    //float ReturnCode = 0;
    //char Operator;
    
    do
    {
    try {
//        float Dividend = GetDividend();
//        float Divisor = GetDivisor();

        char Operator = GetOperator();
        if(Operator == '+' || Operator == '-' || Operator == '*' || Operator =='/' || Operator == '@')
        {
            float Operand = GetOperand();
            Accumulator(Operator, Operand);
        }
        else if(Operator == '!')
        {
            SelfTest();
        }
        else if(Operator == '.')
        {
            //Do nothing
        }
        else
        {
            Accumulator(Operator);
        }
    }catch(runtime_error RuntimeError){
        SAMSErrorHandling::HandleRuntimeError(RuntimeError);
    
    }catch (...) {
        SAMSErrorHandling::HandleNotANumberError();
    }
    }while (::UserWantsToContinue("More division? "));
//    PauseForUserAcknowledgement();
    return 0;
//    return ReturnCode;
}
