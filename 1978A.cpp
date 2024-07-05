#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> pages(n);

    int highest = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> pages[i];
        if (i < n - 1)
            highest = max(pages[i], highest);
    }

    cout << highest + pages[n - 1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}