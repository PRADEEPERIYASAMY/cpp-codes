#include <iostream>
using namespace std;

class TrieNode{
    public:
    vector<TrieNode*> next;
    string word;
    TrieNode():word(""),next(vector<TrieNode*>(26,nullptr)){};
    ~TrieNode(){
        for (TrieNode*&child : next) if(child) delete child;
    }
};

TrieNode *builTree(vector<string> &word){
    TrieNode *root =new TrieNode();
    for (string &w : word) {
        TrieNode *cur = root;
        for (char &c : w) {
            int idx = c - 'a';
            if(!cur->next[idx]) cur->next[idx] = new TrieNode();
            cur = cur->next[idx];
        }
        cur->word = w;
    }
    return root;
}

void helper(vector<vector<char>> &board,int i,int j,TrieNode *cur,vector<string> &res){
    if(i<0 || i>= board.size() || j<0 || j>= board[0].size() || board[i][j] == '#' || !cur->next[board[i][j] - 'a']) return;
    char c = board[i][j];
    cur = cur->next[c - 'a'];
    if(!cur->word.empty()){
        res.push_back(cur->word);
        cur->word.clear();
    }
    board[i][j] = '#';
    helper(board,i-1,j,cur,res);
    helper(board,i+1,j,cur,res);
    helper(board,i,j-1,cur,res);
    helper(board,i,j+1,cur,res);
    board[i][j] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    if(board.empty() || board[0].empty() || words.empty()) return res;
    TrieNode *root = builTree(words);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            helper(board,i,j,root,res);
        }
    }
    return res;
}

int main() {
	// leetcode
	// https://leetcode.com/problems/word-search-ii/
	return 0;
}

