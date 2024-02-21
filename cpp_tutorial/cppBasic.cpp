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
// typedef long long ll;
// double a = 1.23456789;
// int main() {
//     cout << a << "\n";
//     cout.precision(4);
//     cout << a << "\n";
//     return 0;
// }

/**
 * 주소 출력
*/

// int i;

// int main() {
//     cout << &i << "\n";
//     i = 10;
//     cout << &i << "\n";
//     return 0;
// }

/**
 * 이터레이터
*/
// vector<int> v;
// 
// int main() {
//     for(int i=1; i<=5; i++) v.push_back(i);
//     for(int i=0; i<5; i++) {
//         cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";
//         cout << &*(v.begin() + i) << "\n";
//     }

//     for(auto it = v.begin(); it != v.end(); it++) {
//         cout << *it << "\n";
//     }

//     for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//         cout << *it << " : " << "\n";
//     }

//     auto it = v.begin();
//     advance(it, 3);
//     cout << "\n";
//     cout << *it << "\n";

//     return 0;
// }

/**
 * fill()
*/
// int a[10];
// int b[10][10];
// int main() {
//     fill(&a[0], &a[10], 100);

//     for(int i=0; i<10; i++) {
//         cout << a[i] << "\n";
//     }

//     cout << "\n";

//     fill(&b[0][0], &b[9][10], 2);
//     for(int i=0; i<10; i++) {
//         for(int j=0; j<10; j++) {
//             cout << b[i][j] << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }

/**
 * 초기화 주의하기
*/
// int main() {
//     int cnt = 0;
//     int a[5] = {0, };
//     while(++cnt != 10) {
//         for(int i=0; i<5; i++) a[i] = i;
//         a[5] = {0, };
//         for(int i : a) cout << i << ' ';
//         cnt++;
//     }
//     return 0;
// }

/**
 * 커스텀 정렬함수
*/
// vector<pair<int, int>> v;

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     return a.first < b.first;
// }

// int main() {
//     for(int i=10; i>=1; i--) {
//         v.push_back({i, 10-i});
//     }
//     sort(v.begin(), v.end(), cmp);
//     for(auto it : v) cout << it.first << " : " << it.second << "\n";

//     return 0;
// }

/**
 * 최대 요소
*/
// int main() {
//     vector<int> v = {1,2,3,4,5,6,7,8,9};

//     int a = *max_element(v.begin(), v.end());
//     auto b = max_element(v.begin(), v.end());

//     cout << a << "\n"; // 9
//     cout << (int)(b - v.begin()) << "\n"; // 8

//     return 0;
// }

/**
 * for 루프
*/
// vector<int> v {1,2,3};
// int main() {
//     for(int a : v) cout << a << " ";
//     cout << "\n";

//     for(int i=0; i<v.size(); i++) cout << v[i] << ' ';
//     cout << "\n";

//     vector<pair<int, int>> v2 = {{1,2}, {3,4}};
//     for(pair<int, int> a : v2) cout << a.first << " ";

//     return 0;
// }

/**
 * 2차원 배열
*/
// vector<vector<int>> v;
// vector<vector<int>> v2(10, vector<int>(10, 0));
// vector<int> v3[10];

// int main() {
//     for(int i = 0; i < 10; i++) {
//         vector<int> temp;
//         v.push_back(temp);
//     }

//     return 0;
// }

/**
 * 연결리스트
*/
// list<int> a;

// void print(list <int> a) {
//     for(auto it : a) cout << it << " ";
//     cout << "\n";
// }

// int main() {
//     for(int i=1; i<=3; i++) a.push_back(i);
//     for(int i=1; i<=3; i++) a.push_front(i);

//     auto it = a.begin(); it++;
//     a.insert(it, 1000);
//     print(a);

//     it = a.begin(); it++;
//     a.erase(it);
//     print(a);

//     a.pop_front();
//     a.pop_back();
//     print(a);

//     cout << a.front() << " : " << a.back() << "\n";
//     a.clear();

//     return 0;
// }

/**
 * 맵 탐색
*/
// map<string, int> mp;
// string a[] = {"페른", "제리에", "프리렌"};
// int main() {
//     for(int i=0; i<3; i++) {
//         mp.insert({a[i], i+1});
//         mp[a[i]] = i + 1;
//     }
//     // mp에 해당 키가 없다면 0으로 초기화됨 (Int 라면)
//     // 만약 mp에 해당키가 없는지 확인하고 싶고, 초기값이 0이 되면 안된다 하는 상황이라면
//     // find를 써야 한다.

//     cout << mp["friren"] << "\n"; // 0

//     mp["friren"] = 4;
//     cout << mp.size() << "\n"; // 4
//     mp.erase("friren");

//     auto it = mp.find("friren");
//     if(it == mp.end()) {
//         cout << "없는 마법사임" << "\n";
//     }
//     mp["friren"] = 100;

//     it = mp.find("friren");
//     if(it != mp.end()) {
//         cout << (*it).first << " : " << (*it).second << "\n";
//     }

//     for(auto it : mp) {
//         cout << (it).first << " : " << (it).second << "\n";
//     }
//     for(auto it = mp.begin(); it != mp.end(); it++) {
//         cout << (*it).first << " : " << (*it).second << "\n";
//     }

//     mp.clear();

//     return 0;
// }

/**
 * Struct
*/
// struct Point{
//     int y, x;
// };

// bool cmp(const Point & a, const Point & b) {
//     return a.x > b.x;
// }

// vector<Point> v;
// int main() {
//     for(int i=10; i>=1; i--) {
//         v.push_back({i, 10 - i});
//     }

//     sort(v.begin(), v.end(), cmp);

//     for(auto it : v) cout << it.y << " : " << it.x << "\n";

//     return 0;
// }

/**
 * 우선순위 큐
*/
// priority_queue<int, vector<int>, greater<int> > pq; // 오름차순
// priority_queue<int> pq2; //내림차순
// priority_queue<int, vector<int>, less<int> > pq3; // 내림차순

// int main() {
//     for(int i=5; i>=1; i--) {
//         pq.push(i); pq2.push(i); pq3.push(i);
//     }

//     while(pq.size()) {
//         cout << pq.top() << " : "<< pq2.top() << " : " << pq3.top() << "\n";
//         pq.pop(); pq2.pop(); pq3.pop();
//     }

//     return 0;
// }

struct Point {
    int y, x;

    Point(int y, int x) : y(y), x(x) {}
    Point() { y = -1; x = -1; }

    bool operator < (const Point & a) const{
        return x < a.x;
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

    cout << pq.top().x << "\n";

    return 0;
}