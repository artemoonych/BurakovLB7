#include <iostream>
#include <map>
#define MAX 50
#define MAXLINE 500

class Stack {
  public:

      void push(const char n) {
          last++;
          arr[last] = n;
      }

      void pop() {
          last--;
      }

      char& top() {
          return arr[last];
      }

      bool empty() const {
          return (last == -1);
      }

  private:
    char arr[MAX];
    int last = -1;
};

// (4+4)*5^(6+5) 
// 4 4 + 5 6 5 + ^ *
// * 5 ^ (6+ 5)

void OrderRPN(char c, Stack& stack) {
    std::map<char, int> prioryty = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^',3} };

    if (stack.empty()) {
        stack.push(c);
    }
    else {
        if (c == ')') {
            while (stack.top() != '(') {
                std::cout << stack.top() << ' ';
                stack.pop();
            }
            stack.pop();
        }
        else if (c == '(') {
            stack.push(c);
        }
        else {
            while (!stack.empty() && prioryty[stack.top()] >= prioryty[c]) {
                std::cout << stack.top() << ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }
}

void DevastStack(Stack& stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
}

void start(Stack& stack) {
    std::cout << "Введите выражение:\n";
    char chr[MAXLINE];
    char c;
    std::cin.getline(chr, MAXLINE);
    int i = 0;
    int sz = std::strlen(chr);
    while ( i < sz ) {
        c = chr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^') {
            OrderRPN(c, stack);
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
    DevastStack(stack);
    std::cout << "\n";
}

int main(){
    setlocale(LC_ALL, "RU");
    Stack stack;
    start(stack);   
}
