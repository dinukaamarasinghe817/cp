// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-01/challenges/a-game-of-wits-and-cunning
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<double> heights;
        for (int i = 0; i < n; i++)
        {
            double val;
            cin >> val;
            heights.push_back(val);
        }
        string hair_col;
        cin >> hair_col;
        set<double> u_h;

        for (int i = 0; i < heights.size(); i++)
        {
            u_h.insert(heights[i]);
        }

        if ((heights.size() != u_h.size()) || (heights.size() % 2 == 1))
        {
            cout << -1 << endl;
        }
        else
        {
            vector<double> heights_d = heights;

            sort(heights.begin(), heights.end(), greater<int>());

            vector<int> ans;

            for (int i = 0; i < heights_d.size(); i++)
            {
                for (int j = 0; j < heights.size(); j++)
                {
                    if (heights_d[i] == heights[j])
                    {
                        ans.push_back(abs(i - j));
                        break;
                    }
                }
            }

            int sum = 0;

            for (int i = 0; i < ans.size(); i++)
            {
                sum += ans[i];
            }
            cout << sum << endl;
        }
    }
}
