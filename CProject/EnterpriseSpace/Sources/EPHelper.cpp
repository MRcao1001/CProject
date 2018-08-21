#include "../Include/EPHelper.h"
/*EPhelper是本程序的一大特色,本程序完全封装了标准函数cin 来保证输入值的正确性
 *当你输入 'EP' 之后,在任何地方都会唤醒EP helper
 *你可使用EP helper的内置命令来快捷的执行操作,也可以使用自然语言来告诉EP helper你想做的事情
 */
EPHelper::EPHelper(){

}
/*TODO:判断输入的是不是预设命令*/
string EPHelper::JudgeCommandFromFunction_GlobalCommandResponse(string command,int modeChose){
    /*退出程序保存更改命令 'q'*/
    if(quitAndSave == command){

    }
    /*显示命令提示 'help'*/
    if(showHelpInformation == command){

    }
    /*显示公司营收状况 'about'*/
    if(showCompanyIntroduction == command){

    }
    /*快捷注册 'reg'*/
    if(signUp == command){

    }
    /*EP 的自我简介 EP*/
    if(selfIntroduction == command){

    }
    /*显示你的本月工资 'wg'*/
    if(showWages == command){

    }
    /*显示你的个人信息 'me'*/
    if(showMyselfInformation == command){

    }
    /*修改密码直通车 'pwd'*/
    if(changePassword == command){

    }
    /*快捷添加注册key 'add'*/
    if(addUserKey == command){

    }
    /*删除用户直通车 'dlt'*/
    if(deleteUser == command){

    }
    /*显示当月报表 'tb'*/
    if(displayMonthReport == command){

    }
    /*提拔员工直通车 'up'*/
    if(PromotionUser == command){

    }
    else{
        try{
            if(! TryToUnderstandYourStatement(command, modeChose)){
                throw;
            }
        }
        catch(exception e){
            cout<<"在试图让EP理解自然语言的过程中发生了错误:"<<e.what()<<endl;
        }
    }
    return "";

}

//FIXME: 以下功能是让EP尝试理解自然语言,是测试功能
bool EPHelper::TryToUnderstandYourStatement(string command, int modeChose){
    if( (command.find("注册") != string::npos) || (command.find("新用户") != string::npos) || (command.find("没有账号") != string::npos) || (command.find("加入") != string::npos)){
        if((command.find("如何") != string::npos)||(command.find("怎么") != string::npos)||(command.find("我想") != string::npos)){
            cout<<"Ok, you can sign in by this way!"<<endl;
        }
        else{
            cout<<"Ok, I will register you auto ... "<<endl;
        }
    }
    if( (command.find("sign up") != string::npos) || (command.find("new account") != string::npos) || (command.find("register") != string::npos) || (command.find("join") != string::npos)){
        if((command.find("how") != string::npos)||(command.find("way") != string::npos)){
            cout<<"Ok, you can sign up by this way!"<<endl;
        }
        else{
            cout<<"Ok, I will register you auto ... "<<endl;
        }
    }
    if( (command.find("登录") != string::npos) || (command.find("登陆") != string::npos) || (command.find("进入") != string::npos) || (command.find("打开") != string::npos)){
        if((command.find("如何") != string::npos)||(command.find("怎么") != string::npos)||(command.find("我想") != string::npos)||(command.find("怎样") != string::npos)){
            cout<<"Ok, you can login by this way!"<<endl;
        }
        else{
            cout<<"Ok, I will login you auto ... "<<endl;
        }
    }
    if( (command.find("login") != string::npos) || (command.find("sign in") != string::npos) || (command.find("enter") != string::npos) || (command.find("star") != string::npos)){
        if((command.find("how") != string::npos)||(command.find("way") != string::npos)){
            cout<<"Ok, you can login by this way!"<<endl;
        }
        else{
            cout<<"Ok, I will login you auto ... "<<endl;
        }
    }
    else{
        cout<<"sorry ,I can not understand you command , please try agin!"<<endl;
    }
    return true;
}