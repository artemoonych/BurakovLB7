#include <iostream>
#include <map>
#define MAX 50

template <typename T>
class Stack {
  public:
      void push(const T n) {
          top++;
          arr[top] = n;
      }

      T& pop() {
          if (top >= 0) {
              top--;
              return arr[top + 1];
          }
          else
              throw std::out_of_range("Стек пуст");
      }

      int size() const {
          return top + 1;
      }

  private:
    T arr[MAX];
    int top = -1;
};


int main()
{
    std::map<char, int> prioryty = { {')', 0}, {'(', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^',4}};

    Stack<char> a;
    char c;
    while (std::cin.get(c) && c!='\n') {
        if (c != ' ') {

        }
    }
}
