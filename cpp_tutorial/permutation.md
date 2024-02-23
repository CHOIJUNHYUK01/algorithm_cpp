# 순열

> 순서가 정해진 임의의 집합을 다른 순서로 섞는 연산이다.

    1,2,3 -> 1,3,2

이런식으로 다른 순서로 섞는 연산을 순열이라고 한다.
n개의 집합 중 n개를 고르는 순열의 개수는 `n!`이다.

만약 `n개 중`에서 `r개를 뽑는 거다`라고 한다면,
`nPr = n! / (n-r)!`이다.

결국 순서와 관련있게 뽑는 것이다.

### next_permutation, prev_permutation

#### next_permutation

> 오름차순 배열을 기반으로 순열을 만든다.

#### prev_permutation

> 내림차순 배열을 기반으로 순열을 만든다.

```c++
void printV(vector<int> &v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    int a[3] = {1,2,3};
    vector<int> v;

    for(int i=0; i<3; i++) v.push_back(a[i]);

    do {
        printV(v);
    } while(next_permutation(v.begin(), v.end()));

    cout << "----------" << "\n";
    v.clear();

    for(int i=3; i>=1; i--) v.push_back(i);

    do {
        printV(v);
    } while(prev_permutation(v.begin(), v.end()));

    return 0;
}
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
// ----------
// 3 2 1
// 3 1 2
// 2 3 1
// 2 1 3
// 1 3 2
// 1 2 3
```

#### 주의사항이 있다.

`next_permutation`을 사용하려면, 오름차순으로 정렬된 배열이어야 한다.
`prev_permutation`도 마찬가지로 내림차순으로 정렬된 배열이어야 한다.

정렬되지 않았다면, 해당 배열의 그 다음 번째 순열을 만들어 내기 때문에, 정확한 답을 얻을 수 없다.

### 재귀를 활용한 순열

```c++
int a[3] = {1,2,3};
int n = 3, r = 3;

void print() {
    for(int i=0; i<r; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void makePermutation(int n, int r, int depth) {
    if(r == depth) {
        print();
        return;
    }

    for(int i=depth; i<n; i++) {
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        swap(a[i], a[depth]);
    }
    return;
}

int main() {
    makePermutation(n, r, 0);
    return 0;
}
```
