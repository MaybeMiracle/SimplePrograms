#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class String
{
private:
    char str[1000];
    int nowlength;
public:
    String();
	String(const char s[]);
    void assign(const char s[]);
    void append(const String& str);
	String operator +=(const String& str);
    int compare_to(const String& str) const;
	bool operator ==(const String& str) const;
	bool operator !=(const String& str) const;
	bool operator >(const String& str) const;
	bool operator <(const String& str) const;
	void print(ostream& out) const;
	void print() const;
	friend ostream& operator <<(ostream&, const String&);
    int length() const;
    char element(int i) const;
	char operator [](int i) const;
};

#endif
