# pragma once

// namespace를 이용해서 const 값을 재사용 가능
// 여러번 반복되어 사용되는 상수들을 한 곳에 모아놓고 사용하는 것이 좋음
namespace constants
{
    extern const double pi;
    extern const double avogadro;
    extern const double moon_gravity;
    // ...
}