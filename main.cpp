#include "EnglishDictionary.h"


#include <bits/stdc++.h>
using namespace std;

int main() {
    EnglishDictionary dictionary("Test Dictionary");
    dictionary.add(Entry<std::string, std::string>("Hello", "Definition of Hello"));
    dictionary.add(Entry<std::string, std::string>("World", "Definition of World"));
    dictionary.add(Entry<std::string, std::string>("Hello", "Another definition of Hello"));

    std::cout << "Number of words in the dictionary: " << dictionary.words() << std::endl;
    std::cout << "Number of unique words in the dictionary: " << dictionary.uniqueWords() << std::endl;

    std::cout << "Printing dictionary from beginning:" << std::endl;
    dictionary.printDictionary(true);

    std::cout << "Printing definitions for 'Hello':" << std::endl;
    dictionary.printDefinitions("Hello", true);

    return 0;
}
