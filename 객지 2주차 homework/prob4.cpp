#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int sum = 0, start = 0;
    bool is_addition = true; 

    
    if (s[0] == '-') {
        is_addition = false;
        start = 1;
       }
    else
    {
        while (true)
        {
            int findex_plus = s.find("+", start); 
            int findex_minus = s.find("-", start);

            int findex;
            if (findex_plus == -1 && findex_minus == -1)
            {
                string part = s.substr(start);
                if (part == "")
                    break;
                if (is_addition)
                    sum += stoi(part);
                else
                    sum -= stoi(part);
                break;
            }
            else if (findex_plus == -1 || (findex_minus != -1 && findex_minus < findex_plus))
            {
                findex = findex_minus;
                is_addition = false; 
            }
            else
            {
                findex = findex_plus;
                is_addition = true;
            }

            int count = findex - start;
            string part = s.substr(start, count);
            if (is_addition)
                sum += stoi(part);
            else
                sum -= stoi(part);
            start = findex + 1;
        }
    }
    cout << sum << endl;
    return 0;
}
