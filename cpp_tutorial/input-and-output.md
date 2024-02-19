# 입력과 출력

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
