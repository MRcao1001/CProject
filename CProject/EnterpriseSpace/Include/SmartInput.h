#ifndef SMART_INPUT_H
#define SMART_INPUT_H
#include "../Include/PublicHeader.h"
#include "../Include/Display.h"
#include "../Include/EPHelper.h"
#include <cctype>
using namespace std;
class SmartInput{
    public:
        SmartInput();
        int GetInputNumbers();
        string GetInputCommand();
        int GlobalCommandResponse(string getCommandFromCin);
    private:
    int NumberOfRowsThatHaveBeenExported;
    string StoreInputDigits;
    string StoreInputCommand;
};
#endif