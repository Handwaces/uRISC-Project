/*
main.cpp - The main C++ code file in uRISC emulator.

Copyright (C) 2018 John

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>. 
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "inst.hpp"
using namespace std;

typedef unsigned char uc;

uc mem[65536]={0};
uc reg[16]={0};



int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		cout<<"Error #1:"<<endl;
		cout<<"Invaild commandLine"<<endl;
		exit(1);
	}
	FILE *cf=fopen(argv[1],"r");
	if(cf==NULL)
	{
		cout<<"Error #2:"<<endl;
		cout<<"Cannot open file:"<<argv[1]<<endl;
		exit(2);
	}
	for(int i=0;i<65536;i++)
	{
		mem[i]=fgetc(cf);
	}
	for(int i=0;i<16;i++)
	{
		reg[i]=fgetc(cf);
	}
	if(fclose(cf)==-1)
	{
		cout<<"Warning #3:"<<endl;
		cout<<"Cannot close file:"<<argv[1]<<endl;
	}
	while(1)
	{
		
	}
}
