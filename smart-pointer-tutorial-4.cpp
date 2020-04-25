#include <iostream>
#include <memory>
#include <vector>

class A {
  int *data;
 public:
  A() {

    data = new int[100];
    std::cout << "자원을 획득함!" << std::endl;
  }
    void print(){
        std::cout << "class A print" << std::endl;
    }
  ~A() {
    std::cout << "소멸자 호출!" << std::endl;
    delete[] data;
  }
};

void valid(){
  std::vector<std::shared_ptr<A>> vec;
  std::shared_ptr<A> p1 = std::make_shared<A>();
  vec.push_back(std::shared_ptr<A>(p1));
//   vec.push_back(std::shared_ptr<A>(new A()));
  vec.push_back(std::shared_ptr<A>(vec[0]));
  vec.push_back(std::shared_ptr<A>(vec[1]));

  // 벡터의 첫번째 원소를 소멸 시킨다.
  std::cout << "첫 번째 소멸!" << std::endl;
  vec.erase(vec.begin());

  // 그 다음 원소를 소멸 시킨다.
  std::cout << "다음 원소 소멸!" << std::endl;
  vec.erase(vec.begin());

  // 마지막 원소 소멸
  std::cout << "마지막 원소 소멸!" << std::endl;
  vec.erase(vec.begin());

  std::cout << "프로그램 종료!" << std::endl;
}
void invalid()
{
    A *a = new A();

    std::shared_ptr<A> pa1(a);
    std::shared_ptr<A> pa2(a);

    std::cout << pa1.use_count() << std::endl;
    std::cout << pa2.use_count() << std::endl;
}
int main() {
    std::cout << "program start\n";
    std::shared_ptr<A> testA = std::make_shared<A>();
    std::shared_ptr<A> testB = std::make_shared<A>();
    std::shared_ptr<A> testC = testB;
    testA->print();
    testB->print();
    testC->print();

    std::cout << "program end\n";
}