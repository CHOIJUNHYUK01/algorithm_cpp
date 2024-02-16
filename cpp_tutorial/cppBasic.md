# CPP 기본 정보

> 코드로 표현이 불가능한 것은 여기에 정리

### STL

c++ 기본 제공 라이브러리임
자료구조, 함수 등을 제공하는 라이브러리임

`알고리즘`, `컨테이너`, `이터레이터`, `펑터` 이렇게 4가지를 제공해줌

`vector`라는 자료구조를 쓴다던가 `sort()` 함수를 쓸 수 있게 되는 게 다 `STL` 덕분임

#### 알고리즘이 뭔데

> 정렬, 탐색 등에 관한 함수로 이루어져 있음. sort()가 대표적임.

#### 컨테이너는 뭔데

> c++에서 제공하는 자료구조를 의미한다.

`시퀀스 컨테이너`

- 데이터를 단순히 저장해 놓는 자료구조다.
- `array`, `vector`, `deque`, `forward_list`, `list`가 있음.

`연관 컨테이너`

- 자료가 저장됨에 따라 자동정렬되는 자료구조다. 중복키가 가능한 것은 이름에 `multi`가 붙음.
- `set`, `map`, `multiset`, `multimap`이 있음.

`정렬되지 않은 연관 컨테이너`

- 자료가 저장됨에 따라 자동정렬이 되지 않는 자료구조다.
- `unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap`이 있음.

`컨테이너 어댑터`

- 시퀀스 컨테이너를 이용해 만든 자료구조다.
- `stack`, `queue`는 `deque`로 만들어졌고, `priority_queue`는 `vector`로 만들었다.

#### 이터레이터는 뭔데

> 추후 공부 후, 정리할 거

#### 펑터는 뭔데

> 함수 호출 연산자를 오버로드하는 클래스 인스턴스를 말한다. 여기서는 활용하지 않음.

<hr />

### 입력

> cin, scanf가 있음.

#### cin

> 개행문자까지 입력을 받음

#### scanf

> 형식을 지정해서 입력을 받음

int = d
char = c
string = s
double = lf
long long = ld

#### getline

> 개행문자까지 전부 한꺼번에 받기 가능함

cin으로 T개의 getline을 받을지 설정하는 경우도 있음.
그때는 특정 문자열을 기반으로 `버퍼플래시`를 하고 받아야 한다.

cin으로 입력을 받을 때, 개행문자 직전까지 입력을 받게 되고, 이 때문에 중간에 위치한 버퍼에 `\n`이 남아있게 된다.
이를 없애기 위해 `getline(cin, bufferflush)`를 해줘야 한다.

### 출력

> cout과 printf가 있음.

#### printf

string str을 출력할 떄는 `c_str()`함수를 걸어 출력해야 한다.
그 이유는 printf 기반으로 문자열을 출력하려면 string을 `문자열에 대한 포인터 (char *) 타입`으로 바꿔줘야 하기 때문이다.
그래서 보통 `cout`을 사용하는 것이 좋다.

<hr />

### 타입

> void, char, string, bool, int, long long, double, unsigned long long

#### void : 리턴하는 값이 없다.

#### char : 문자

> 작은 따옴표로 선언해야 하고, 1바이트 크기를 가진다.

#### string: 문자열

> char[]로 선언하거나 그냥 string으로 선언해 여러개의 문자모음이자 문자배열인 문자열을 선언할 수 있다.

`+=`

> 메서드는 아니고, 문자열에 문자열을 더할 때 사용한다.

    `push_back()`라는 메서드가 있지만, 이는 문자하나씩밖에 더하지 못하기에 보통 이걸 사용한다.

`begin()`

> 문자열의 첫 번째 요소를 가리키는 이터레이터를 반환한다. 이를 기반으로 \*를 통해 해당 위치 값을 가져올 수 있다.

`end()`

> 문자열 마지막 요소 그 다음을 가리키는 이터레이터를 반환한다.

`size()`

> 문자열 사이즈를 반환한다. O(1).

`insert(위치, 문자열)`

> 특정 위치에 문자열을 삽입한다. O(n).

`erase(위치, 크기)`

> 특정 위치에 크기만큼 문자열을 지운다. O(n)

`pop_back()`

> 문자열 끝을 지운다. O(1)

`find(문자열)`

> 특정 문자열을 찾아 위치를 반환한다. 못 찾게 된다면, string::npos를 반환하고 O(n).

    string::npos는 size_t 타입의 최댓값을 의미한다.

`substr(위치, 크기)`

> 특정 위치에서 크기만큼의 문자열을 추출한다. O(n).

`아스키코드와 문자열`

> 아스키 코드를 통해 숫자로 된 문자를 반환한다.

`reverse()`

> string은 해당 메서드를 지원하지 않는다. 거꾸로 뒤집고 싶다면, STL에서 지원하는 함수 reverse()를 써야 한다.

    void reverse (BidirectionalIterator first, BidirectionalIterator last);
    아무것도 반환하지 않는다. 원본 문자열 자체를 바꿔버린다.

`split()`

> 이 메서드는 존재하지 않기 때문에 직접 구현해야 한다. O(n).

```c++
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    string s = "안녕하세요. 최준혁입니다.", d = " ";
    vector<string> a = split(s, d);
    for(string b : a) cout << b << "\n";
}
```

`atoi(s.c_str())`

> 문자열을 int로 바꿔야 할 상황이 있을 수 있음. 해당 글자가 문자열인지 숫자인지 확인할 경우에 사용한다.

    문자열이 문자라면 0을 반환한다.

<hr />

### 숫자

#### 오버플로

> 타입의 허용범위를 넘어갈 때 발생하는 에러다.

    최대 범위에 1을 더하면 최솟값으로 돌아감

#### 언더플로

> 오버플로와 반대되는 개념이다.

    이또한 최소 범위에 1을 빼면 최댓값으로 돌아감

<hr />

### pair와 tuple

    pair는 first와 second라는 멤버변수를 가지는 클래스다. (두 가지가 최대)

    tuple은 세 가지 이상의 값을 담을 떄 사용함.

```c++
tuple<int, int, int> tl;

tl = make_tuple(1,2,3);
tie(a,b,c) = tl;
```

<hr />

### auto 타입

> 타입 추론해 결정되는 타입이다.

```c++
// 두 개 다 동일함
pair<int, int> it;
auto it;
```
