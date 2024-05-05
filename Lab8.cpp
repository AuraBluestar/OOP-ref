#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

// Comparam si sortam
struct CompareWords {
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
    }
};

int main() {
    // deschidem fisierul
    ifstream file("input.txt");
    if (!file) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Citim fraza si punem in phrase
    string phrase;
    getline(file, phrase);

    // Creem map-ul
    map<string, int> word_counts;
    string word = "";
    for (char c : phrase) {
        if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!') {
            if (!word.empty()) {
                // Trecem totul în lowercase ?i incrementãm count-ul
                for (char& ch : word) {
                    ch = tolower(ch);
                }
                word_counts[word]++;
                word = "";
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        for (char& ch : word) {
            ch = tolower(ch);
        }
        word_counts[word]++;
    }

    // Cream priority queue 
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> sorted_words;
    for (auto i = word_counts.begin(); i != word_counts.end(); ++i)
    {
        const auto& pair = *i;
        sorted_words.push(pair);
    }


    // Afisam 
    while (!sorted_words.empty()) {
        const auto& pair = sorted_words.top();
        cout << pair.first << " => " << pair.second << endl;
        sorted_words.pop();
    }

    return 0;
}
