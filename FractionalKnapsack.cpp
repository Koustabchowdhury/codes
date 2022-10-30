#include <bits/stdc++.h>
using namespace std;

struct knapsack
{
    int val;
    int wt;
    float frac;
};

bool compare(const knapsack &obj1, const knapsack &obj2)
{
    if (obj2.frac < obj1.frac)
        return 1;
    return 0;
}

double Knap(int W, struct knapsack obj[], int N)
{
    double finalvalue = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (obj[i].wt <= W)
        {
            W -= obj[i].wt;
            finalvalue += obj[i].val;
        }
        else
        {
            finalvalue += obj[i].val * ((double)W / (double)obj[i].wt);
            break;
        }
    }
    return finalvalue;
}
int main()
{
    int n;
    cout << "Enter Number of Sacks : ";
    cin >> n;
    int w;
    cout << "Enter Weight(Capacity) Of Sack : ";
    cin >> w;

    knapsack obj[n];
    cout << "Enter Value and Weight : ";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << i + 1 << " : ";
        cin >> obj[i].val >> obj[i].wt;
        obj[i].frac = obj[i].val / obj[i].wt;
    }
    sort(obj, obj + n, &compare);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].val << " " << obj[i].wt << " " << obj[i].frac << endl;
    }
    cout << "Maximum Profit : " << Knap(w, obj, n);
    return 0;
}
