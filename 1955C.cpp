#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    deque<ll> durabilities(n);
    for (ll &i : durabilities)
        cin >> i;

    int res = 0;
    while (k > 0 && !durabilities.empty())
    {
        if (durabilities.size() == 1)
        {
            if (k >= durabilities.front())
            {
                res++;
                k -= durabilities.front();
                durabilities.pop_front();
            }
            break;
        }

        ll front = durabilities.front();
        ll back = durabilities.back();

        if (front > back)
        {
            if (k >= 2 * back)
            {
                res++;
                k -= 2 * back;
                durabilities[0] -= back;
                durabilities.pop_back();
            }
            else
            {
                break;
            }
        }
        else if (front < back)
        {
            if (k >= 2 * front)
            {
                res++;
                k -= 2 * front;
                durabilities.pop_front();
                durabilities.back() -= front;
            }
            else if (k == 2 * front - 1)
            {
                res++;
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (k >= 2 * front)
            {
                durabilities.pop_front();
                durabilities.pop_back();
                k -= 2 * front;
                res += 2;
            }
            else if (k == 2 * front - 1)
            {
                res++;
                break;
            }
            else
            {
                break;
            }
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