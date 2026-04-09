#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    if (dict.find(endWord) == dict.end())
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto front = q.front();
        string word = front.first;
        int steps = front.second;
        q.pop();

        if (word == endWord)
            return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (dict.find(word) != dict.end()) {
                    q.push({word, steps + 1});
                    dict.erase(word); // avoid revisiting
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength("hit", "cog", wordList);
    return 0;
}
