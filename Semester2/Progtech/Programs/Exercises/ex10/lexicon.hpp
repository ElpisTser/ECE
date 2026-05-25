#ifndef LEXICON_HPP
#define LEXICON_HPP

#include <iostream>
#include <string>

class lexicon {
public:
    lexicon();
    ~lexicon();

    void insert(const std::string& s);
    int lookup(const std::string& s) const;
    int depth(const std::string& s);
    void replace(const std::string& s1, const std::string s2);

    friend std::ostream & operator <<(std::ostream& out, const lexicon& l);
private:
    struct Node {
        Node(const std::string& s, int f , Node* l, Node* r) : 
            word(s), freq(f), left(l), right(r) {}
        Node() : word(""), freq(0), left(nullptr), right(nullptr) {}
        
        std::string word;
        Node* left;
        Node* right;
        int freq;
    };
    Node* root;

    void deleteTree(Node* node);

    static void printHelp(Node* node, std::ostream& out);
};

#endif