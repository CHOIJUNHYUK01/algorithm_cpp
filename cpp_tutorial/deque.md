# deque

> queue가 앞에서만 요소를 끄집어낼 수 있다면, 이건 앞뒤로 삽입, 삭제, 참조가 가능한 자료 구조다.

```c++
int main() {
    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << dq.front() << "\n"; // 1
    cout << dq.back() << "\n"; // 3
    cout << dq.size() << "\n"; // 3

    dq.pop_back();
    dq.pop_front();

    cout << dq.size() << "\n"; // 1

    return 0;
}
```
