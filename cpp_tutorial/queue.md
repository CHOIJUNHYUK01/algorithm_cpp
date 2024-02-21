# queue

> 먼저 집어넣은 데이터가 먼저 나오는 FIFO 특성을 지닌 자료 구조다. 스택과는 반대된다.

삽입과 삭제에는 O(1)
탐색에는 O(n)

```c++
queue<int> q;
int main() {
    for(int i=1; i<=10; i++) q.push(i);

    while(q.size()) {
        cout << q.front() << '\n'; // 1,2,3,4,5,6,7,8,9,10
        q.pop();
    }

    return 0;
}
```

### push(value)

> value를 큐에 추가한다.

### pop()

> 가장 앞에 있는 요소를 제거한다.

### size()

> 큐의 크기를 반환한다.

### front()

> 가장 앞에 있는 요소를 참조한다.
