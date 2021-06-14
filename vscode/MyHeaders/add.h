#pragma once

// 전처리기
// MY_ADD가 이미 정의 되어있으면 MY_ADD를 include하지 마라(정의 하지 마라) 
// => #pragma once로 한번에 구현 가능
// #ifndef MY_ADD

// #define My_ADD

int add(int a, int b)
{
    return a + b;
}

// #endif