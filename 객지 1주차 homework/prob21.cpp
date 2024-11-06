#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "정수의 개수를 입력하세요 (n <= 100): ";
    cin >> n;

    int arr[100]; 
    int leaders[100]; 
    int leaderCount = 0; 

    
    cin >> arr[0]; 
    leaders[leaderCount++] = arr[0]; 
    
    for (int i = 1; i < n; ++i) {
        int num;
        cin >> num;
       
        if (num >= leaders[leaderCount - 1]) {
            leaders[leaderCount++] = num; 
        }
    }

    
    cout <<  leaderCount << ":";
    for (int i = 0; i < leaderCount; ++i) {
        cout << " " << leaders[i];
    }
    cout << endl;

    return 0;
}
