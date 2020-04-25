#include <iostream>
#include <memory>

class A {
  int* data;

 public:
  A() {
    std::cout << "자원을 획득함!" << std::endl;
    data = new int[100];
  }

  void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }

  void do_sth(int a) {
    std::cout << "무언가를 한다!" << std::endl;
    data[0] = a;
  }

  ~A() {
    std::cout << "자원을 해제함!" << std::endl;
    delete[] data;
  }
};

// 올바르지 않은 전달 방식
void do_something(std::unique_ptr<A>& ptr) { ptr->do_sth(3); }

int main() {
    std::cout<< "main start\n" ;
  std::unique_ptr<A> pa(new A());
  do_something(pa);
    std::cout<<"program end\n";
}