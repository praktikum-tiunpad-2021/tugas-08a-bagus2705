/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 */

#include <iostream>

#include "queue.hpp"

using namespace strukdat::priority_queue;

int main()
{
    auto q = new_queue<int>();
    enqueue(q, 1, 5);
  std::cout<<top(q);
  enqueue(q, 2, 3);
  std::cout<<top(q);
 enqueue(q, 4, 7);
  dequeue(q);
  std::cout<<top(q);
}
