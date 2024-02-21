# unordered_map

> map은 정렬이 되지만, 이건 정렬이 불가능하다. 메서드는 map과 동일하다.

| 주제       | map              | unordered_map           |
| ---------- | ---------------- | ----------------------- |
| 정렬       | 가능             | 불가능                  |
| 기반       | 레드블랙트리기반 | 해시테이블기반          |
| 시간복잡도 | O(logN)          | O(1)이지만, 최악엔 O(n) |

```c++
unordered_map<string, int> umap;
int main() {
    umap["bcd"] = 1;
    umap["aaa"] = 1;
    umap["aba"] = 1;

    for(auto it : umap) {
        cout << it.first << " : " << it.second << "\n";
    }

    return 0;
}
```

되도록이면 map을 쓰자.
