#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<string> statements(n);

    for (int i = 0; i < n; i++) {
        cin >> statements[i];
    }

    vector<int> goodStart(n);
    int leftMostTrueBlock = n - 1;
    int rightMostTrueBlock = 0;
    bool trueBlock = true;
    for (int i = 0; i < n; i++) {
        if (statements[i] == "true" && trueBlock) {
            goodStart[i] = 1;
        }
        else if (statements[i] == "false" && trueBlock) {
            goodStart[i] = 1;
            trueBlock = false;
        }
        if (statements[i] == "or") {
            if (trueBlock && leftMostTrueBlock == (n - 1)) { 
                leftMostTrueBlock = i - 1;
            }
                
            trueBlock = true;
        }
    }

    vector<int> goodEnd(n);
    trueBlock = true;
    for (int i = n - 1; i >= 0; i--) {
        if (statements[i] == "true" && trueBlock) {
            goodEnd[i] = 1;
        }
        else if (statements[i] == "false" && trueBlock) {
            goodEnd[i] = 1;
            trueBlock = false;
        }
        if (statements[i] == "or") {
            if (trueBlock && rightMostTrueBlock == 0) { 
                rightMostTrueBlock = i + 1;
            }
                
            trueBlock = true;
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        string c;
        cin >> c;

        if (c == "true" && ((goodStart[a] == 1 && goodEnd[b] == 1) || (a > leftMostTrueBlock || b < rightMostTrueBlock))) {
            cout << 'Y';
        }
        else if(c == "false" && a <= leftMostTrueBlock && b >= rightMostTrueBlock) {
            cout << 'Y';
        } 
        else {
            cout << 'N';
        }
        
    }

}