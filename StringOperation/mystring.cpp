#include "mystring.h"
#include <iostream>
#include <cstring>

using namespace std;

String::String()
{
    this->str[1] = '\0'; 
    this->nowlength = 0;
}

String::String(const char s[])
{
    for(int i = 0; i < (int)strlen(s); i++)
	{
	    this->str[i + 1] = s[i];
	}
    this->nowlength = (int)strlen(s);
}

void String:: assign(const char s[])
{
	for(int i = 0; i < (int)strlen(s); i++)
	{
	    this->str[i + 1] = s[i];
	}
    this->nowlength = (int)strlen(s);
}

void String:: append(const String& str)
{
	for(int i = this->nowlength + 1; i <= this->nowlength + str.nowlength; i++)
	{
		this->str[i] = str.str[i - this->nowlength];
	}
	this->nowlength = this->nowlength + str.nowlength;
}

String String:: operator +=(const String& str)
{
	for(int i = this->nowlength + 1; i <= this->nowlength + str.nowlength; i++)
	{
		this->str[i] = str.str[i - this->nowlength];
	}
	this->nowlength = this->nowlength + str.nowlength;
	return this->str;
}

int String:: compare_to(const String& str) const
{
    for(int i = 1; i <= this->nowlength && i <= str.nowlength; i++)
	{
		if(str.element(i) > this->str[i])
		{
    		return -1;
		}
		else if(str.element(i) < this->str[i])
		{
			return 1;
		}
	}
	if(str.nowlength > this->nowlength)
	{
		return -1;
	}
	else if(str.nowlength < this->nowlength)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool String:: operator ==(const String& str) const
{
	for(int i = 1; i <= this->nowlength && i <= str.nowlength; i++)
	{
		if(str.element(i) != this->str[i])
		{
    		return false;
		}
	}
	if(str.nowlength != this->nowlength)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool String:: operator !=(const String& str) const
{
	for(int i = 1; i <= this->nowlength && i <= str.nowlength; i++)
	{
		if(str.element(i) != this->str[i])
		{
    		return true;
		}
	}
	if(str.nowlength != this->nowlength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String:: operator >(const String& str) const
{
	for(int i = 1; i <= this->nowlength && i <= str.nowlength; i++)
	{
		if(str.element(i) > this->str[i])
		{
    		return false;
		}
		else if(str.element(i) < this->str[i])
		{
			return true;
		}
	}
	if(str.nowlength >= this->nowlength)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool String:: operator <(const String& str) const
{
	for(int i = 1; i <= this->nowlength && i <= str.nowlength; i++)
	{
		if(str.element(i) > this->str[i])
		{
    		return true;
		}
		else if(str.element(i) < this->str[i])
		{
			return false;
		}
	}
	if(str.nowlength >= this->nowlength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void String:: print(ostream& out) const
{
    for(int i = 1; i <= this->nowlength; i++)
	{
    	out<<this->str[i];
	}
}

void String:: print() const
{
    for(int i = 1; i <= this->nowlength; i++)
	{
    	cout<<this->str[i];
	}
}

ostream& operator <<(ostream& out, const String& r)
{
	r.print(out);  
    return out; 
}

int String:: length() const
{
	return this->nowlength;
}

char String:: element(int i) const
{
	if(i >= 1 && i <= this->nowlength)
	{
		return this->str[i];
	}
	else
	{
		cout<<"Warning: input location is out-of-range for the string."<<endl;
		return '\0';
	}
}

char String:: operator [](int i) const
{
	if(i >= 1 && i <= this->nowlength)
	{
		return this->str[i];
	}
	else
	{
		cout<<"Warning: input location is out-of-range for the string."<<endl;
		return '\0';
	}
}
