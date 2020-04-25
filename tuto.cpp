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
    unique_ptr<list<string>>  producers;//Song class는 unique_ptr을 소유.
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
unique_ptr<Song> SongFactory(const string& artist, const string& title)
{
    return make_unique<Song>(artist, title);
}

void SongVector()
{
    vector<unique_ptr<Song>> songs;
    //unique_ptr 생성 및 vector에 추가
    songs.push_back(make_unique<Song>("Anne-Marie", "2002"));
    songs.push_back(make_unique<Song>("Namie Amuro", "Funky Town"));
    songs.push_back(SongFactory("Twice","FANCY"));

    auto song = make_unique<Song>("Ayumi Hamasaki", "Poker Face");

    unique_ptr<Song> song2 = std::move(song);//song은 "Ayumi Hamasaki" & "Poker Face"에 접근 할 수 없다.

    //songs.push_back(song2);//에러! song2는 song2라는 레퍼런스가 연결을 맺고 있으므로 move를 통해 연결을 옮겨주어야 한다.
    songs.push_back(std::move(song2));

    for (const auto& song : songs)
    {
        printf("Artist: %15s Title: %s\n", song->getArtist().c_str(), song->getTitle().c_str());
    }

    song.reset(); // song이 가리키고 있는 메모리 영역을 삭제함.
}
int main() {
    SongVector();
}