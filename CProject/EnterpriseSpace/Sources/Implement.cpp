#include "../Include/Implement.h"
Display *dispaly = new Display;
SmartInput *input = new SmartInput;
DataProcessing *dataProcessing = new DataProcessing;
//暂时禁止登陆的用户向量,存储对应用户的用户名和封禁开始时间
vector <UserLoginTime> ProhibitedUsers;

void Implement(){
    /*在while循环内开始程序的运行*/

    string modeChose;
    sleep(1);
    while(1){
        dispaly->ShowAppLogoFunction();
        modeChose = input->GetInputCommand();
        if(input->GlobalCommandResponse(modeChose)){
            continue;
        }
        if(modeChose == "a"){
            dispaly->ShowAppMenuFunction(1);
            sleep(1);
            continue;
        }
        if(modeChose == "b"){
            dispaly->ShowLoginPageFunction(2);
            Login(2);
            sleep(1);
            continue;
        }
        if(modeChose == "c"){
            dispaly->ShowLoginPageFunction(3);
            Login(3);
            sleep(1);
            continue;
        }
        if(modeChose == "d"){
            dispaly->ShowRegPageFunction(4);
            Register();
            sleep(1);
            continue;
        }
        if(modeChose == "e"){
            cout<<"\033[43;37m EP \033[0;33m Are you sure exit ?[ y / n ]"<<endl;
            string you_chose = input->GetInputCommand();
            if(you_chose.find("y") != string::npos || you_chose.find("Y") != string::npos){
                cout<<"\033[43;37m EP \033[0;33m Bye !"<<endl;
                sleep(1);
                system("clear");
                exit(0);
            }
            else{
                cout<<"\033[43;37m EP \033[0;33m You are cancled!"<<endl;
                sleep(1);
                continue;
            }
        }
        else{
            cout<<"\033[43;37m EP \033[0;33m There is only 5 choise !"<<endl;
            sleep(1);
            continue;
        }
    }
}



//主功能函数

//登陆请求处理,"数据处理函数"根据登陆之后获取的key来生成不同的对象,将登陆的用户数据存入对象以供后续操作
void Login(int modeChose){
    string userName;
    string lastUserName = "";
    string password;
    int numberToLogin = 2;
    int logRec ;
    while(1){
        cout<<"\033[43;30m EP [Login]\033[0;33m 请输入用户名: \033[0m";
        cin >> userName;
        //判断输入的是不是一个全局命令
        if(input->GlobalCommandResponse(userName)){
            dispaly->DoesItNeedToBeDisplayed = true;
            return;
        }
        //判断是否在重复尝试一个用户的登陆,如果不是就不对登陆行为计数
        if(lastUserName != userName){
            lastUserName = userName;
            numberToLogin = 2;
        }
        //判断尝试登陆的用户是否在封禁列表类,如果在返回需要等待的秒数并终止登陆
        double RemainingTime = thisAccountCanBeUse(userName);
        if( RemainingTime != 0){
            cout << "对不起,由于您连续三次输入错误的密码,所以您还需要等待 " << RemainingTime << " 秒" <<endl;
            sleep(2);
            break;
        }
        cout<<"\033[43;30m EP [Login]\033[0;33m 请输入密码: \033[0m";
        cin >> password;
        if(input->GlobalCommandResponse(password)){
            dispaly->DoesItNeedToBeDisplayed = true;
            return;
        }

        //传入用户名,密码,登陆时间,开始登录
        string nowTime= getTime(3);
        logRec = dataProcessing->LoginProcessing(userName,password,nowTime);
        //登陆成功则在界面上显示用户名和登陆时间(打卡时间)
        if(logRec){
            //如果登陆成功之后返回值和选择的用户模式相同,结束登陆循环,进入功能选择界面
            if(modeChose == logRec){
                dispaly->DoesItNeedToBeDisplayed = false;
                cout<<"\033[43;30m EP [Login]\033[0;33m 登陆成功,请稍候... !\033[0m"<<endl;
                dispaly->userName = userName;
                dispaly->LogTime = nowTime;
                break;
            }
            //如果登陆成功之后的返回值和用户选择的登陆模式不同,提示模式选择错误,退出登陆返回主界面
            cout<<"\033[43;30m EP [Login]\033[0;33m 对不起, 您选择的账户类型和你登陆的账户类型不匹配, 请重新选择 !\033[0m"<<endl;
            dispaly->DoesItNeedToBeDisplayed = true;
            return;
            
        }
        //登陆失败则判断是连续第几次登陆失败,如果连续三次登陆失败则封号.否则重新开始登陆
        else{
            dispaly->DoesItNeedToBeDisplayed = true;
            cout<<"\033[43;30m EP [Login]\033[0;33m 您的用户名或者密码输入有误,请重试 ! \033[0m"<<endl;
            //重试
            if(numberToLogin != 0){
                cout << "您还可以尝试"<< numberToLogin<<"次,请您务必正确输入用户名密码"<<endl
                    <<"否则, 在这之后的10分钟内您将被禁止登陆! "<<endl;
                numberToLogin--;
                continue;
            }
            //封号
            else{
                cout << "您已经连续三次输入了错误的密码,您可以花10分钟的时间去想一想你的正确密码或者咨询管理员"<<endl;
                UserLoginTime *ULT = new UserLoginTime;
                time_t timeNow;
                time(&timeNow);
                ULT->username = userName;
                ULT->loginTime = timeNow;
                ProhibitedUsers.push_back( *ULT);
                break;
            }
        }
    }
    //登陆成功之后并进入功能选择循环函数;
    Selection(logRec, userName);
}

