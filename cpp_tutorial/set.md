# set

> 고유한 요소만을 저장하는 컨테이너다. 중복을 허용하지 않는다. pair 또는 int 형을 집어넣어 만들 수도 있다. 자동정렬 된다.

```c++
int main() {
    set<pair<string, int>> st;

    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});

    cout << st.size() << "\n"; // 1

    set<int> st2;

    st2.insert(2);
    st2.insert(1);
    st2.insert(2);
    for(auto it : st2) {
        cout << it << "\n"; // 1,2
    }

    return 0;
}
```

### set과 unique 중 어떤 걸 써야 할까?

> 둘 다 가능하다.

`set을 사용할 경우`

1. 중복된 배열인 vector 생성
2. set 사용해서 중복제거
3. 다시 새 vector를 만들어 set 요소 집어넣음

`unique와 erase를 사용할 경우`
해당 중복된 배열 vector를 기반으로 사용해도 된다.
이 경우가 더 좋다.
