/*
bit.hpp - The bit-op header in uRISC emulator.

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

/*
 b7 # # # # # # # # b0
    ^h4bit^ ^l4bit^
    7 6 5 4 3 2 1 0 <<gbit,sbit 
*/

uc h4bit(uc _src)
{
	_src=_src>>4;
	return _src;
}

uc l4bit(uc _src)
{
	_src=_src%16;
	return _src;
}

bool gbit(uc _src,int pos)
{
	_src=_src>>pos;
	return _src%2;
}

void sbit(uc &_des,bool _val,int pos)
{
	/*bool b[8]={0};
	for(int i=0;i<8;i++)
	{
		b[i]=gbit(_des,i);
	}
	b[pos]=_val;
	_des=0;
	int k=1;
	for(int i=0;i<8;i++)
	{
		_des+=k*b[i];
		k*=2;
	}
	*/
	uc a=1;
	a=a<<pos;
	if(_val==true)
	{
		_des|=a;
	}
	else
	{
		a=!a;
		_des&=a;
	}
}
