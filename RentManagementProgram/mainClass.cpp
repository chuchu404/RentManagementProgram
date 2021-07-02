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
//guest obj
ostream& operator<<(ostream& out,const Guest& g){
	out<<g.id<<" "<<g.name<<" "<<g.workUnit<<" "<<g.workAge<<" "<<g.contacts<<" "<<g.allowance;
	return out;
}
istream& operator>>(istream& in,Guest& g){
	in>>g.id>>g.name>>g.workUnit>>g.workAge>>g.contacts>>g.allowance;
	return in;
}

//house obj
ostream& operator<<(ostream& out,const House& h){
	out<<h.address<<" "<<h.houseId<<" "<<h.houseType<<" "<<h.area<<" "<<h.decorateLv<<" "<<h.rent;
	return out;
}
istream& operator>>(istream& in,House& h){
	in>>h.address>>h.houseId>>h.houseType>>h.area>>h.decorateLv>>h.rent;
	return in;
}
