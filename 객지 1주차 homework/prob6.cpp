#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "양의 정수 N를 입력해주세요" << endl
    cin >> N;



    

    int min = 0, max = 0;

    
    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

        if (i == 0) 
        {
            min = num;
            max = num;
        }
        else 
        {
            if (num < min) 
            {
                min = num;
            }
            if (num > max) 
            {
                max = num;
            }
        }

        int difference = max - min;
        cout << difference << " ";
    }

    return 0;
}
