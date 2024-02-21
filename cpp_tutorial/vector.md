# Vector

> 동적으로 요소를 할당할 수 있는 동적 배열이다. 컴파일 시점에 사용할 요소 개수를 모른다면 이걸 쓰면 된다.

탐색과 맨 뒤의 요소를 삭제 또는 삽입에 `O(1)`이 걸린다.
그게 아닌 요소에는 `O(n)`이 걸린다.

    vector<타입> 변수명;

### push_back()

> 뒤에서부터 요소를 더한다.

`push_back()`과 `emplace_back()`도 있다. 더 빠르긴 하지만, 시간차이는 별로 나지 않는다.

### pop_back()

> 맨 뒤의 요소를 지운다.

### erase()

    iterator erase (const_iterator position);
    iterator erase (const_iterator first, const_iterator last);

erase로 한 요소만을 지운다면 `erase(위치)`로 쓰지만,
[from, to)로 지우고 싶다면, `erase[from, to)`를 통해 지운다.

### find(from, to, value)

> vector의 메서드가 아닌, STL 함수다.

`[from, to)` 에서 `value`를 찾는다. O(n)이 걸린다.

### clear()

> vector의 모든 요소를 지운다.

### fill(from, to, value)

> value로 값을 할당하고 싶다면, 이를 써서 채운다.

### 범위기반 for 루프

> vector 뿐만 아니라, 순회 가능한 컨테이너인 array, map 등도 사용 가능하다.

```c++
vector<int> v {1,2,3};
int main() {
    for(int a : v) cout << a << " "; // 1,2,3
    cout << "\n";

    for(int i=0; i<v.size(); i++) cout << v[i] << ' '; // 1,2,3
    cout << "\n";

    vector<pair<int, int>> v2 = {{1,2}, {3,4}};
    for(pair<int, int> a : v2) cout << a.first << " "; // 1,3

    return 0;
}
```

### vector의 정적할당

> 무조건 크기가 0인 빈 vector를 만들어 요소를 추가하는 게 아니다. 크기를 정해놓은 수도 있고, 값을 초기화 해놓을 수도 있다.

```c++
vector<int> v(5, 100);
int main() {
    for(int a : v) cout << a << "\n"; // 100, 100, 100, 100,1 00
    return 0;
}
```

### 2차원 배열

```c++
vector<vector<int>> v; // 아래 for문으로 빈배열을 만든다.
vector<vector<int>> v2(10, vector<int>(10, 0)); // { {0,0,0,...}, {0,0,0,...}, ... }
vector<int> v3[10]; // { {}, {}, ... }

int main() {
    for(int i=0; i<10; i++) {
        vector<int> temp;
        v.push_back(temp);
    }

    return 0;
}
```
