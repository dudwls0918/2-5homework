#include <iostream>
using namespace std;
const int MAX = 100;
int main()
{
    int n;
    cin >> n; 

    
    int starts[MAX], ends[MAX];

    
    for (int i = 0; i < n; ++i) {
        cin >> starts[i] >> ends[i];
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) {
            if (starts[j] < starts[i] || (starts[j] == starts[i] && ends[j] < ends[i])) {
                
                int temp = starts[i];
                starts[i] = starts[j];
                starts[j] = temp;

                temp = ends[i];
                ends[i] = ends[j];
                ends[j] = temp;
                
            }
        }
        
    }
        
    cout << "정렬된 구간 출력" << endl;
     for (int i = 0; i < n; ++i)
     {
        cout << starts[i] << " " << ends[i] << endl;
     }

        return 0;

    
}

