# priority queue

> 우선순위 큐다. 각 요소에 어떤 우선 순위가 추가로 부여된 컨테이너다.

### 힙

> 완전 이진 트리로 최소힙, 최대힙이 있다. 삽입, 삭제, 탐색, 수정이 O(logN)이 걸린다.

최대 힙은 루트 노드에 최댓값이 있고,
최소 힙은 루트 노드에 최솟값이 있다.

### int형 우선순위 큐

> greater<타입>을 써서 오름차순, less<타입>을 써서 내림차순으로 바꿀 수 있다. 기본값은 내림차순이다. 메서드는 stack과 같다.

```c++
priority_queue<int, vector<int>, greater<int> > pq; // 오름차순
priority_queue<int> pq2; //내림차순
priority_queue<int, vector<int>, less<int> > pq3; // 내림차순

int main() {
    for(int i=5; i>=1; i--) {
        pq.push(i); pq2.push(i); pq3.push(i);
    }

    while(pq.size()) {
        cout << pq.top() << " : "<< pq2.top() << " : " << pq3.top() << "\n";
        pq.pop(); pq2.pop(); pq3.pop();
    }

    return 0;
}
// 1 : 5 : 5
// 2 : 4 : 4
// 3 : 3 : 3
// 4 : 2 : 2
// 5 : 1 : 1
```

### 구조체를 담은 우선순위 큐

```c++
struct Point {
    int y, x;

    Point(int y, int x) : y(y), x(x) {}
    Point() { y = -1; x = -1 }

    bool operator < (const Point & a) const{
        return x > a.x; // 내림차순
    }
};

priority_queue<Point> pq;

int main() {
    pq.push({1,1});
    pq.push({2,2});
    pq.push({3,3});
    pq.push({4,4});
    pq.push({5,5});
    pq.push({6,6});

    cout << pq.top().x << "\n"; // 1

    return 0;
}
```

내림차순을 했는데 1이 나온다.
거꾸로 바꾸면 오름차순으로 바뀌어 6이 나온다.
이는 우선순위큐에 커스텀 정렬을 넣은 때는 반대로 넣어야 하는 특징 때문이다.
