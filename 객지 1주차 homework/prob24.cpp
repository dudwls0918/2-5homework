#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int data[MAX];
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> data[i];

    
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (data[j] < data[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            
            int temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
    }

    
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";

    return 0;
}


    
