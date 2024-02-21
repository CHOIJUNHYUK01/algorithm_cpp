# Array

> 정적배열이다. 보통 크기를 설정해 연산을 진행한다. 연속된 메모리 공간에 위치한 같은 타입의 요소 모음이다. 중복 허용한다.

### 2차원 배열 탐색을 빠르게 하는 법

> 단순하게 차원을 늘려서 만들면 된다.

```c++
const int mxy = 3;
const int mxx = 4;
int a[mxy][mxx];

int main() {
    for(int i=0; i<mxy; i++) {
        for(int j=0; j<mxx; j++) {
            a[i][j] = i + j;
        }
    }

    // Good
    for(int i=0; i<mxy; i++) {
        for(int j=0; j<mxx; j++) {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }

    // Bad
    for(int i=0; i<mxy; i++) {
        for(int j=0; j<mxx; j++) {
            cout << a[j][i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}
```

Good 코드와 Bad 코드 차이점.
첫 번째 차원을, 여기서는 y값 먼저 돌고, 2번 째 차원을 도는 게 좋은 것이다.

캐시 관련 효율성 때문에라도 순서를 지키면 좋다.
c++에서 캐시를 첫 번째 차원을 기준으로 하기 때문이다.
