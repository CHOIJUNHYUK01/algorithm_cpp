# 정수록

### 최대공약수

```c++
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
```

### 최소공배수

> (a \* b) / (a와 b의 최대공약수)

```c++
int lcm(int a, int b) {
    return (a * b) / gcd(a,b);
}
int main() {
    int a = 10, b = 12;
    cout << lcm(a,b) << "\n";
    return 0;
}
```
