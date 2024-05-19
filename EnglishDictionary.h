#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include <string>
#include "NodeDictionaryG.h"
#include "Entry.h"

class EnglishDictionary {
private:
    std::string name;
    NodeDictionaryG<std::string, std::string> dictionary;

public:
    EnglishDictionary(std::string dictionaryName);
    virtual ~EnglishDictionary();

    int words() const;
    int uniqueWords() const;
    bool empty() const;

    void add(const Entry<std::string, std::string>& entry);
    void deleteFirst(std::string word);
    void deleteWord(std::string word);
    void printDictionary(bool fromBeginning) const;
    void printDefinitions(std::string word, bool fromBeginning) const;
    Entry<std::string, std::string> find(std::string word) const;
};

#endif 