//注册请求处理
void Register(){
    string chose, userName, password, password_2, key;
    cin >> chose;
    if(input->GlobalCommandResponse(userName)){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    if(chose == "b"){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    cout<<"\033[43;30m EP [Register]\033[0;33m please input you AccountID: \033[0m";
    cin >> userName;
    if(input->GlobalCommandResponse(userName)){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    cout<<"\033[43;30m EP [Register]\033[0;33m please input you Password: \033[0m";
    cin >> password;
    if(input->GlobalCommandResponse(password)){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    cout<<"\033[43;30m EP [Register]\033[0;33m please input you Password agin: \033[0m";
    cin >> password_2;
    if(input->GlobalCommandResponse(password_2)){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    cout<<"\033[43;30m EP [Register]\033[0;33m please input you register key: \033[0m";
    cin >> key;
    if(input->GlobalCommandResponse(key)){
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    if(password != password_2){
        cout << "password is not same !"<<endl;
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    int regReciver = 0;
    regReciver = dataProcessing->RegisterProcessing(userName, password, key);
    if(regReciver == 1){
       cout<<"\033[43;30m EP [Register]\033[0;33m User Name has been used , try agin !\033[0m"<<endl; 
       dispaly->DoesItNeedToBeDisplayed = true;
       return;
    }
    if(regReciver == 2){
        cout<<"\033[43;30m EP [Register]\033[0;33m Can not find this key , try agin !\033[0m"<<endl; 
        dispaly->DoesItNeedToBeDisplayed = true;
        return;
    }
    if(regReciver == 3){
       cout<<"\033[43;30m EP [Register]\033[0;33m something was come bad , reboot it !\033[0m"<<endl; 
       dispaly->DoesItNeedToBeDisplayed = true;
       return;
    }
    else{
        cout<<"\033[43;30m EP [Register]\033[0;33m register successfuly ! \033[0m"<<endl;
        dispaly->DoesItNeedToBeDisplayed = true;
        if(key.find("PT")!= string::npos){
            Login(3);
            return;
        }
        Login(2);
        return;
    }
}

//显示主菜单选择的函数
//logRec 是当前登陆用户的类别
void Selection(const int &LogRec, string &userName){
    string menuChose;
    while(1){
        dispaly->ShowAppLogoFunction();
        dispaly->ShowAppMenuFunction(LogRec);
        menuChose = input->GetInputCommand();
        cout<<"您的选择是: "<<menuChose<<endl;
        if(menuChose == "exit"){
            cout<<"退出系统? (y/n)"<<endl;
            if(getchar() == 'y'){
                exit(0);
            }
        }
        if(menuChose == "home"){
            cout<<"返回主界面"<<endl;
            sleep(1);
            break;
        }
        //公司简介
        if(menuChose == "a"){
            
            getch();
            continue;
        }
        //公司营收
        if(menuChose == "b"){
            getch();
            continue;
        }
        if(LogRec == 3){
            //个人信息
            if(menuChose == "c"){
                dispaly->ShowAppLogoFunction();
                dispaly->ShowAppMenuFunction(LogRec);
                dataProcessing->showUserInfo(userName);
                getch();
                continue;
            }
            //修改个人信息
            if(menuChose == "d"){
                dispaly->ShowAppLogoFunction();
                dispaly->ShowAppMenuFunction(LogRec);
                dataProcessing->showUserInfo(userName);
                string changeChose;
                string changeValue;
                while(1){
                    cout<<"请输要修改的条目编号(修改即时生效,显示隔日生效,输入'back'取消修改): "<<endl;
                    changeChose = input->GetInputCommand();
                    cout<<"请输入修改后的内容: "<<endl;
                    cin >> changeValue;
                    cout << changeValue;
                    if(changeChose == "a"||changeChose == "b"||changeChose == "c"){
                        dataProcessing->changeInfo(changeChose,changeValue);
                        cout<<"即将退出当前账户,请重新登陆"<<endl;
                        sleep(2);
                        return;
                    }
                    if(changeChose == "back"){

                    }
                    else{
                        cout<<"更多选择请期待后续版本更新! "<<endl;
                    }
                }
                getch();
                continue;
            }
            //签到签退
            if(menuChose == "e"){
                getch();
                continue;
            }
            //提交销售额以审批
            if(menuChose == "f"){
                getch();
                continue;
            }
            //查看领导留言
            if(menuChose == "g"){
                getch();
                continue;
            }
            else{
                cout<<"爱上了一匹野马,可我的家里没有草原(您的选择不在列表范围内,请重试)"<<endl;
                continue;
            }
        }
        if(LogRec == 2){
            //查看个人信息
            if(menuChose == "c"){
                dispaly->ShowAppLogoFunction();
                dataProcessing->showUserInfo(userName);
                getch();
                continue;
            }
            //修改个人信息
            if(menuChose == "d"){
                dispaly->ShowAppLogoFunction();
                dispaly->ShowAppMenuFunction(LogRec);
                dataProcessing->showUserInfo(userName);
                string changeChose;
                string changeValue;
                while(1){
                    cout<<"请输要修改的条目编号(修改即时生效,显示隔日生效,输入'back'取消修改): "<<endl;
                    changeChose = input->GetInputCommand();
                    cout<<"请输入修改后的内容: "<<endl;
                    cin >> changeValue;
                    cout << changeValue;
                    if(changeChose == "a"||changeChose == "b"||changeChose == "c"){
                        dataProcessing->changeInfo(changeChose,changeValue);
                        cout<<"即将退出当前账户,请重新登陆"<<endl;
                        sleep(2);
                        return;
                    }
                    if(changeChose == "back"){

                    }
                    else{
                        cout<<"更多选择请期待后续版本更新! "<<endl;
                    }
                }
                getch();
                continue;
            }
            //查看所有所属成员
            if(menuChose == "e"){
                getch();
                continue;
            }
            //审批销售额报告
            if(menuChose == "f"){
                getch();
                continue;
            }
            //提拔/开除员工
            if(menuChose == "g"){
                getch();
                continue;
            }
            else{
                cout<<"确认过眼神,选择了错的人(您的选择不在列表范围内,请重试)"<<endl;
                continue;
            }
        }
        else{
            cout<<"爱上了不该爱上的人,选择了不能留下的城(您的选择不在列表范围内,请重试)"<<endl;
            continue;
        }

    }
}


//子功能函数
string getTime(int type){
    time_t timer = time(NULL);
    struct tm *tblock;
    tblock = localtime(&timer);
    string timeNow;
    if(type == 1){
        timeNow  = std::to_string(tblock->tm_year+1900);
        return timeNow;
    }
    if(type == 2){
        timeNow  = std::to_string(tblock->tm_year+1900)+"."+std::to_string(tblock->tm_mon+1);
        return timeNow;
    }
    if(type == 3){
        timeNow  = std::to_string(tblock->tm_year+1900)+"."+std::to_string(tblock->tm_mon+1)+"."+std::to_string(tblock->tm_mday);
        return timeNow;
    }
    if(type == 4){
        timeNow  = std::to_string(tblock->tm_year+1900)+"."+std::to_string(tblock->tm_mon+1)+"."+std::to_string(tblock->tm_mday)+" "+std::to_string(tblock->tm_hour)+":"+std::to_string(tblock->tm_min);
        return timeNow;
    }
    
}

double thisAccountCanBeUse(string &userName){
    time_t timeNow = time(NULL);
    for(int i = 0 ; i <ProhibitedUsers.size(); i++){
        if(ProhibitedUsers[i].username == userName){
            double timecat = difftime(timeNow,ProhibitedUsers[i].loginTime);
            if(timecat >= 600){
                ProhibitedUsers.erase(ProhibitedUsers.begin()+i);
                return 0;
            }
            else{
                return 600-timecat;
            }
        }
    }
    return 0;
}
//自定义getch函数,以实现暂停功能
void getch(){
    getchar();
    cout << "按回车键继续...";
    system("stty -echo");
    char c=getchar();
    system("stty echo");
}