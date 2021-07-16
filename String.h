//
// Created by 86130 on 2021/7/16.
//

#ifndef C__CODE_STRING_H
#define C__CODE_STRING_H


#include <cstring>
#include <iostream>

class String {
public:
    String(const char* ctr = 0);
    String(const String& str);
    String& operator=(const String & str);
    ~String();
    char* get_c_str() const { return m_data; }
private:
    char * m_data;
};

inline
String::String(const char *ctr) {
    if (ctr) {
        m_data = new char [strlen(ctr) + 1];
        strcpy(m_data, ctr);
    } else {
        m_data = new char [1];
        *m_data = '\0';
    }
}

inline
String::~String() {
    delete[] m_data;
}

inline
String::String(const String &str) {
    std::cout << "invoke\n";
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline
String & String::operator=(const String &str) {
    if (this == &str) {
        return *this;
    }

    delete[] m_data;
    m_data = new char [strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

#endif //C__CODE_STRING_H
