#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include "../Include/PublicHeader.h"
#include "../Include/CompanyMembers.h"
#include "../Include/FileService.h"

class DataProcessing{
    public:
        DataProcessing();
        ~DataProcessing();
        int LoginProcessing(string &userName, string &passWord, string &nowTime);
        int RegisterProcessing(string &userName, string &passWord, string &key);
        //TODO:还需要的函数
        //1: 显示个人信息的函数
        void showUserInfo(string &userName);
        void changeInfo(string &changeChose, string &changeValue);
        //2: 修改个人信息的函数
        //3: 签到函数和签退函数
        //4: 提交销售额函数(如果用户类型不是PTS则提示不能进行此项操作)
        //5: 查看任务和领导留言(可以和查看个人信息合并)
        //6: 查看所属成员
        //7: 审批销售报告(将销售额修后缀的wait修改为ok,用户登陆之后当销售额包含ok则工资为销售额*0.01)
        //8: 提拔/开除员工(提拔员工将员工key修改为PJM/SLM开头,并删除之前的员工信息表创建新表,开除员工,删除所有与对应员工key相关的信息并把key回收到key表)
    private:
        FileService *fileService;
        vector <CompanyMembers> companyMembersVector_userInfo;
        vector <string> vector_key;
        //预先生成四个用户指针,根据不同的用户登陆情况对其进行实例化
        userReal *user_real;
        vector <userReal> userVector;
        //定义一个全局变量当前登陆的是那种类型的用户,以选择不同的指针进行操作
        string thisTypeOfUser;
        //TODO:需要一个注销函数来delete!
        //定义四种用户向量存储四中用户数据
        
};
void searchUserByUsername(vector <userReal> &userRealVector, string &userName);
#endif