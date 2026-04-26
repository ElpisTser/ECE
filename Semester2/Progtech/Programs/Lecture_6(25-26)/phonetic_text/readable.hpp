#pragma once

#include <string>
#include <map>
#include <vector>

class readable {
private:
    std::string normalText;
    std::string phoneticText;

    static std::map<char, std::string> phoneticMap;
    static std::map<std::string, char> invPhoneticMap;
    static const std::vector<std::string> phoneticWords;
    
    static void initializeMappings();
    static std::string char2Phonetic(const char& c);
    static std::string text2Phonetic(const std::string& txt);
    static char phonetic2Char(const std::string& s);
    static std::string phonetic2Text(const std::string& t);

public:
    readable();
    readable(const std::string& someText);

    std::string phonetic() const;
    std::string text() const;
    void setPhonetic(const std::string& pText);
    void setText(const std::string& nText);
};

