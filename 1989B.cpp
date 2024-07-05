#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

void solve()
{
    string a, b;
    cin >> a;
    cin >> b;

    ll res = a.size();
    int longest_subse = 0;

    int i = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        int subse = i;
        for (int j = 0; j < a.size(); ++j)
        {

            if (b[subse] == a[j])
            {
                subse++;
            }
        }
        longest_subse = max(longest_subse, subse - i);
    }

    cout << res + (b.size() - longest_subse) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}