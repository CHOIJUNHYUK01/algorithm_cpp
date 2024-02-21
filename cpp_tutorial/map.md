# Map

> 고유한 키를 기반으로 키 - 값을 한 쌍으로 이뤄진 정렬된 연관 컨테이너다. 레드 - 블랙트리로 구현된다. 이 때문에 삽입, 삭제, 수정, 탐색이 O(logN)이다.

고유한 키를 갖기에, 하나의 키에 중복된 값이 들어갈 수 없다.
자동으로 오름차순 정렬이 되기 때문에 넣은 순서대로 map을 탐색할 수 있지 않고, 아스키코드 순으로 정렬된다.
또한 대괄호 연산자로 해당 키로 직접 참조가 가능하다.

#### 레드블랙트리는 균형 이진 검색 트리다.

```c++
map<string, int> mp;
string a[] = {"페른", "제리에", "프리렌"};
int main() {
    for(int i=0; i<3; i++) {
        mp.insert({a[i], i+1});
        mp[a[i]] = i + 1;
    }
    // mp에 해당 키가 없다면 0으로 초기화됨 (Int 라면)
    // 만약 mp에 해당키가 없는지 확인하고 싶고, 초기값이 0이 되면 안된다 하는 상황이라면
    // find를 써야 한다.

    cout << mp["friren"] << "\n"; // 0

    mp["friren"] = 4;
    cout << mp.size() << "\n"; // 4
    mp.erase("friren");

    auto it = mp.find("friren");
    if(it == mp.end()) {
        cout << "없는 마법사임";
    }
    mp["friren"] = 100;

    it = mp.find("friren");
    if(it != mp.end()) {
        cout << (*it).first << " : " << (*it).second << "\n";
    }

    for(auto it : mp) {
        cout << (it).first << " : " << (it).second << "\n";
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " : " << (*it).second << "\n";
    }

    mp.clear();

    return 0;
}
```

### insert({key, value})

> map에다 {Key, value}를 집어 넣는다.

### [key] = value

> 대괄호를 통해 key에 해당하는 value를 할당한다.

### [key]

> 대괄호를 통해 key를 기반으로 map에 있는 요소를 참조한다.

### size()

> map에 있는 요소 개수를 반환한다.

### erase(key);

> 해당 키에 해당하는 요소를 지운다.

### find(key)

> map에서 해당 key를 가진 요소를 찾아 반환한다. 못찾았다면, map의 end() 값을 반환한다.

### for(auto it : mp)

> 범위기반 for루프로 map에 있는 요소를 순회한다. 순회할 때는 key는 first, value는 second로 참조한다.

### for(auto it = mp.begin(); it != mp.end(); it++)

> map에 있는 요소를 순회할 수 있다.

### mp.clear();

> map에 있는 요소를 다 제거한다.

### 맵을 쓸 때 주의할 점

> 해당 인덱스에 참조만 해도 맵의 요소가 생긴다. int라면 0으로, char나 string이라면 빈 문자열로 할당된다.

이게 싫다면 `find()`를 쓸 것
