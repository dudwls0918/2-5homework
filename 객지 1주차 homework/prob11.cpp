#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "양의 정수를 입력하세요: ";
    cin >> input;

    string reversed_input = "";
    for (int i = input.size() - 1; i >= 0; --i) {
        reversed_input += input[i];
    }

    cout <<reversed_input << endl;

    return 0;
}
