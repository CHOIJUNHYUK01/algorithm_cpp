# 배열 수정하기

### 요소 수정하기

> 크기를 정하지 않은 "int a[]" 또는 배열의 크기를 정한 "int a[3]", 배열의 포인터인 "int \* a"를 넘겨 수정이 가능하다.

```c++
int a[3] = {1,2,3};

void go(int a[]){
    a[2] = 100;
}

void go2(int a[3]) {
    a[2] = 1000;
}

void go3(int *a) {
    a[2] = 10000;
}

int main() {
    go(a); cout << a[2] << "\n"; // 100
    go2(a); cout << a[2] << "\n"; // 1000
    go3(a); cout << a[2] << "\n"; // 10000
    return 0;
}
```

### 2차원 배열 수정하기

### vector

```c++
vector<vector<int>> v;
vector<vector<int>> v2(10, vector<int>(10, 0));
vector<int> v3[10];

void go(vector<vector<int>> &v) {
    v[0][0] = 100;
}
void go2(vector<vector<int>> &v) {
    v[0][0] = 100;
}
void go3(vector<int> v[10]) {
    v[0][0] = 100;
}

int main() {
    vector<int> temp;
    temp.push_back(0);
    v.push_back(temp);

    v3[0].push_back(0);

    go(v); go2(v2); go3(v3);
    cout << v[0][0] << " : " << v2[0][0] << " : " << v3[0][0] << "\n";

    return 0;
}
```

### array

```c++
int a[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
void go(int a[][3]) {
    a[2][2] = 100;
}
void go2(int a[3][3]) {
    a[2][2] = 1000;
}

int main() {
    go(a); cout << a[2][2] << "\n"; // 100
    go2(a); cout << a[2][2] << "\n"; // 1000
    return 0;
}
```
