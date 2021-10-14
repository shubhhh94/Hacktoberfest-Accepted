#include <iostream>

#include <vector>

using namespace std;

int dp[1024][11];

int cost[10][10];

int n;

vector <int> path;

//code for max 10 city

int solve(int mask,int pos)

{

    if (dp[mask][pos]!=-1)

        return dp[mask][pos];

    int ans=INT_MAX;

    for (int i=0;i<n;i++)

    {

        if ((1<<i)&mask)

        {

            ans=min(ans,cost[pos][i]+solve(mask-(1<<i),i));

        }

    }

    dp[mask][pos]=ans;

    return ans;

}

void pathfinder(int mask,int pos)

{

    path.push_back(pos);

    if (mask==0)

    {

        return;

    }

    int ans=INT_MAX;

    int index=-1;

    for (int i=0;i<n;i++)

    {

        if ((1<<i)&mask)

        {

            if (ans>cost[pos][i]+dp[mask-(1<<i)][i])

            {

                ans=cost[pos][i]+dp[mask-(1<<i)][i];

                index=i;

            }

        }

    }

    pathfinder(mask-(1<<index),index);

}

int main()

{

    cin >> n;

    for (int i=0;i<1024;i++)

    {

        for (int j=0;j<10;j++)

        {

            dp[i][j]=-1;

        }

    }

    for (int i=0;i<n;i++)

    {

        for (int j=0;j<n;j++)

        {

            cin >> cost[i][j];

        }

    }

    for (int i=0;i<n;i++)

    {

        dp[0][i]=cost[i][0];

    }

    cout << solve((1<<n)-2,0) << endl;

    //print path

    pathfinder((1<<n)-2,0);

    for (auto i: path)

    {

        cout << i << " --> ";

    }

    cout << 0 << endl;

}