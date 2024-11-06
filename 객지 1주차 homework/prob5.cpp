#include <iostream>
#include <climits> 
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int min = INT_MAX; 

    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        
        if (num >= 0 && num < min) {
            min = num;
        }
    }

    
    if (min == INT_MAX) {
        cout << -1 << endl; 
    }
    else 
        cout <<  min << endl;


    return 0;
}
