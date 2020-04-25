#include <stdio.h>
#include <memory>
#include <vector>
#include <list>
#include <string>


using namespace std;
class Song {
private:
    string title;
    string artist;
    unique_ptr<list<string>> producers;//Song class는 unique_ptr을 소유.
public:
    // list<string> 기본 생성자와 make_unique를 이용한 초기화
    Song(string artist, string title) : producers(make_unique<list<string>>()) {
        this->artist = artist;
        this->title = title;
    }
    string getTitle() {
        return title;
    }
    string getArtist() {
        return artist;
    }
};
class TestClass{
public:
    TestClass(){}
    ~TestClass(){}
};
unique_ptr<Song> SongFactory(const string& artist, const string& title)
{
    return make_unique<Song>(artist, title);
}

int main() {
    printf("main\n");
    std::auto_ptr<TestClass> tmp(new TestClass);
    std::auto_ptr<TestClass> tmp1(tmp);
    printf("ptr\n");
    std::unique_ptr<int> ptr = std::make_unique<int>();

    // Change value to 1
    *ptr = 1;
    printf("ptr2\n");
    printf("*ptr:%d\n", *ptr);
    // 2. std::unique_ptr (by moving 'ptr' to 'ptr2', 'ptr' doesn't own the object anymore)
    std::unique_ptr<int> ptr2 = std::move(ptr);
    int a = *ptr2; // 'a' is 1
    // printf("ptr:%p\n", ptr);
    
    int b = *ptr;  // undefined behavior! 'ptr' is 'nullptr'
                   // (because of the move command above)
    printf("b:%d\n", b);
}
