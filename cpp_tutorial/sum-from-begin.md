# 등차수열의 합

```c++
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 5, ret = 0;

    for(int i=1; i<=n; i++) {
        ret += i;
    }

    cout << ret << "\n";
    cout << n * (n+1) / 2 << "\n"

    return 0;
}
```

이와 같이 공식이 있다.

    n * (n+1) / 2

그러면, 초항이 3이고 등차가 5인 등차수열의 합은?

    Sn = n(a+l) / 2

    n은 몇 번째 항까지인지, a는 초항, l은 마지막 항의 값이다.

```c++
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 5, a = 3, l = 23;

    cout << n * (a+l) / 2 << "\n";

    return 0;
}
```

# 등비수열의 합

    a = 초항, r는 공비, n은 더하는 것의 개수

    1. a * (r의 n승 - 1) / (r - 1)
    2. a / (1 - r)

```c++
int main() {
    int a = 1, r = 2, n = 4;
    vector<int> v;
    cout << a * ((int)pow(2, n) - 1) / (r - 1); // 15
    cout << "\n";

    for(int i=0; i<n; i++) {
        v.push_back(a);
        a *= r;
    }
    for(int i : v) cout << i << " "; // 1 2 4 8
    cout << "\n";

    return 0;
}
```

# 수학 공식

> int 형을 사용하고 싶다면, 반드시 (int)로 형변환을 해줘야 한다.

### 제곱

    pow(double base, double exponent)

### 제곱근

    sqrt(double num)
