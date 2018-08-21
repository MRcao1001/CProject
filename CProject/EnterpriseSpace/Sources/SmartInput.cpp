#include "../Include/SmartInput.h"
SmartInput::SmartInput(){
    NumberOfRowsThatHaveBeenExported = 0;
    StoreInputDigits="";
    StoreInputCommand="";
}

//强制输入纯数字
int SmartInput::GetInputNumbers(){
    int subscript = 0;
    int result = 0;
        try{
            cin >> StoreInputDigits;
            //判断输入的是不是全局命令
            while(subscript < StoreInputDigits.length()){
                //使用isdigit判断该字符是不是数字
                if(isdigit(StoreInputDigits[subscript]) == 0){
                    cout<<"\033[43;37m EP \033[0;33m Oh~ is so bad, you must input a number !"<<endl;
                    sleep(1);
                    break;
                }
                if(subscript == 9){
                    break;
                }
                subscript++;
            }
            result = std::stoi(StoreInputDigits);
        }
        catch(exception e){
            cout<<e.what()<<endl;
        }
    return result;
}

//强制输入纯字母组成的字符串
string SmartInput::GetInputCommand(){
    int subscript = 0;
    string result = "";

        try{
            cin >> StoreInputCommand;
            getchar();
            while(subscript < StoreInputCommand.length()){
                //使用isalpha判断字符是不是字母
                if( isalpha(StoreInputCommand[subscript]) == 0){
                    cout<<"\033[43;37m EP \033[0;33m Oh~ is so bad, you must input a words !"<<endl;
                    sleep(1);
                    return 0;
                }
                if(subscript == 9){
                    break;
                }
                subscript++;
            }
            result = StoreInputCommand;
        }
        catch(exception e){
            cout<<e.what()<<endl;
        }
    return result;
}
//判断输入的字符串是不是一个全局命令
int SmartInput::GlobalCommandResponse(string getCommandFromCin){
    if(getCommandFromCin == "exit"){
        exit(0);
        return 1;

    }
    else if(getCommandFromCin == "EP"){
        Display *EPdisplay = new Display;
        EPdisplay->ShowEPHelper();
        EPHelper *epHelper = new EPHelper;
        string newCommand = "";
        cout << "EP geting command..."<<endl;
        cin >> newCommand;
        epHelper->TryToUnderstandYourStatement(newCommand,2);
        cout << "EP halp you end"<<endl;
        delete EPdisplay;
        delete epHelper;
        return 1;
    }
    if(getCommandFromCin == "quit"){
        cout << "quit";
        return 1;

    }
    else{
        return 0;
    }
}