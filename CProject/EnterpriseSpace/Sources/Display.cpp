#include "../Include/Display.h"
Display::Display(){
    DoesItNeedToBeDisplayed = true;
    userName = "请登录 / 注册";
    LogTime = "N / A";
}

/*本程序的名字是 EnterPriseSpace   这个函数只用于显示他的logo*/
void Display::ShowAppLogoFunction(){
    system("clear");
    cout<<"\033[0;33m                                                                             "<<endl;
    cout<<"         /#######  /######     /######"<<endl;
    cout<<"        | ##____/ /##__  ##   /##__  ##"<<endl;
    cout<<"        | ##     | ##  \\ ##  | ##  \\__/ /######  /######  /####### /######"     <<endl;
    cout<<"        | #######| ##  | ##  |  ###### /##__  ##|____  ##/##_____//##__  #"   <<endl;
    cout<<"        | ##____/| #######    \\____  #| ##  \\ ## /######| ##     | ########"   <<endl;
    cout<<"        | ##     | ##____/    /##  \\ #| ##  | ##/##__  #| ##     | ##_____/"   <<endl;
    cout<<"        | #######| ##        |  ######| #######|  ######|  ######|  ######"   <<endl;
    cout<<"        |_______/|__/         \\______/| ##____/ \\ ______/\\_______/\\_______/"   <<endl;
    cout<<"                                      | ##"<<endl;
    cout<<"                                      | ##   By : MRcao1001"<<endl;
    cout<<"                                      |__/   Version : 0.0.1-beta"<<endl;
    cout<<endl;
    if(DoesItNeedToBeDisplayed == false){
        cout<<"\033[43;30m 你好, "<<userName<<",欢迎使用Epspace                           您最近一次登陆时间是: "<<LogTime<<"  \033[0m"<<endl;
        return;
    }
    cout<<"\033[43;30m       a: 访客模式    b: 管理员登陆     c: 用户登陆     d: 注册新用户    e: 退出系统                      \033[0m"<<endl;
    cout<<"\033[43;30m EP \033[0;33m 您好 , 请输入您的选择 "<<endl;
    DoesItNeedToBeDisplayed = false;
    return;
}

void Display::ShowLoginPageFunction(int ModeChose){
    string Mode = "DefaultMode";
    string TimeNow = "未登陆";
    /*获取本地时间,判断我是应该说早安还是晚安*/
    time_t timer = time(NULL);
    struct tm *tblock;
    tblock = localtime(&timer);
    (tblock->tm_hour > 12)?((tblock->tm_hour >19)?(TimeNow = "晚上好! "):(TimeNow = "下午好, ")):(TimeNow = "早上好! ");
    (ModeChose == 1)?(Mode = "访客"):( (ModeChose == 2)?(Mode = "尊敬的管理员"):(Mode = "亲爱的员工"));
    //如果是访客,则不要求登陆,直接展示基本功能
    if(ModeChose == 1){
        cout<<"\033[43;30m EP [登陆]\033[0;33m 你可以在不登录的情况下使用以下功能: \033[0m"<<endl;
        return;
    }
    /*如果选择登陆将提示输出到界面上*/
    cout<<endl<<"\033[43;30m EP [登陆]\033[0;33m "<<TimeNow<<Mode<<", 请输入您的 \033[0;37m用户名\033[0;33m和\033[0;37m密码\033[0;33m来登录系统!\033[0m"<<endl;
    
}

