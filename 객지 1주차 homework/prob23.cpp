#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int size = 0;

    while (true) {
        int new_number;
        cin >> new_number;

        
        if (new_number == -1)
            break;

        
        int duplicate = 0;

        
        for (int i = 0; i < size; i++) {
            if (numbers[i] == new_number) {
                duplicate = 1;
                break;
            }
        }

        
        if (duplicate==0) {
            
            int insert = 0;
            while (insert < size && numbers[insert] < new_number) {
                insert++;
            }
            
            for (int i = size; i > insert; i--) {
                numbers[i] = numbers[i - 1];
            }
            numbers[insert] = new_number;
            size++;

            
            for (int i = 0; i < size; ++i) {
                cout << numbers[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "duplicate" << endl;
        }
    }

    return 0;
}

