#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> hint(n - 1);
        vector<int> frequency(n + 1);

        for (int i = 0; i < n - 1; i++) {
            cin >> hint[i];
        }

        for (int z : hint) {
            frequency[z]++;
        }

        if (hint.back() != 1) {
            cout << -1 << endl;
            continue;
        }

        if (frequency[1] > 2 || frequency[1] == 0) {
            cout << -1 << endl;
            continue;
        }

        bool invalid = false;

        int missing1 = 0;
        int missing2 = 0;
        for (int i = 2; i <= n; i++) {
            if (frequency[i] > 1) {
                cout << -1 << endl;
                invalid = true;
                break;
            }
            if (frequency[i] == 0) {
                if (missing1 != 0) {
                    missing2 = i;
                }
                else {
                    missing1 = i;
                }
            }
        }

        if(invalid) {
            continue;
        }

        if (frequency[1] == 1) {
            reverse(hint.begin(), hint.end());
            for (int value : hint) {
                cout << value << " ";
            }
            cout << missing1 << endl;
        }
        else {
            int left = 0;
            int right = n - 1;
            int h = 0;
            
            vector<int> ans(n);
            ans[left] = missing1;
            ans[right] = missing2;
            while (h != n - 1) {
                if (ans[right] > ans[left]) {
                    ans[right - 1] = hint[h];
                    h++;
                    right--;
                } else {
                    ans[left + 1] = hint[h];
                    h++;
                    left++;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    cout << ans[i] << " ";
                }
                else {
                    cout << ans[i] << endl;
                }
            }
            
        }




        
    
    }



}