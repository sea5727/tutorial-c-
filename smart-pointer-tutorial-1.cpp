#include<iostream>
#include<memory>
using namespace std;

class Object {

public:
    Object();
    ~Object();
    void Print(); 
    int GetID();
    void IncreaseID();
private:
    int ID; 
};

Object::Object() {
    std::cout << "Constructor" << std::endl;
    ID = 10;
}

Object::~Object() {
    std::cout << "Destructor" << std::endl;
}

void Object::Print() {
    std::cout << "Print Object" << std::endl;
}
int Object::GetID() {
    return ID;
}

void Object::IncreaseID() {
    std::cout << "Increase Object ID" << std::endl;
    ID++;
}
void unique_ptr_tutorial(){
    std::unique_ptr<Object> pa(new Object());
    // 1. c++14 에서 추가된 unique_ptr을 생성하는 팩토리이다.
    std::unique_ptr<Object> objectPtr = std::make_unique<Object>();


    // 2. 일반적인 대입연산자로 다른 포인터로 옮길수 없어 move 를 사용해서 옮긴다.
    std::unique_ptr<Object> objectPtrA = std::make_unique<Object>();
    std::unique_ptr<Object> objectPtrB = std::move(objectPtrA);


    // objectPtrA의 소유권이 없으나, print는 되는듯?, IncreseID는 객체변수를 변경시키기때문에 core down이 발생될것임.
    objectPtrA->Print();    // work
    objectPtrB->Print();    // work

    if(objectPtrA) {
        std::cout << "objectPtrA is valid" << std::endl;    
        objectPtrA->IncreaseID();    // not executed
    }
    objectPtrB->IncreaseID();

    // 3. 소멸 : objectPtrB에 새로운 unique_ptr을 선언해주니, 이전에 있던 objectPtrB 가 소멸
    objectPtrB = std::make_unique<Object>();    // lost ownership
    // reset : 소멸
    objectPtrB.reset();

}
void shared_ptr_tutorial(){
    std::shared_ptr<Object> pa(new Object());
    std::shared_ptr<Object> objectPtrA = std::make_shared<Object>();
    std::cout << "objectPtrA's use count : " << objectPtrA.use_count() << std::endl; // 1

    std::shared_ptr<Object> objectPtrB = objectPtrA;
    std::cout << "objectPtrA's use count : " << objectPtrA.use_count() << std::endl; // 2

    objectPtrB = nullptr;
    std::cout << "objectPtrA's use count : " << objectPtrA.use_count() << std::endl; // 1

    objectPtrA = nullptr; // destructor
}
void weak_ptr_tutorial()
{
    std::shared_ptr<Object> objectPtrA = std::make_shared<Object>();
    std::cout << "objectPtrA's use count : " << objectPtrA.use_count() << std::endl; // 1
    std::weak_ptr<Object> objectPtrB = objectPtrA;
    std::cout << "objectPtrA's use count : " << objectPtrA.use_count() << std::endl; // 1
    objectPtrB.reset(); // not work
    objectPtrA = nullptr; // use_count will be 0. call destructor
}
int main(){

}