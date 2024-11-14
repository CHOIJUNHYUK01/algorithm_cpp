[링크](https://www.acmicpc.net/problem/1629)

```
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;

int go(int b)
{
    if (b == 1)
        return a % c;

    ll ret = go(b / 2);
    ret = (ret * ret) % c;

    if (b % 2)
    {
        ret = (ret * a) % c;
    }

    return ret;
}

int main()
{
    cin >> a >> b >> c;

    cout << go(b);

    return 0;
}
```
