#ifndef EP_HELPER_H
#define EP_HELPER_H
#include "../Include/PublicHeader.h"
class EPHelper{
    public:
        EPHelper();
        string JudgeCommandFromFunction_GlobalCommandResponse(string command,int modeChose);
        bool TryToUnderstandYourStatement(string command, int modeChose);
    private:
        /*default command*/
        const string quitAndSave = "q";
        const string showHelpInformation = "help";
        const string showCompanyIntroduction = "about";
        const string signUp = "reg";
        const string selfIntroduction = "EP";
        const string showWages = "wg";
        const string showMyselfInformation = "me";
        const string changePassword = "pwd";
        const string addUserKey = "add";
        const string deleteUser = "dlt";
        const string displayMonthReport = "tb";
        const string PromotionUser = "up";
};
#endif