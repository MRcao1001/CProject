#include "../Include/CompanyMembers.h"
/*构造函数在创建对象时调用,根据key的类型来决定创建不同的对象
 *员工没有keyStartWords,只有key,key是其对应的上级的keyStartWords+注册年月日+随机四位数
 *经理拥有keyStartWords,可以添加空白key到key文件,用来给新员工注册
 *有一个特殊对象总经理对象,用户名是admin,在该用户的操作界面内可以任意添加删除成员,
 */

/*构造函数:在生成对象的同时初始化其 用户名 密码 key 职位 手机号 工资*/
CompanyMembers::CompanyMembers(){
    number = "null";
    name = "null";
    password = "null";
    key = "null";
    wages = "0";
}

PartTimeSales::PartTimeSales(){

}

PartTimeTechnicians::PartTimeTechnicians(){

}

ProjectManager::ProjectManager(){

}

SalesManager::SalesManager(){

}
//TODO: 该函数通过计算每日打卡时间差或者销售额或者月固定工资(根据职位)来计算工资
void CompanyMembers::setWages(int &getWages){
    wages = to_string(getWages);
}


//TODO: 经理每天会统计兼职销售的销售额并计入每个人的账户,用户登陆之后自动根据销售额生成当日工资,
void PartTimeSales::setSalesVolume(int &getSalesVolume){
    SalesVolume_pts = to_string(getSalesVolume);
}

//TODO: 每天登陆时计算前一天打卡时间差统计工作时间存入文件
void PartTimeTechnicians::setWorkTime(string &getWorkTime){
    Log = getWorkTime;
}

//TODO: 在经理登陆时调用此函数遍历文件内所有的用户匹配keyStartWords计数写入经理账户
void ProjectManager::setNumberOfEmployees(int &getNumberOfEmployees){
    NumberOfEmployees_pjm = to_string(getNumberOfEmployees);
}

//FINISH: 在经理登陆时调用此函数遍历文件内所有的用户匹配keyStartWords计数写入经理账户
void ProjectManager::setKeyStartWords(){
    keyStartWords = "PJM"+name;
}

//TODO: 在经理登陆时调用此函数遍历文件内所有的用户匹配keyStartWords计数写入经理账户
void SalesManager::setNumberOfEmployees(int &getNumberOfEmployees){
    NumberOfEmployees_slm = to_string(getNumberOfEmployees);
}

//FINISH: 在经理登陆时调用此函数遍历文件内所有的用户匹配keyStartWords计数写入经理账户
void SalesManager::setSalesVolume(){
    SalesVolume_slm = "0";
}
userReal::userReal(){

}
userReal::~userReal(){

}