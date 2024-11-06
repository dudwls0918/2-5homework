#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        data.push_back(num);
    }

    sort(data.begin(), data.end());

    int count = 0;
    for(int i = 0; i < data.size(); i++) {
        if(i == 0 or data[i] != data[i-1])
            count++;
    }
    cout << count << " : ";
    for(int i = 0; i < data.size(); i++) {
        if(i == 0 or data[i] != data[i-1]) {
            cout << data[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
