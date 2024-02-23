# 코딩테스트 필수로직

> 자주 나오며, 꼭 알아야 함

### 1차원 배열 회전

> 배열을 시계 방향, 반시계 방향으로 회전해야 할 때 사용한다.

`{1,2,3,4,5,6}`에서
시계방향으로 한 번 돌리면 `{6,1,2,3,4,5}`
반시계방향으로 한 번 돌리면 `{2,3,4,5,6,1}`이 된다.

이걸 해주는 게 `rotate()` 함수다.

    ForwardIterator rotate (ForwardIterator first, ForwardIterator middle, ForwardIterator last)

middle에는 몇 칸을 움직일지 표현한다.

```c++
// 반시계방향 구축
vector<int> v;
int main() {
    vector<int> v = {1,2,3,4,5,6};
    rotate(v.begin(), v.begin() + 2, v.end()); // 2칸을 반시계로 돌린다.
    for(int i : v) cout << i << "\n"; // 3 4 5 6 1 2

    return 0;
}

// 시계방향 구축
int main() {
    vector<int> v = {1,2,3,4,5,6};
    rotate(v.rbegin(), v.rbegin() + 1, v.rend()); // 1칸을 시계로 돌린다.
    for(int i : v) cout << i << "\n"; // 6 1 2 3 4 5
    return 0;
}
```

`rbegin()`
배열의 마지막 번째를 나타내는 이터레이터다.

`rend()`
오른쪽부터 시작해, 배열의 시작 전의 위치를 나타낸다.

### 직접 구현한다면

1번에서 4번까지 반시계로 한 칸 돌렸을 때를 나타낸다.

```c++
int main() {
    vector<int> v = {1,2,3,4,5,6};
    int i = 1;
    int temp = v[i];

    v[i] = v[i+1];
    v[i+1] = v[i+2];
    v[i+2] = v[i+3];
    v[i+3] = temp;

    for(int i : v) cout << i << "\n"; // 1 3 4 5 2 6

    return 0;
}
```

### 2차원 배열 회전

아래는 가로세로 크기가 다른 배열일 때의 코드다.
같다면 `Resize()`코드가 빠지기 때문에 더 단순해진다.

```c++
const int n = 3;
const int m = 4;

void rotate_left_90(vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            temp[i][j] = key[j][m - i - 1];
        }
    }

    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

void rotate_right_90(vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            temp[i][j] = key[n - j - 1][i];
        }
    }

    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<vector<int>> a = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10, 11, 12},
    };
    rotate_right_90(a);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

### 2차원 배열 대칭

    123     147
    456  -> 258
    789     369

```c++
vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7,8,9}};
int b[3][3];

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            b[j][i] = v[i][j];
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

### n진법 변환

> 어떤 숫자 n에서 b진법으로 바꾸는 법

아래는 10진법을 2진법으로 바꾸는 코드다.
`b`를 b진법이라고 보면 된다. 숫자를 바꾸면 된다.

```c++
vector<int> v;

int main() {
    int n = 100;
    int b = 2;

    while(n > 1) {
        v.push_back(n % b);
        n /= b;
    }

    if(n == 1) v.push_back(1);
    reverse(v.begin(), v.end());

    for(int a : v) {
        if(a >= 10) cout << char(a + 55); // 이건 16진법을 위한 것임
        else cout << a;
    }
    return 0;

    return 0;
}
```
