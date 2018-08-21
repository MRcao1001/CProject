/*
 * @Author: MRcao on ubuntu18.04
 * @Date: 2018-08-13 14:04:29
 * @LastEditors: MRcao
 * @LastEditTime: 2018-08-13 14:04:29
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//vector: 向量容器
class Student {
  public:
    Student();
    void setStu(string name,string gread, string sex);
    string m_name;
    string m_gread;
    string m_sex;
};

Student::Student(){}

void Student::setStu(string name,string gread, string sex){
  m_name = name;
  m_gread = gread;
  m_sex = sex;
}

// << 运算符重载,写入类

int main(int argc, char const *argv[]) {
  /* code */
  vector <Student> stu_vector;
  ofstream file_out("student.txt",ios_base::app);
  for(int i = 0 ;i <5; i++){
    Student stu;
    string name,gread,sex;
    cin >> name ;
    cin >> gread;
    cin >> sex;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    stu.setStu(name,gread,sex);
    stu_vector.push_back(stu);
    file_out << stu_vector[i].m_name<<"_"<< stu_vector[i].m_gread<<"_"<< stu_vector[i].m_sex<<endl;
  }
  file_out.close();
  ifstream file_in("student.txt");
  vector <Student> student_info;
  int i =0;
  while(!(file_in.eof())){
    Student stu;
    char info[1024] = {'\0'};
    file_in.getline(info,100);
    int key = 1;
    for(int j = 0 ; j < 1024 ; j++){
      if(info[j] == '_'){
        j++;
        key ++;
      }
      if(info[j] == '\0'){
        break;
      }
      if(key == 1){
        stu.m_name+=info[j];
      }
      if(key == 2){
        stu.m_gread += info[j];
      }
      if(key == 3){
        stu.m_sex += info[j];
      }
    }
    student_info.push_back(stu);
  }
  for(int m = 0; m < student_info.size();m++){
    cout<< student_info[m].m_name<<"_"<< student_info[m].m_gread<<"_"<< student_info[m].m_sex<<endl;
  }
  return 0;
}
