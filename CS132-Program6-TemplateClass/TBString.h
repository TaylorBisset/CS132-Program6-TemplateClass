// TBString.h

/*
Declares the TBString class for custom string manipulation.
It defines the structure and interface of the class.
*/

#ifndef TBSTRING_H
#define TBSTRING_H

#include <iostream>

class TBString
{    // You NEED to change the name of the class to reflect your name 
                    //   for example Nancy Programmer would use the name NPString 
public:
    TBString();						// default constructor
    TBString(const TBString& mstr); // copy constructor
    TBString(const char* cstr);     // cstring constructor
    ~TBString();                    // destructor

    int length() const;
    int capacity() const;

    char& operator[](int index);
    char at(int index);
    friend std::istream& operator>>(std::istream& inputStrm, TBString& tbStr);        // replaces `bool read(istream& inputStrm);`
    friend std::ostream& operator<<(std::ostream& outputStrm, const TBString& tbStr); // replaces `void write(ostream& outputStrm);`

    friend TBString operator+(const TBString& lvalue, const TBString& rvalue);

    bool operator!=(const TBString& argStr) const;
    bool operator<(const TBString& argStr) const;       // replaces `bool lessThan(const TBString& argStr);`
    bool operator>(const TBString& argStr) const;       // replaces `bool greaterThan(const TBString& argStr);`
    bool operator==(const TBString& argStr) const;      // replaces `bool equals(const TBString& argStr);`

    TBString& operator=(const TBString& argStr);        // replaces `void setEqualTo(const TBString& argStr);`
    const char* c_str();

    static int getCreatedCount();
    static int getCurrentCount();

private:
    int length(const char* str) const
    {
        int len;
        for (len = 0; str[len] != '\0'; len++) {}
        return len;
    }

    int compareTo(const char* lstr, const char* rstr) const
    {
        while (*lstr != '\0' && *rstr != '\0')
        {
            if (*lstr < *rstr)
            {
                return -1;
            }
            else if (*lstr > *rstr)
            {
                return 1;
            }
            lstr++;
            rstr++;
        }
        if (length(lstr) < length(rstr))
        {
            return -1;
        }
        else if (length(lstr) > length(rstr))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int compareCaseInsensitive(const char* lstr, const char* rstr) const
    {
        // Compare strings case-insensitively
        while (*lstr && *rstr)
        {
            int cmp = tolower(static_cast<unsigned char>(*lstr)) - tolower(static_cast<unsigned char>(*rstr));
            if (cmp != 0)
            {
                return cmp;
            }
            ++lstr;
            ++rstr;
        }
        return tolower(static_cast<unsigned char>(*lstr)) - tolower(static_cast<unsigned char>(*rstr));
    }

    char* str;
    int end;
    int cap;

    static int createdCount;
    static int currentCount;
};

#endif // !TBSTRING_H
