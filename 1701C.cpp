#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> proficiency(m);
    vector<int> working_times(n, 0);
    for (int &i : proficiency)
        cin >> i;

    ll min_t = m / n;
    ll max_t = 2 * m;

    for (int i = 0; i < m; ++i)
        working_times[proficiency[i] - 1]++;

    ll res = 0;
    while (min_t <= max_t)
    {
        ll vacant = 0, over = 0;
        ll mid = (max_t + min_t) / 2;

        for (int i = 0; i < n; ++i)
        {
            ll t = working_times[i];
            if (t > mid)
                over += (t - mid);
            else if (t < mid)
                vacant += (mid - t) / 2;
        }

        if (vacant >= over)
        {
            max_t = mid - 1;
            res = mid;
        }
        else if (vacant < over)
        {
            min_t = mid + 1;
        }
    }

    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}