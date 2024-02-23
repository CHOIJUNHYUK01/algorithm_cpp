# 재귀함수와 수학

### 재귀함수

    정의 단계에서 자신을 재참조하는 함수다.
    전달되는 상태인 매개 변수가 달라질 뿐, 똑같은 일을 한다.
    큰 문제를 작은 부분 문제로 나눠 풀 때, 사용한다.

예시로 팩토리얼이 있다.

```c++
int fact_rec(int n) {
    if(n == 1 || n == 0) return 1;
    return n * fact_rec(n-1);
}

int n = 5;
int main() {
    cout << fact_rec(n) << "\n"; // 120
    return 0;
}
```

피보나치의 합도 구현할 수 있다.

```c++
int fibo(int n) {
    cout << n << "\n";
    if(n == 0 || n == 1) return n;
    return fibo(n-1) + fibo(n-2);
}

int n = 5;
int main() {
    cout << fibo(n) << "\n";
    return 0;
}
```

#### 주의사항

    종료조건을 넣어야 한다.
    사이클이 있다면, 쓰면 안 된다. f(a)가 f(b)를 부르고, 다시 f(a)를 부르는 경우는 안 된다.
    반복문으로 된다면, 반복문을 쓸 것. 함수호출에는 코스트가 든다.
