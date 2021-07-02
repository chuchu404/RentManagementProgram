//#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;
class House                 //房屋类
{
    string address;         //地址
    string houseId;         //房产证号
    string houseType;       //户型
    double area;            //面积
    string decorateLv;      //装修等级
    double rent;            //月租金
public:
    House(string _address="",string _houseId="",string _houseType="",string _area="", string _decorateLv = "", string _rent = "") :
    address(_address),houseId(_houseId),houseType(_houseType),decorateLv(_decorateLv)
    {
        area = atof(_area.c_str());
        rent = atof(_rent.c_str());
    }
    string getAddress() { return address; }
    string getHouseId(){return houseId;}
    string getHouseType() { return houseType; }
    string getArea() { return to_string(area).substr(0, to_string(area).length() - 4); }
    string getDecorateLv() { return decorateLv; }
    string getRent() { return to_string(rent).substr(0, to_string(rent).length() - 4); }
	
    friend ostream& operator<<(ostream& out,const House& h);
	friend istream& operator>>(istream& in,House& h);
	
	/*
    * House(string _address="",string _houseId="",string _houseType="",double _area=0,string _decorateLv="",double _rent=0):
    address(_address),houseId(_houseId),houseType(_houseType),area(_area),decorateLv(_decorateLv),rent(_rent){}
    void printInfo()
    {
        cout<<address<<" "<<houseId<<" "<<houseType<<" "<<area<<" "<<decorateLv<<" "<<rent<<endl;
    }
    static void search(const char *filename,string num);
    static void add(const char *filename,int num);
    static void printAll(const char *filename);
    */
};
class Guest                 //租客类
{
    string id;              //身份证号
    string name;            //姓名
    string workUnit;        //工作单位
    int workAge;            //工龄
    string contacts;        //联系方式
    double allowance;       //租房补贴
public:
    Guest(string _id = "", string _name = "", string _workUnit = "", string _workAge = "", string _contacts = "", string _allowance = "") :
        id(_id), name(_name), workUnit(_workUnit), contacts(_contacts)
    {
        workAge = atof(_workAge.c_str());
        allowance = atof(_allowance.c_str());
    }
    friend ostream& operator<<(ostream& out, const Guest& h);
    friend istream& operator>>(istream& in, Guest& h);
    string getId() { return id; }
    string getName() { return name; }
    string getWorkUnit() { return workUnit; }
    string getWorkAge() { return to_string(workAge).substr(0, to_string(workAge).length() - 4); }
    string getContacts() { return contacts; }
    string getAllowance() { return to_string(allowance).substr(0, to_string(allowance).length() - 4); }//保留2位小数
    /*      //useless part
    Guest(string _id="",string _name="",string _workUnit="",int _workAge=0,string _contacts="",double _allowance=0):
    id(_id),name(_name),workUnit(_workUnit),workAge(_workAge),contacts(_contacts),allowance(_allowance){}
    void printInfo()
    {
        cout<<id<<" "<<name<<" "<<workUnit<<" "<<workAge<<" "<<contacts<<" "<<allowance<<endl;
    }
    //static void search(const char *filename,string num);
    //static void add(const char *filename,int num);
    //static void printAll(const char *filename);
    */

};

class Register              //租房登记信息类
{
    string id;              //身份证号
    string houseId;         //房产证号
    string checkInTime;     //入住时间
    string agreementNum;       //租房合同号
    string remark;          //备注
public:
    Register(string _id="",string _houseId="",string _checkInTime="",string _agreementNum="",string _remark=""):
    id(_id),houseId(_houseId),checkInTime(_checkInTime),agreementNum(_agreementNum),remark(_remark){}
    string getId() { return id; }
    string getHouseId() { return houseId; }
    string getCheckInTime() { return checkInTime; }
    string getAgreementNum() { return agreementNum; }
    string getRemark() { return remark; }
	friend ostream& operator<<(ostream& out,const Register& r);
	friend istream& operator>>(istream& in,Register& r);
	/*
    void printInfo()
    {
        cout<<id<<" "<<houseId<<" "<<checkInTime<<" "<<agreementNum<<" "<<remark<<endl;
    }
    static void search(const char *fileRe,const char *fileHo,const char *fileGu,string num);
    static void add(const char *filename,int num);
    static void printAll(const char *filename);
    */
};
