# multiset

> 중복된 요소도 집어넣을 수 있는 자료구조다. 자동 정렬된다.

```c++
multiset<int> s;
int main() {
    for(int i=5; i>=1; i--) {
        s.insert(i);
        s.insert(i);
    }

    for(int it : s) cout << it << "\n"; // 1,1,2,2,3,3,4,4,5,5

    return 0;
}
```
