#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Gin
{
    string code;
    int hamming;
    bool operator<(const Gin &gin)
    {
        return hamming - gin.hamming;
    }
};

main()
{
    freopen("exercise006.in", "r", stdin);

    int m, n;
    while (scanf("%d%d", &m, &n) == 2 && m && n)
    {
        vector<Gin> gins;

        for (int i = 0; i < m; i++)
        {
            string code;
            int totalHamming = 0;
            getline(cin, code);

            for (Gin g : gins)
            {
                int hamming = 0;
                for (int j = 0; j < n; j++)
                {
                    if (code[j] != g.code[j])
                        hamming++;
                }

                g.hamming += hamming;
                totalHamming += hamming;
            }

            gins.push_back({code, totalHamming});
        }

        sort(gins.begin(), gins.end());

        cout << gins[0].code << endl;
    }

    return 0;
}