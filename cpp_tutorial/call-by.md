# 값에 의한 호출과 참조에 의한 호출

> 함수에 값을 전달할 때, 값에 의한 호출과 참조에 의한 호출이 있다.

### 매개변수 (Parameter)

> 함수에 전달되는 값이자, 함수 괄호 안에 선언된 값을 말한다.

```c++
int add(int n1, int n2) {
    return n1 + n2;
}
```

### 값에 의한 호출 (call by value)

> 매개변수로 전달되는 변수를 모두 함수 내부에서 복사해 함수를 실행하는 방법이다.

함수 내부에서 전체 복사가 일어나, 실제 변수와는 다른 주소에 할당된다.
그래서 실제 변수와 매개변수로 전달된 변수는 다른 주솟값을 가진다.

즉, 함수 내부에서 이 복사본이 변경되더라도 원본값은 변하지 않는다.

```c++
int add(int a, int b) {
    a += 10;
    cout << a << "\n"; // 11
    return a + b;
}

int main() {
    int a = 1;
    int b = 2;
    int sum = add(a,b);
    cout << a << "\n"; // 1
    return 0;
}
```

이는 vector를 넘겨 수정하더라도 동일하다.

```c++
vector<int> v(3, 0);

void go(vector<int> v) {
    v[1] = 100;
}

int main() {
    go(v);
    for(int i : v) cout << i << "\n"; // 0 0 0
    return 0;
}
```

### 참조에 의한 호출 (call by reference)

> "변수의 주소"를 매개 변수로 함수에 전달하는 방법이다.

함수 내부에서 해당 매개 변수를 변경하면, 원본 변수에도 반영이 된다.

```c++
int add(int &a, int b) {
    a += 10;
    cout << a << "\n"; // 11
    return a + b;
}

int main() {
    int a = 1;
    int b = 2;
    int sum = add(a,b);
    cout << a << "\n"; // 11
    return 0;
}
```

`vector`도 동일하다.

```c++
vector<int> v(3, 0);

void go(vector<int> &v) {
    v[1] = 100;
}

int main() {
    go(v);
    for(int i : v) cout << i << "\n"; // 0 100 0
    return 0;
}
```

### 참조에 의한 호출로 넘거야 할 때

> 원시 타입이면 "값에 의한 호출"로 넘기는 게 좋다. 복사가 일어나지만, 간단하기 때문에 복사에 대한 코스트가 크지 않기 때문이다. 오히려 함수 내부에서 직접 참조할 수 있기 때문에 더 빠르다.

하지만 복잡한 `struct`나 많은 요소를 가진 배열을, 배열이 차지하는 메모리가 많을 수록 참조로써 매개 변수를 넘기는 게 좋다.
참조없이 전달하게 될 경우, 전체 복사를 해야 하는데 코스트가 크기 때문이다.

#### 여기서 코스트란?

> 해당 복사에 드는 CPU 시간, 메모리를 말한다.

#### 원시 타입

> byte, short, int, long, float, double, boolean, char

#### 참조 타입

> String, struct, class, int[], string[] 등
