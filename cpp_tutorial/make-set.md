# 조합

> 순서는 없다. 그저 몇 명을 뽑아서 갈 것인가를 쓸 때 조합을 쓴다. 오로지 몇 명을 다양하게 뽑을 때 사용한다.

### 공식

    nCr = n! / r!(n-r)!

```c++
int n = 5, k = 3, a[5] = {1,2,3,4,5};
void print(vector<int> b) {
    for(int i : b) cout << i << " ";
    cout << "\n";
}

void combi(int start, vector<int> b) {
    if(b.size() == k) {
        print(b);
        return;
    }

    for(int i=start+1; i<n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    vector<int> b;
    combi(-1, b);
    return 0;
}
```

for 문으로도 가능하다.

```c++
int n = 5, k = 3, a[5] = {1,2,3,4,5};

int main() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k = j+1; k<n; k++) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }

    return 0;
}
```

### 조합의 특징

    nCr = nC(n-r)

9개 중에 7개를 뽑는 거나, 2개를 뽑는 거나 동일하다.
7개를 뽑으면 나머지 2개가 자동으로 나오기 때문이다.
