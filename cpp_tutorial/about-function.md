# 함수

### fill()과 memset()

> 배열을 초기화할 때 사용한다.

#### fill()

> 모든 값으로 초기화가 가능하다. 0, 1, 100 등 모든 숫자로도 가능하다. O(n)의 시간복잡도를 가진다.

##### 왜 fill()로 전체 초기화를 해야할까?

> 순차적으로 1열 요소를 초기화하고, 그 다음 2열, 3열 ... 이런식으로 초기화가 일어난다.

```c++
int a[10];
int b[10][10];
int main() {
    fill(&a[0], &a[10], 100);

    for(int i=0; i<10; i++) {
        cout << a[i] << "\n";
    }

    cout << "\n";

    fill(&b[0][0], &b[9][10], 2);
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

#### memset()

> -1, 0으로만 초기화가 가능하다. 이 함수가 fill() 보다 빠르다. char 형의 하나의 문자(a,b,c, 등...)으로도 가능하다.

#### 쓰지 말아야 할 초기화 방법 {0, }

```c++
int a[5] = {0, };
```

a라는 배열 요소 5개 모두 0으로 초기화하는 의미다.
하지만 이건 초반에 한 번하는 정적 초기화로써만 유요하다.
동적 초기화로 동작하지 않는다.

```c++
int main() {
    int cnt = 0;
    int a[5] = {0, };
    while(++cnt != 10) {
        for(int i=0; i<5; i++) a[i] = i;
        a[5] = {0, };
        for(int i : a) cout << i << " ";
        cnt++;
    }
    return 0;
}
```

### memcpy()와 copy()

> 깊은 복사를 할 경우에 사용한다. Array끼리 복사할 때는 memcpy()를, Array, vector에는 모두 copy()가 쓰인다.

#### 얕은 복사와 깊은 복사

얕은 복사는 메모리 주소값을 복사한 것이라, 복사한 배열을 수정하면 원본 배열이 변경된다.
깊은 복사는 새로운 메모리 공간을 확보해 완전히 해당 배열을 복사한 것이라, 복사한 배열을 수정해도 원본 배열이 변경되지 않는다.

#### memcpy()

> 어떤 변수의 메모리에 있는 값들을 다른 변수의 "특정 메모리값"으로 복사할 때 사용한다.

하지만, 이 함수는 array에만 해당하며 vector는 되지 않는다.
`TriviallyCopyable`인 타입인 데이터만 가능하다.
c++에서는 `is_trivial`함수로 확인할 수 있다.

#### copy()

> memcpy()와 똑같은 동작을 하는 함수다. vector와 Array 모두 쓰일 수 있다.

```c++
// v : 복사당하는 vector
// ret : 복사하는 vector
copy(v.begin(), v.end(), ret.begin()); // ret에 v를 복사한다.
```

### sort()

> 배열 등 컨테이너들의 요소를 정렬하는 함수다. O(nlogn) 시간복잡도를 가진다.

    sort(first, last, *커스텀비교함수)

first는 정렬하고 싶은 배열의 첫 번째 이터레이터를
last는 정렬하고 싶은 배열의 마지막 이터레이터를 넣으면 된다.
또한 [first, last) 라는 범위를 갖는다.
즉, first는 포함하고 last는 포함하지 않는다는 의미다.

#### 커스텀 비교함수

> 세 번째 매개변수이며, 지정하지 않는다면 기본적으로 오름차순이다.

`greater<T>()` : 내림차순
`less<T>()` : 오름차순

커스텀도 가능하다.

```c++
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    for(int i=10; i>=1; i--) {
        v.push_back({i, 10-i});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v) cout << it.first << " : " << it.second << "\n";

    return 0;
}
```

### unique()

> 범위 안에 있는 요소 중 앞에서부터 서로를 비교해가며 중복되는 요소를 제거하는 함수다. O(n)의 시간복잡도를 가진다.

```c++
vector<int> v {1,1,2,2,3,3,5,6,7,8,9};
int main() {
    auto it = unique(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << "\n";
    return 0;
}
// 1,2,3,4,5,6,7,8,7,8,9
```

중복되지 않은 배열을 앞에서부터 채우고, 남는 나머지 배열 요소는 그대로 가진다.
그래서 `sort()`, `erase(unique())` 와 함께 사용한다.

### lower_bound()와 upper_bound()

> 정렬된 배열에서 어떤 값이 나오는 첫 번째 지점 또는 초과하는 지점의 위치를 찾기 위함이다. 꼭 정렬된 배열에 사용해야 원하는 결과가 나온다.

```c++
typedef long long ll;
int main() {
    vector<int> a {1, 2, 3, 3, 3, 4};

    cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 2
    cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 5

    return 0;
}
```

    왜 a.begin()을 빼나요?

처음 배열 위치 주소값을 빼야 제대로 된 3 위치를 알 수 있다.
이를 기반으로 숫자 3이 몇 개 들어가 있는지 확인도 가능하다.

```c++
typedef long long ll;
int main() {
    vector<int> a {1, 2, 3, 3, 3, 4};

    cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3) << "\n";

    return 0;
}
```

    만약 해당 요소가 없으면 뭘 반환하나요?

그 근방지점을 반환한다.
위 코드에서 `5`를 뽑아낸다고 한다면, `가장 근접한 4의 위치`를 반환한다.

### accumulate()

> 배열의 합을 쉽고 빠르게 구해준다.

### max_element()

> 가장 큰 요소를 추출한다. 이를 기반으로 해당 최댓값의 인덱스도 뽑아낼 수 있다.

```c++
int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};

    int a = *max_element(v.begin(), v.end());
    auto b = max_element(v.begin(), v.end());

    cout << a << "\n"; // 9
    cout << (int)(b - v.begin()) << "\n"; // 8

    return -;
}
```

### min_element()

> 가장 작은 요소를 추출한다. max_element()와 동일하게 사용 가능하다.
