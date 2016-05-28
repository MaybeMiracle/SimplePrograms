#ifndef MYSTRING_H
#define MYSTRING_H

class String
{
private:
    char str[1000];
    int nowlength;
public:
    String();
    void assign(const char s[]);
    void append(const String &str);
    int compare_to(const String &str) const;
    void print() const;
    int length() const;
    char element(int i) const;
};

#endif
