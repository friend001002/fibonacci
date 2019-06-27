#include <iostream>

using namespace std;

uint64_t Fibonacci_rec(uint16_t n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return Fibonacci_rec(n - 1) + Fibonacci_rec(n - 2);
  }
}

template<uint16_t n>
uint64_t Fibonacci_templ()
{
  if constexpr (n <= 1)
  {
    return n;
  }
  else
  {
    return Fibonacci_templ<n - 1>() + Fibonacci_templ<n - 2>();
  }
}

uint64_t Fibonacci(uint16_t n)
{
  uint64_t ret { 1 };
  uint64_t old_1 {};
  uint64_t old_2 {};

  if (0 == n)
  {
    return 0;
  }
  else if (1 == n)
  {
    return 1;
  }
  
  old_1 = 0;
  old_2 = 1;

  for (uint16_t i { 2 }; i <= n; ++i)
  {
    ret = old_1 + old_2;
    old_1 = old_2;
    old_2 = ret;
  }

  return ret;
}

int main()
{
  for (uint16_t i {}; i <= 20; ++i)
  {
    cout << Fibonacci(i) << ' ';
  }

  cout << endl;

  for (uint16_t i {}; i <= 20; ++i)
  {
    cout << Fibonacci_rec(i) << ' ';
  }

  cout << endl;

  cout << Fibonacci_templ<20>() << ' ';

  cout << endl;

  cin.get();

  return 0;
}
