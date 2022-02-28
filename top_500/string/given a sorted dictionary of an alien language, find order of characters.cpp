#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int i,unordered_map<int,vector<int>> &graph,vector<bool> &visited,stack<int> &st){
    visited[i] = true;
    for (auto &adj : graph[i]) {
        if(!visited[adj]) topologicalSortUtil(adj,graph,visited,st);
    }
    st.push(i);
}

void topologicalSort(unordered_map<int,vector<int>> &graph,int n){
    stack<int> st;
    vector<bool> visited(n,false);
    for (int i = 0; i < n; i++) {
        if(visited[i] == false) topologicalSortUtil(i,graph,visited,st);
    }
    while(!st.empty()){
        cout<<(char)('a'+st.top())<<" ";
        st.pop();
    }
}

void printOrder(string words[],int n,int alpha){
    unordered_map<int,vector<int>> graph;
    for (int i = 0; i < n-1; i++) {
        string word1 = words[i],word2 = words[i+1];
        for (int j = 0; j < min(word1.size(),word2.size()); j++) {
            if(word1[j] != word2[j]){
                graph[word1[j] - 'a'].push_back(word2[j]-'a');
                break;
            }
        }
    }
    topologicalSort(graph,n);
}

int main() {
	// pepcoding
	// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
	string words[] = {"caa", "aaa", "aab"};
    printOrder(words, 3, 3);
	return 0;
}

