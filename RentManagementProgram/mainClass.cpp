#include"pch.h"
#include"mainClass.h"

#include<iostream>
#include <fstream>
#include <sstream>

// register obj
ostream& operator<<(ostream& out,const Register& r){
	out<<r.id<<" "<<r.houseId<<" "<<r.checkInTime<<" "<<r.agreementNum<<" "<<r.remark;
	return out;
}

istream& operator>>(istream& in,Register& r){
	in>>r.id>>r.houseId>>r.checkInTime>>r.agreementNum>>r.remark;
	return in;
}

/*
void Register::add(const char *filename,int num=1)
{
	ofstream os(filename,ios_base::binary|ios_base::app);
	while(num--)
	{
		string id;
		string houseId;
		string checkInTime;
		string agreementNum;
		string remark;
		cin>>id>>houseId>>checkInTime>>agreementNum>>remark;
		Register r(id,houseId,checkInTime,agreementNum,remark);
		os<<r;
	}
	os.close();
}
void Register::search(const char *fileRe,const char *fileHo,const char *fileGu,string num)  // redo
{
	ifstream is(fileRe,ios_base::binary);
	Register sread;
	bool flag=false;
	while(!is.eof()){
		is>>sread;
		if(sread.agreementNum==num){
			flag=true;
			break;
		}
	}
	if(flag)sread.printInfo();
	else cout<< "对象未找到！"<<endl;
	is.close();
	is.open(fileGu,ios_base::binary);
	Guest gread;
	flag=false;
	while(!is.eof()){
		is>>gread;
		if(gread.getId()==num){
			flag=true;
			break;
		}
	}
	if(flag)
	{
		cout << "已找到相关租客信息，需要输出吗?" << endl;
		//cout<<"已找到相关租客信息，需要输出吗？"<<endl;		//selection
		//???
		gread.printInfo();
	}
	else cout<<"相关租客未找到！"<<endl;
	is.close();
	is.open(fileHo,ios_base::binary);
	House hread;
	flag=false;
	while(!is.eof()){
		is>>hread;
		if(hread.getId()==num){
			flag=true;
			break;
		}
	}
	if(flag)
	{

		cout << "已找到相关房屋信息，需要输出吗?" << endl;
		//cout << "已找到相关房屋信息，需要输出吗？" << endl;	//selection
		hread.printInfo();
	}
	else cout<< "相关房屋未找到！"<<endl;
	is.close();
}
*/




//guest obj
ostream& operator<<(ostream& out,const Guest& g){
	out<<g.id<<" "<<g.name<<" "<<g.workUnit<<" "<<g.workAge<<" "<<g.contacts<<" "<<g.allowance;
	return out;
}
istream& operator>>(istream& in,Guest& g){
	in>>g.id>>g.name>>g.workUnit>>g.workAge>>g.contacts>>g.allowance;
	return in;
}
/*
void Guest::search(const char *filename,string num)
{
	ifstream is(filename,ios_base::binary);
	Guest sread;
	bool flag=false;
	while(!is.eof()){
		is>>sread;
		if(sread.id==num){
			flag=true;
			break;
		}
	}
	if(flag)sread.printInfo();
	else cout<< "对象未找到！"<<endl;
	is.close();
}
void Guest::add(const char *filename,int num=1)
{
	ofstream os(filename,ios_base::binary|ios_base::app);
	while(num--)
	{
		string id;
		string name;
		string workUnit;
		string workAge;
		string contacts;
		string allowance;
		cin>>id>>name>>workUnit>>workAge>>contacts>>allowance;
		Guest g(id,name,workUnit,workAge,contacts,allowance);
		os<<g;
	}
	os.close();
}
void Guest::printAll(const char *filename){
	ifstream is(filename,ios_base::binary);
	Guest sread;
	while(!is.eof()){
		sread.id="xxxxxx";
		is>>sread;
		if(sread.id!="xxxxxx")
			sread.printInfo();
	}
	is.close();
}
*/




//house obj
ostream& operator<<(ostream& out,const House& h){
	out<<h.address<<" "<<h.houseId<<" "<<h.houseType<<" "<<h.area<<" "<<h.decorateLv<<" "<<h.rent;
	return out;
}
istream& operator>>(istream& in,House& h){
	in>>h.address>>h.houseId>>h.houseType>>h.area>>h.decorateLv>>h.rent;
	return in;
}

/*
void House::search(const char *filename,string num){
	ifstream is(filename,ios_base::binary);
	House sread;
	bool flag=false;
	while(!is.eof()){
		is>>sread;
		if(sread.houseId==num){
			flag=true;
			break;
		}
	}
	if(flag)sread.printInfo();
	else cout<< "对象未找到！"<<endl;
	is.close();
}
void House::add(const char *filename,int num=1)
{
	ofstream os(filename,ios_base::binary|ios_base::app);
	while(num--)
	{
		string address;
		string houseId;
		string houseType;
		double area;
		string decorateLv;
		double rent;
		cin>>address>>houseId>>houseType>>area>>decorateLv>>rent;
		House h(address,houseId,houseType,area,decorateLv,rent);
		os<<h;
	}
	os.close();
}

void House::printAll(const char *filename){
	ifstream is(filename,ios_base::binary);
	House sread;
	while(!is.eof()){
		sread.houseId="xxxxxx";
		is>>sread;
		if(sread.houseId!="xxxxxx")
			sread.printInfo();
	}
	is.close();
}
*/
