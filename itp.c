#include <stdio.h>
#include <stdlib.h>
 #include <string.h>

 int prec(char c)
 {
 if (c == '^')
 return 3;
 else if (c == '/' || c == '*')
 return 2;
 else if (c == '+' || c == '-')
 return 1;
 else
 return -1;
 }

 void infixToPostfix(char* s)
 {
 char* result = (char*)malloc(strlen(s) * sizeof(char));
 int resultIndex = 0;
  int sLength = strlen(s);
 char* stack = (char*)malloc(sLength * sizeof(char));
 int stackIndex = 0;

 for (int i = 0; i < sLength; i++) {
 char c = s[i];

 if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
 || (c >= '0' && c <= '9')) {
 result[resultIndex++] = c;
 }

 else if (c == '(') {
 stack[stackIndex++] = '(';
 }

 else if (c == ')') {
 while (stackIndex > 0 && stack[stackIndex - 1] != '(') {
 result[resultIndex++] = stack[--stackIndex];
}
 stackIndex--;
 }

 else {
 while (stackIndex > 0
 && prec(s[i]) <= prec(stack[stackIndex - 1])) {
 result[resultIndex++] = stack[--stackIndex];
}
 stack[stackIndex++] = c;
 }
 }

 while (stackIndex > 0) {
 result[resultIndex++] = stack[--stackIndex];
}

// Data structure (3130702) 220170116004


result[resultIndex] = '\0';

 printf("%s\n", result);

 free(result);
 free(stack);
 }

 int main()
 {
 char s[100];
 printf("Enter an infix expression: ");
 scanf("%s", s);

 infixToPostfix(s);

 return 0;
 }