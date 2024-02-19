# 타입

> void, char, string, bool, int, long long, double, unsigned long long

### void : 리턴하는 값이 없다.

### char : 문자

> 작은 따옴표로 선언해야 하고, 1바이트 크기를 가진다.

### string: 문자열

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
