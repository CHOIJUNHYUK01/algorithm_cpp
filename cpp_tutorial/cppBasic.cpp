#include <bits/stdc++.h> // c++의 모든 표준 라이브러리가 포함된 헤더 파일을 include 시킴
using namespace std; // 네임스페이스란, 많은 라이브러리를 불러서 사용하다보면 변수명 중복이 발생할 수 있는데 이를 방지하기 위해 범위를 걸어놓는 것이다.
// cin, cout 등을 사용할 때, 원래는 std라는 네임스페이스를 통해 std::cin 이렇게 호출을 해야 하는데 std를 기본으로 설정해 cin, cout으로 호출할 수 있게 함

/**
 * 출력에 대하여
*/
// string a;
// int main(){
//     cin >> a;
//     cout << a << "\n";
//     return 0;
// }

/**
 * typedef
*/
// typedef int i; // Swift에서 typealias와 동일함
// int main(){
//     i a = 1;
//     cout << a << "\n";
//     return 0;
// }

/**
 * define
*/
// #define PI 3.14159 // 상수
// #define loop(x,n) for(int x = 0; x < n; x++) // 매크로

// int main(){
//     cout << PI << "\n";
//     int sum = 0;
//     loop(i, 10) {
//         sum += i;
//     }
//     cout << sum << "\n";
//     return 0;
// }

/**
 * 입력
*/
// string a;
// int T;
// // int i;
// int main(){
//     // cin >> a;
//     // cout << a << "\n";

//     // scanf("%d", &i);
//     // printf("%d\n", i);

//     // getline(cin, a);
//     // cout << a << "\n";

//     cin >> T;
//     string bufferflush;

//     getline(cin, bufferflush);

//     for(int i=0; i<T; i++) {
//         getline(cin, a);
//         cout << a << "\n";
//     }

//     return 0;
// }

/**
 * 출력
*/
typedef long long ll;
double a = 1.23456789;
int main() {
    cout << a << "\n";
    cout.precision(4);
    cout << a << "\n";
    return 0;
}