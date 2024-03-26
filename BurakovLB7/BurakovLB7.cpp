#include <iostream>
#include <map>
#define MAX 50
#define MAXLINE 500

template <typename T>
class Stack {
  public:

      void push(const T n) {
          top++;
          arr[top] = n;
      }

      T& pop() {
          top--;
          return arr[top + 1];
      }

      int size() const {
          return top + 1;
      }

  private:
    T arr[MAX];
    int top = -1;
};

void OrderRPN(char c) {

}

void input() {
    char chr[MAXLINE];
    char c;
    std::cin.getline(chr, MAXLINE);
    int i = 0;
    int sz = std::strlen(chr);
    while ( i < sz ) {
        c = chr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^') {
            OrderRPN(c);
        } 
        else if (static_cast<int>(c) <= 57 && static_cast<int>(c) >= 48) {
            std::cout << c;
            if (i < sz - 1) {
                while (static_cast<int>(chr[i + 1]) <= 57 && static_cast<int>(chr[i + 1]) >= 48) {
                    std::cout << chr[i + 1];
                    i++;
                }
            }
            std::cout << ' ';
        }
        i++;
    }
   
}

int main()
{
    std::map<char, int> prioryty = { {')', 0}, {'(', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'^',4}};

    Stack<char> a;
    
    input();
    
}