void Display::ShowRegPageFunction(int ModeChose){
    string Mode = "DefaultMode";
    string TimeNow = "N/A";
    /*获取本地时间,判断我是应该    string number;说早安还是晚安*/
    time_t timer = time(NULL);
    struct tm *tblock;
    tblock = localtime(&timer);
    (tblock->tm_hour > 12)?((tblock->tm_hour >19)?(TimeNow = "晚上好 , "):(TimeNow = "下午好 , ")):(TimeNow = "早啊 , ");
    (ModeChose == 1)?(Mode = " 亲爱的访客 "):( (ModeChose == 2)?(Mode = " 尊敬的管理员 "):(Mode = " 亲爱的用户 "));
    /*将提示输出到界面上*/
    cout<<endl<<"\033[43;30m EP [登陆]\033[0;33m "<<TimeNow<<"感谢您选择注册EPspace, 您在注册之前需要了解一下我们的条款哦: "<<endl
                <<"这是注册条款，你应该在注册前选择'a: 同意' 或者 'b: 拒绝'："<<endl<<endl  
                <<"\033[0;37m1: 本系统注册需要您输入可用的注册key, 他通常是 '大写字母+user+年月日+四位随机码'. "<<endl
                <<"\033[0;37m3: 注册key十分重要, 因为它关系到您的薪资计算方式和对系统的使用权限, 请务必要准确输入. "<<endl
                <<"\033[0;37m4: 如果您没有注册key, 您可以询问系统管理员或者向您的直属上司申请注册key. "<<endl
                <<"\033[0;37m5: 系统注册时需要您输入您的真实姓名和长度不小于⑧位的密码, 密码中禁止包含 '下划线'. "<<endl
                <<"\033[0;37m6: 您可以使用的功能和您的账户权限有关,若您需要使用更高级的功能,您需要提升您的账户权限. "<<endl
                <<"\033[0;37m7: 如果您在使用过程中发现任何问题,欢迎发送邮件至 caoyong_work.outlook.com. "<<endl<<endl
                <<"\033[0;37m                 a: 同意                        b: 拒绝\033[0m"<<endl;
}

/*这个函数会在登陆之后显示,根据你选择的登陆方式不同给你不同的权限*/
void Display::ShowAppMenuFunction(int ModeChose){
    cout<<endl;
    //所有用户都可以看到的选项
    cout<<"\033[43;30m EP [Menu]\033[0;33m 你好,欢迎使用EPspace,以下是您账户权限下可用的所有功能:\033[0m"<<endl;
    cout<<"\033[43;30m EP [Menu]\033[0;33m 您可以在任意时刻输入'back' 或者 'exit' 来返回或退出,或者输入 'home' 返回主菜单!\033[0m"<<endl<<endl;
    cout<<"\033[43;30m  \033[0;37m a: 公司简介 \033[0m"<<endl<<endl;
    cout<<"\033[43;30m  \033[0;37m b: 公司业务介绍  \033[0m"<<endl<<endl;
    
    if(ModeChose == 1){
        cout<<"\033[43;37m EP [Menu]\033[0;33m 如果您还有更多需求,您可以在任意时刻输入\033[0;37mREG\033[0;33m来开始注册一个新的账户,享用更多权益!\033[0m"<<endl;
        return;
    }
    //游客只能看到此处以上的选项
    cout<<"\033[43;30m  \033[0;37m c: 显示您的个人信息  \033[0m"<<endl<<endl;
    cout<<"\033[43;30m  \033[0;37m d: 修改您的个人信息  \033[0m"<<endl<<endl;
    if(ModeChose == 3){
        //这些功能领导不需要使用只显示给员工
        cout<<"\033[43;30m  \033[0;37m e: 签到/签退  \033[0m"<<endl<<endl;
        cout<<"\033[43;30m  \033[0;37m f: 提交销售额以审核  \033[0m"<<endl<<endl;
        cout<<"\033[43;30m  \033[0;37m g: 查看任务和领导留言  \033[0m"<<endl<<endl;
        cout<<"\033[43;37m EP [Menu]\033[0;33m 这是员工需要使用的功能,如果你想要高级功能,努力吧少年!\033[0m"<<endl;
        return;
    }
    //员工只能看到此处以上的选项,以下是领导可以使用的功能
    cout<<"\033[43;30m  \033[0;37m e  查看所有所属成员  \033[0m"<<endl<<endl;
    cout<<"\033[43;30m  \033[0;37m f  审批销售额报告  \033[0m"<<endl<<endl;
    cout<<"\033[41;37m  \033[0;37m g  提拔/开除员工  \033[0m"<<endl<<endl;
    
     
}
/*输入EP命令之后会显示以通知你进入EP命令模式*/
void Display::ShowEPHelper(){
    cout<<endl;
    cout<<"\033[43;30m EP \033[0;33m 你好,我是EP助手,请多指教! "<<endl;
    cout<<"\033[43;30m EP \033[0;33m 如果你对我还不是很熟悉的话,你可以输入\033[0;37mhelp\033[0;33m来获得一些提示!"<<endl;

}
