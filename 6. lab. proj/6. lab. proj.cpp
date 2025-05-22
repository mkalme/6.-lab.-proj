//221RDB411 Miķelis Kalme-Danenbaums

#include <iostream>
#include <string>
#include <map>

bool AreAnagrams(std::string word1, std::string word2) {
    if (word1.size() != word2.size()) return false;
    
    std::map<char, int> word1Map = {};
    std::map<char, int> word2Map = {};

    for (int i = 0; i < word1.size(); i++) {
        word1Map[word1[i]]++;
        word2Map[word2[i]]++;
    }

    if (word1Map.size() != word2Map.size()) return false;

    for (auto i = word1Map.begin(); i != word1Map.end(); ++i) {
        if (word2Map.find(i->first) == word2Map.end()) return false;
        if (word2Map[i->first] != i->second) return false;
    }

    return true;
}

int main()
{
    std::string word1, word2;
    std::cin >> word1;
    std::cin >> word2;

    if (AreAnagrams(word1, word2)) {
        std::cout << "YES\n";
    }
    else {
        std::cout << "NO\n";
    }
}