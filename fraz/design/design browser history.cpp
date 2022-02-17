#include <iostream>
using namespace std;

class BrowserHistory {
    stack<string> history;
    stack<string> future;
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>(); 
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>(); 
    }
    
    string back(int steps) {
        while(steps>0 && history.size()>1){
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps>0 && future.size()>0){
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};

int main() {
	// leetcode
	// https://leetcode.com/problems/design-browser-history/discuss/674486/Two-Stacks-Pretty-code.
	return 0;
}

