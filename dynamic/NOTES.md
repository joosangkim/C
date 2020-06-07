## Functions
* Forward declartion -> 전방선언 
### 매개변수 평가순서 
* 표준 -> 함수 매개변수의 평가순서는 명시되지 않음(Unspecified)
* 따라서 컴파일러에 따라 매개변수의 평가순서가 달라진다. 
* 함수호출 -> **sequence point**
* 한 시퀸스에서 한 변수를 여러변 변경하지 말자 
# fgets -> 개행문자제거
```c
fgets(str, WORD_LEN, stdin);
str[strlen(str)-1] = '\0';
```

## Scope
### Translation unit 
* Preprocessing -> Translation unit
```clang -std=c89 -W -Wall -pedantic-errors -E main.c```
* Compiler -> Assemble code
```clang -std=c89 -W -Wall -pedantic-errors -S main.c```
* Assembler -> Object code
```clang -std=c89 -W -Wall -pedantic-errors -c main.c```
