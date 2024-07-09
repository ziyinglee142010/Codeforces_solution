#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve()
{
    int x;
    cin >> x;

    vector<int> valid_arr(31, 0);

    int pos = 0;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            if (valid_arr[pos])
            {
                valid_arr[pos] = 0;
                valid_arr[pos + 1] = 1;
            }
            else if (pos - 1 >= 0)
            {

                if (valid_arr[pos - 1] == 1)
                {
                    valid_arr[pos - 1] = -1;
                    valid_arr[pos + 1] = 1;
                }
                else
                {
                    valid_arr[pos] = 1;
                }
            }
            else
            {
                valid_arr[pos] = 1;
            }
        }
        pos++;
        x /= 2;
    }

    int size = 0;
    if (valid_arr[pos] == 1)
    {
        size = pos + 1;
    }
    else
    {
        size = pos;
    }

    cout << size << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << valid_arr[i];
        if (i != size - 1)
        { // Don't print a space after the last element
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}