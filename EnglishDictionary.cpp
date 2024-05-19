#include "EnglishDictionary.h"

EnglishDictionary::EnglishDictionary(std::string dictionaryName)
    : name(dictionaryName), dictionary() {}

EnglishDictionary::~EnglishDictionary() {}

int EnglishDictionary::words() const {
    return dictionary.size();
}

int EnglishDictionary::uniqueWords() const {
    return dictionary.uniqueKeys();
}

bool EnglishDictionary::empty() const {
    return dictionary.empty();
}

void EnglishDictionary::add(const Entry<std::string, std::string>& entry) {
    dictionary.put(entry.getK(), entry.getV());
}

void EnglishDictionary::deleteFirst(std::string word) {
    dictionary.erase(word);
}

void EnglishDictionary::deleteWord(std::string word) {
    while (dictionary.findAll(word).first != dictionary.end()) {
        dictionary.erase(dictionary.findAll(word).first);
    }
}

void EnglishDictionary::printDictionary(bool fromBeginning) const {
    if (fromBeginning) {
        dictionary.print(true);
    } else {
        dictionary.print(false);
    }
}

void EnglishDictionary::printDefinitions(std::string word, bool fromBeginning) const {
    NodeDictionaryG<std::string, std::string>::Range range = dictionary.findAll(word);
    if (fromBeginning) {
        dictionary.print(range.first);
    } else {
        dictionary.print(--range.second);
    }
}

Entry<std::string, std::string> EnglishDictionary::find(std::string word) const {
    NodeDictionaryG<std::string, std::string>::IteratorG it = dictionary.find(word);
    if (it != dictionary.end()) {
        return *it;
    } else {
        return Entry<std::string, std::string>("", "");
    }
}
