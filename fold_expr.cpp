#include <climits>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

/*
折叠表达式的实例化按如下方式展开成表达式 e ：
1) 一元右折叠 (E op ...) 成为 (E1 op (... op (E.N-1 op E.N)))
2) 一元左折叠 (... op E) 成为 (((E1 op E2) op ...) op E.N)
3) 二元右折叠 (E op ... op I) 成为 (E1 op (... op (E.N−1 op (E.N op I))))
4) 二元左折叠 (I op ... op E) 成为 ((((I op E1) op E2) op ...) op E.N)
（其中 N 是包展开中的元素数）
*/

template <typename T>
void op(const T& arg)
{
  std::cout << arg << '\n';
}

template <typename... Args>
void print(Args&&... args)
{
  (std::cout << ... << args) << '\n';
  (op(args), ...);
}

template <class T, class... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
  (v.push_back(args), ...);
}

int main()
{
  print(1, 2, 3, "abc");
  std::vector<int> v;
  push_back_vec(v, 6, 2, 45, 12);
  for (auto it : v) {
    std::cout << it << '\t';
  }

  return 0;
}