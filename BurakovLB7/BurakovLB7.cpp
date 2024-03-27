#include <iostream>
#include <map>
#include <string>
#include <fstream>

#define MAXSTACK 50
#define MAXLINE 500
#define MAXLINES 10
#define INFILE "input.txt"
#define OUTFILE "output.txt"

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
    char arr[MAXSTACK];
    int last = -1;
};


void StackRPN(char c, Stack& stack, std::string& output) {
    std::map<char, int> prioryty = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^',3} };
    if (stack.empty()) {
        stack.push(c);
    }
    else {
        if (c == ')') {
            while (stack.top() != '(') {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.pop();
        }
        else if (c == '(') {
            stack.push(c);
        }
        else {
            while (!stack.empty() && prioryty[stack.top()] >= prioryty[c]) {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.push(c);
        }
    }
}

void DevastStack(Stack& stack, std::string& output) {
    while (!stack.empty()) {
        output.push_back(stack.top());
        output.push_back(' ');
        stack.pop();
    }
}

void WriteFile(std::string out) {
    std::ofstream file(OUTFILE, std::ios::app);

    if (file.is_open()) {
        file << out << '\n';
        file.close();
    }
    else
        throw "Unable to open file\n";
}

void RPN(std::string chr) {
    Stack stack;
    std::string output;

    int i = 0;
    int sz = size(chr);
    while ( i < sz ) {
        if (chr[i] != ' ') {
            if (chr[i] == '+' || chr[i] == '-' || chr[i] == '*' || chr[i] == '/' || chr[i] == '(' || chr[i] == ')' || chr[i] == '^') {
                StackRPN(chr[i], stack, output);
            }
            else if (static_cast<int>(chr[i]) <= 57 && static_cast<int>(chr[i]) >= 48) {
                output.push_back(chr[i]);
                if (i < sz - 1) {
                    while (static_cast<int>(chr[i + 1]) <= 57 && static_cast<int>(chr[i + 1]) >= 48) {
                        output.push_back(chr[i + 1]);
                        i++;
                    }
                }
                output.push_back(' ');
            }
            else
                throw "Unfamilar symbol\n";
        }
        i++;
    }
    DevastStack(stack, output);
    WriteFile(output);
}

void ReadFile() {
    std::ifstream file(INFILE);
    std::string str;

    if (file.is_open()) {
        while (std::getline(file, str)) {
            RPN(str);
        }
        file.close();
    }
    else
        throw "Unable to open file\n";
}

int main(){
    setlocale(LC_ALL, "RU");
    ReadFile();   
}
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
