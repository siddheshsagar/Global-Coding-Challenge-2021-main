#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b,int n,int m) 
{
    int x=0,y=0,Finalans=0,currSum=0;

    while (x < n or y < m)
    {
        if (x < n and y < m)
        {
            if (a[x] > b[y])
            {
                currSum += b[y];
                if (currSum >= maxSum)
                    break;
                Finalans++;
                y++;
            }
            else 
            {
                currSum += a[x];
                if (currSum >= maxSum)
                    break;
                Finalans++;
                x++;
            }
        }
        else if (x < a.size())
        {
            currSum += a[x];
            if (currSum > maxSum)
                break;
            Finalans++;
            x++;
        }
        else if (y < b.size())
        {
            currSum += b[y];
            if (currSum > maxSum)
                break;
            Finalans++;
            y++;
        }
        else
            break;
    }
    return Finalans;
}

int main()
{
    ios::sync_with_stdio(false);


    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b,n,m);
    cout << result;
    return 0;
}