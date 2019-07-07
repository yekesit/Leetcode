//
// Created by Ke Ye on 2019-07-06.
//

#include <iostream>
#include <vector>

using namespace std;

int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

///List is too slow... Let's try map
//List will survie,,, map is dead, lol.
//Maybe vector is ok I think.

//The problem is, there is  a kind of input where there are so many same prefix liek aaaaaaaaaaaaaaab
//Then our set will keep growing bigger and bigger. Then we need a long time to traverse the whole set.
//So after I see some solution from discussion. They ust reverse all things and everytime use a reverse string
//To search in Trie... Well, obviously it can avoid aaaaaaaaaab situatoin.
//But if there is a string like  baaaaaaaaaaaaaaa? They have to keep searching it.... still slow
//Just a tricky method in this problem... Then there is something called AC-automaton...
//https://www.cnblogs.com/nullzx/p/7499397.html. Try to learn it.
// class StreamChecker {
// public:
//     StreamChecker(vector<string>& words) {
//         root = new TrieNode();
//         for(string& w : words){
//             addWord(w);
//         }
//     }

//     bool query(char letter) {
//         return true;
//     }

// private:
//     struct TrieNode{
//         string word;
//         vector<TrieNode*> children;
//         TrieNode(string&& word = "") : word(word){
//             children.resize(26, nullptr);
//         }
//     };
//     TrieNode *root;
//     // list<TrieNode*> exist;
//     unordered_set<TrieNode*> exist;
//     void addWord(string& word){
//         TrieNode *p = root;
//         for(char& w : word){
//             if(!p->children[w - 'a']){
//                 p->children[w - 'a'] = new TrieNode();
//             }
//             p = p->children[w - 'a'];
//         }
//         p->word = word;
//     }
// };

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */





//Try to implement AC-automaton


class StreamChecker{
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto& w : words){
            addWordToTrie(w);
        }
        buildFailInTrie();
        curr = root;
    }

    bool query(char letter) {
        int i = letter - 'a';
        while(curr){
            if(curr->children[i]){
                curr = curr->children[i];
                if(curr->isWord){
                    return true;
                }
                if(curr->fail->isWord){
                    return true;
                }
                return false;
            }
            else{
                curr = curr->fail;
            }
        }
        curr = root;
        return false;
    }
private:
    struct TrieNode{
        TrieNode* fail;
        bool isWord;
        vector<TrieNode*> children;
        TrieNode(){
            fail = nullptr;
            isWord = false;
            children.resize(26, nullptr);
        }
    };
    TrieNode *root;
    TrieNode *curr;

    void addWordToTrie(string& word){
        TrieNode *p = root;
        for(char& w : word){
            if(!p->children[w - 'a']){
                p->children[w - 'a'] = new TrieNode();
            }
            p = p->children[w - 'a'];
        }
        p->isWord = true;
    }

    void buildFailInTrie(){
        queue<TrieNode*> bfs;
        for(auto& c : root->children){
            if(c){
                c->fail = root;
                bfs.push(c);
            }
        }
        while(!bfs.empty()){
            TrieNode *p = bfs.front(); bfs.pop();
            for(int i = 0; i < 26; i++){
                if(p->children[i]){
                    bfs.push(p->children[i]);
                    TrieNode* failTo = p->fail;
                    while(failTo){
                        if(failTo->children[i]){
                            p->children[i]->fail = failTo->children[i];
                            break;
                        }
                        else{
                            failTo = failTo->fail;
                        }
                    }
                    if(!failTo){
                        p->children[i]->fail = root;
                    }
                }
            }
        }
    }

};


int main(){

}