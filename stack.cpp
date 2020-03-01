#include <iostream>
#include <string>
#include <stack>          // std::stack
using namespace std;

//pass by reference
//Another way to write this is take in parameter stack<int> &s and call emptyOutStack(s) in main
//That way I don't need to de-reference using -> for functions like s->empty
void emptyOutStack(stack<int> *s){
  while(!(s->empty())){
    cout << '\t' << s->top();
    s->pop();
  }
  cout << '\n';
}

//pass by value
void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main(){
  stack <int> s;
  s.push(10);
  s.push(30);
  s.push(20);

  showstack(s);

  cout << "Size of stack: " << s.size() << endl;

  emptyOutStack(&s);

  cout << "Size of stack: " << s.size() << endl;





}
