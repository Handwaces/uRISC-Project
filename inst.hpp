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

void aluwc(uc a,uc b,uc s,uc &f)
{
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
}

void alunc(uc a,uc b,uc s,uc &f)
{
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
}

void alu(uc a,uc b,uc s,uc &f)
{
	
}
