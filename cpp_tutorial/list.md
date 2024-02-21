# List

> 연결리스트다. 요소가 인접한 메모리 위치에 저장되지 않는 선형 자료구조다. 랜덤 접근은 불가능하고, 순차적 접근만 가능하다. next, prev라는 포인터로 연결되어 이뤄지고, 중복을 허용한다.

데이터를 감싼 노드를 포인터로 연결해, 공간적인 효율성을 극대화시킨 자료구조다.
삽입과 삭제에 O(1)이 걸리며, k 번째 요소를 참조한다 했을 때는 O(k)가 걸린다.

```c++
class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
}
```

### 싱글 연결리스트

> next 포인터밖에 존재하지 않으며, 한 방향으로만 데이터가 연결된다.

### 이중 연결리스트

> prev, next 두 개의 포인터가 존재하고, 양방향으로 데이터가 연결된다.

### 원형 연결리스트

> 마지막 노드와 첫 번째 노드가 연결되어 원을 형성한다. 싱글 연결리스트 또는 이중 연결리스트로 이뤄진 2가지 타입의 원형 연결리스트가 있다.

```c++
list<int> a;

void print(list <int> a) {
    for(auto it : a) cout << it << " ";
    cout << "\n";
}

int main() {
    for(int i=1; i<=3; i++) a.push_back(i);
    for(int i=1; i<=3; i++) a.push_front(i);

    auto it = a.begin(); it++;
    a.insert(it, 1000);
    print(a);

    it = a.begin(); it++;
    a.erase(it);
    print(a);

    a.pop_front();
    a.pop_back();
    print(a);

    cout << a.front() << " : " << a.back() << "\n";
    a.clear();

    return 0;
}
```

### push_front(value)

> 리스트 앞에서부터 value를 넣는다.

### push_back(value)

> 뒤에서부터 value를 넣는다.

### insert(idx, value)

    iterator insert (const_iterator position, const value_type& val);

요소를 position에 삽입한다.

### erase(idx)

    iterator erase (const_iterator position)

리스트의 position 번째 요소를 지운다.

### pop_front()

> 첫 번째 요소를 지운다.

### pop_back()

> 맨 끝 요소를 지운다.

### front()

> 맨 앞 요소를 참조한다.

### back()

> 맨 끝 요소를 참조한다.

### clear()

> 모든 요소를 지운다.

## 배열과 연결리스트 차이

| 키워드         | 배열                      | 연결리스트                       |
| -------------- | ------------------------- | -------------------------------- |
| 메모리 공간    | 연속된 메모리 공간에 저장 | 연속되지 않은 메모리 공간에 저장 |
| 삽입 삭제 시간 | O(n)                      | O(1)                             |
| 참조 시간      | O(1)                      | O(n)                             |
| 추천           | 참조를 많이 하는 것       | 데이터 추가와 삭제가 잦은 것     |
