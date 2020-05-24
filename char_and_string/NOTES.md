# fgets -> 개행문자제거
```c
fgets(str, WORD_LEN, stdin);
str[strlen(str)-1] = '\0';
```