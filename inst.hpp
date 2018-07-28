/*
inst.hpp - The instructions define file in uRISC emulator.

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

#include "nop.hpp"

typedef unsigned char uc;

void lgu(uc a,uc b,uc s,uc &f)
{
	switch(s)
	{
		case 0:
			f=!a;
			break;
		case 1:
			f=!(a&b);
			break;
		case 2:
			f=(!a)|b;
			break;
		case 3:
			f=255;
			break;
		case 4:
			f=!(a|b);
			break;
		case 5:
			f=!b;
			break;
		case 6:
			f=!(a^b);
			break;
		case 7:
			f=a|(!b);
			break;
		case 8:
			f=(!a)&b;
			break;
		case 9:
			f=a^b;
			break;
		case 10:
			f=b;
			break;
		case 11:
			f=a|b;
			break;
		case 12:
			f=0;
			break;
		case 13:
			f=a&(!b);
			break;
		case 14:
			f=a&b;
			break;
		case 15:
			f=a;
			break;
	}
}

void aluwc(uc a,uc b,uc s,uc &fi)
{
	int f=0;
	switch(s)
	{
		case 0:
			f=a;
			break;
		case 1:
			f=a&b;
			break;
		case 2:
			f=a&(!b);
			break;
		case 3:
			f=0;
			break;
		case 4:
			f=a+(a|(!b))+1;
			break;
		case 5:
			f=(a&b)+(a|(!b))+1;
			break;
		case 6:
			f=a-b;
			break;
		case 7:
			f=a|(!b)+1;
			break;
		case 8:
			f=a+(a|b)+1;
			break;
		case 9:
			f=a+b+1;
			break;
		case 10:
			f=(a&(!b))+(a|b)+1;
			break;
		case 11:
			f=(a|b)+1;
			break;
		case 12:
			f=a+a+1;
			break;
		case 13:
			f=(a&b)+a+1;
			break;
		case 14:
			f=(a&(!b))+a+1;
			break;
		case 15:
			f=a+1;
			break;
	}
	if(f>=256) sbit(reg[15],1,1);
	fi=f;
}

void alunc(uc a,uc b,uc s,uc &fi)
{
	int f=0;
	switch(s)
	{
		case 0:
			f=a-1;
			break;
		case 1:
			f=(a&b)-1;
			break;
		case 2:
			f=(a&(!b))-1;
			break;
		case 3:
			f=-1;
			break;
		case 4:
			f=a+(a|(!b));
			break;
		case 5:
			f=(a&b)+(a|(!b));
			break;
		case 6:
			f=a-b-1;
			break;
		case 7:
			f=a|(!b);
			break;
		case 8:
			f=a+(a|b);
			break;
		case 9:
			f=a+b;
			break;
		case 10:
			f=(a&(!b))+(a|b);
			break;
		case 11:
			f=a|b;
			break;
		case 12:
			f=a+a;
			break;
		case 13:
			f=(a&b)+a;
			break;
		case 14:
			f=(a&(!b))+a;
			break;
		case 15:
			f=a;
			break;
	}
	if(f>=256) sbit(reg[15],1,1);
	fi=f;
}

void alu(uc a,uc b,uc s,uc &f)
{
	bool cn=gbit(reg[15],0);
	if(cn==1) aluwc(a,b,s,f);
	else alunc(a,b,s,f);
	if(l4bit(f)==15) sbit(reg[15],1,2);
	if(h4bit(f)==15) sbit(reg[15],1,3);
}

void mrd(uc &a,uc b)
{
	uc ds=reg[14];
	a=mem[ds*256+b];
}

void mwt(uc a,uc b)
{
	uc ds=reg[14];
	mem[ds*256+b]=a;
}

void ior(uc &a,uc b)
{
	uc ds=reg[14];
	//Porcess inside IO port
	if(ds*256+b==0) a=getchar();
}

void iow(uc a,uc b)
{
	uc ds=reg[14];
	//Porcess inside IO port
	if(ds*256+b==0) putchar(a);
}

void imm(uc &des,u val)
{
	des=val;
}

void nop()
{
	__nop();
}
