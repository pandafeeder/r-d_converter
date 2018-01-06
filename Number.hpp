//
//  Number.hpp
//  Roman2Decimal
//
//  Created by qusr on 01/01/2018.
//  Copyright © 2018 qusr. All rights reserved.
//

#ifndef Number_hpp
#define Number_hpp

#include <string>
#include <vector>
#include <regex>
#include <map>
#include <stdexcept>
#include <iostream>

static std::map<std::string, unsigned> roman2NumMap =
{
    {"I", 1},
    {"IV", 4},
    {"VI", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000},
};


static std::map<int, std::string> num2RomanMap =
{
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

static std::regex re("^(M{0,3})(CM|DC{0,3}|CD|C{0,3})(XC|LX{0,3}|XL|X{0,3})(IX|VI{0,3}|IV|I{0,3})$");

static int nums[13] {1000,900,500,400,100,90,50,40,10,9,5,4,1};

unsigned r2d(const std::smatch&);
std::string d2r(const unsigned&);
std::smatch get_patterns(const std::string&);

class Number {
public:
    Number() = default;
    Number(const std::string &s): roman(s) {}
    Number(const unsigned &i): decimal(i) {}
    virtual std::string get_roman() const = 0;
    virtual unsigned get_decimal() const = 0;
protected:
    std::string roman;
    unsigned decimal;
};

class Roman: public Number {
public:
    Roman() = default;
    Roman(const std::string &r): Number(r), pats(get_patterns(r)) {}
    std::string get_roman() const override {return roman;}
    unsigned  get_decimal() const override {return r2d(pats);};
private:
    std::smatch pats;
};

class Decimal: public Number {
public:
    Decimal() = default;
    Decimal(const unsigned short &d): Number(d)
    {
        if (d >= 4000)
            throw "maximum number is 3999";
    }
    std::string get_roman() const override {return d2r(decimal);}
    unsigned  get_decimal() const override {return decimal;}
};


#endif /* Number_hpp */
