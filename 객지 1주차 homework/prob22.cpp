#include <iostream>

using namespace std;

int main() {
    int MAX = 100;
    int prices[100];
    int n = 0;

    
    while (true) {
        int price;
        cin >> price;
        if (price == -1 or n >= MAX)
            break;
        prices[n++] = price;
    }

    
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    cout << maxProfit  << endl;

    return 0;
}
