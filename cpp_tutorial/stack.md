# stack

> 가장 마지막으로 들어간 데이터가 가장 첫 번째로 나오는 LIFO 특성을 가진 자료구조다.

재귀함수, 알고리즘에 사용되며 웹 브라우저 방문 기록 등에 쓰인다.

삽입과 삭제에는 O(1)
탐색에는 O(n)

```c++
stack<string> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stk.push("엄")
    stk.push("준")
    stk.push("식")
    stk.push("화")
    stk.push("이")
    stk.push("팅")

    while(stk.size()) {
        cout << stk.top() << "\n"; // 팅 이 화 식 준 엄
        stk.pop();
    }

    return 0;
}
```

문자열 폭발, 아름다운 괄호만들기, 짝찾기 키워드를 기반으로 이뤄진 문제에서 사용한다.
"교차하지 않고" 라는 문장이 나오면 스택을 사용하는 것은 아닐끼? 염두해야 한다.

### push(value)

> 해당 value를 스택에 추가한다.

### pop()

> 가장 마지막에 추가한 요소를 지운다. (가장 위에 있는 요소를 지운다.)

### top()

> 가장 위에 있는 요소를 참조한다.

### size()

> 스택 크기를 반환한다.
