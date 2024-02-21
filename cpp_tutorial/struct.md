# struct

> 구조체라 불린다. 이는 c++에서 제공하는 게 아니라 개발자가 커스텀한 자료 구조다. 커스텀하게 정렬을 추가하고 싶거나 문제에서 여러 변수가 들어간다면 이를 사용해야 한다.

예를 들어 int 타입 2개, double 타입 3개가 필요한 때 사용한다.

```c++
struct Ralo {
    int a, b;
    double c, d, e;
};

void print(Ralo ralo) {
    cout << ralo.a << " : " << ralo.b <<  " : " << ralo.c << " : " << ralo.d << " : " << ralo.e << "\n";
}

int main() {
    Ralo ralo = {1, 1, 1, 1, 1};
    print(ralo); // 1,1,1,1,1

    vector<Ralo> ret;
    ret.push_back({1,2,3,4,5});
    ret.push_back({1,2,3,4,6});
    ret.push_back({});
    ret.push_back({1,3});

    for(Ralo ralo : ret) {
        print(ralo); // 1 2 3 4 5
                     // 1 2 3 4 6
                     // 0 0 0 0 0
                     // 1 3 0 0 0
    }

    return 0;
}
```

### Point 구조체 정의하기

> 구조체를 기반으로 정렬하는 연산, 초기값 설정이 필요하다면 다음 예시와 같이 하면 된다.

```c++
struct Point {
    int y, x; // 구조체의 멤버변수

    Point(int y, int x) : y(y), x(x) {} // y, x를 받아 멤버변수를 생성한다.
    Point(){y = -1; x = -1} // 빈 값이라면 -1로 초기화한다.

    bool operator < (const Point & a) const { // 연산자 오버로딩이다.
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
}
```

#### 왜 오버로딩인가?

> 연산자 의미를 변경하지 않으며, 오퍼레이터 대상이 바뀌는 것 뿐이다. struct 기반으로 확장하는 것 뿐이기 때문이다.

#### 구조체 기반 sort를 사용할 때 주의점

> 오퍼레이터를 오버로딩 할 때에는 <를 주의해야 한다. sort()가 <를 기준으로 정렬하기 때문이다.

정렬을 할 때, 아스키코드 순으로 비교하기 때문에 "33"이 "111"보다 크다고 인식하기 때문에 사이즈 확인 로직을 넣어햐 한다.

### vector에다 struct넣고 정렬하기

```c++
struct Point{
    int y, x;
};

bool cmp(const Point & a, const Point & b) {
    return a.x > b.x;
}

vector<Point> v;
int main() {
    for(int i=10; i>=1; i--) {
        v.push_back({i, 10 - i});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto it : v) cout << it.y << " : " << it.x << "\n";

    return 0;
}
```
