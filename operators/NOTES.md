# Operator 

## Macro
* 반복되는 값 혹은 프로그램 전체에서 사용되는 상수의 경우 **매크로** 로 지정할 수 있다. 
```
#define MACRO_NAME value
``` 
* 만약 Macro 로 지정한 값을 해제하고 싶다면, `#undef`키워드로 해제 할 수 있으며, 해제한 이후 Macro 값을 사용하고자 하면 컴파일 에러가 발생한다. 
```
#define MACRO_NAME value
...
#undef MACRO_NAME
``` 
