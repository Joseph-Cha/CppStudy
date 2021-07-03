# pragma once

// namespace를 이용해서 const 값을 재사용 가능
// 여러번 반복되어 사용되는 상수들을 한 곳에 모아놓고 사용하는 것이 좋음
namespace constants
{
    constexpr double pi(3.141592);
    constexpr double avogadro(6.0221413e23);
    constexpr double moon_gravity(9.8 / 6.0);
    // ...
}