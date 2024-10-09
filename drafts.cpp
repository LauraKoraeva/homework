//Продвинутые темы и техники C++

//Урок 8. Введение в ООП. Часть 1

//Задание 1. Реализация имитации аудиоплеера

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
#include <map>


enum PlayerCommands
{
    PLAY = 1,
    PAUSE,
    NEXT,
    STOP,
    EXIT,
};

class Track
{
private:
std::string m_title;
std::tm m_creationDate;
int m_duration;

public:
Track()
{
}

Track(std::string title, tm creationDate, int duration)
: m_title(title), m_creationDate(creationDate), m_duration(duration)
{
}

std::string getTitle() { return m_title; }
std::tm getCreationDate() { return m_creationDate; }
int getDuration() { return m_duration; }

void setTitle(std::string title) { m_title = title; }
void setCreationDate(std::tm creationDate) {
m_creationDate.tm_year = creationDate.tm_year;
m_creationDate.tm_mon = creationDate.tm_mon;
m_creationDate.tm_mday = creationDate.tm_mday;
}
void setDuration(int duration) { m_duration = duration; }

void print()
{
std::cout << "Title: " << m_title << '\n';
std::cout << "Creation date: " << m_creationDate.tm_year << "/" <<
m_creationDate.tm_mon << "/" << m_creationDate.tm_mday << '\n';
int minutes = m_duration / 60;
int seconds = (m_duration % 60) % 10;
if (seconds < 10)
    std::cout << "Duration: " << minutes << ":0" << seconds << '\n';
else
    std::cout << "Duration: " << minutes << ":" << seconds << '\n';
}
};

class Player
{
private:
std::map<std::string, Track> m_trackList;
std::vector<std::string> m_titleList;

Track* currentTrack;
bool m_isPlaying = false;
bool m_isPaused = false;
bool m_isStopped = true;

public:

void addTrack(Track newTrack)
{
m_trackList.insert(std::make_pair<std::string, Track>(newTrack.getTitle(), Track(newTrack)));
m_titleList.push_back(newTrack.getTitle());
}

void printPlaylist()
{
    for (int i = 0; i < m_titleList.size(); ++i)
    {
        std::cout << m_titleList[i] << '\n';
    }
}

void play()
{
if (!m_isPlaying)
{
std::cout << "Enter the track title\n";
std::string title;
std::getline(std::cin, title);

auto currentSong = m_trackList.find(title);
m_isPlaying = true;
std::cout << "Now playing: \n";
currentSong->second.print();
currentTrack = &currentSong->second;
}
}

void pause()
{
if (m_isPlaying && !m_isPaused)
{
m_isPlaying = false;
m_isPaused = true;
std::cout << currentTrack->getTitle() << " is paused\n";

}
}

void next()
{
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomNumber = rand() % (m_titleList.size());
   
 auto currentSong = m_trackList.find(m_titleList[randomNumber]);
m_isPlaying = true;
std::cout << "Now playing: \n";
currentSong->second.print();
currentTrack = &currentSong->second;
   

}

void stop()
{
if (m_isPlaying || m_isPaused)
{
currentTrack = nullptr;
m_isPlaying = false;
m_isPaused = false;
m_isStopped = true;
std::cout << "Player is stopped\n";
}
}

void exit()
{
exit();
}
};


int main()
{

std::tm date_1;
date_1.tm_year = 2011;
date_1.tm_mon = 07;
date_1.tm_mday = 04;
Track song_1("Set Fire to the Rain", date_1, 242);

std::tm date_2;
date_2.tm_year = 2014;
date_2.tm_mon = 03;
date_2.tm_mday = 17;
Track song_2("Chandelier", date_2, 216);

std::tm date_3;
date_3.tm_year = 2014;
date_3.tm_mon = 05;
date_3.tm_mday = 11;
Track song_3("Only Love Can Hurt Like This", date_3, 232);

std::tm date_4;
date_4.tm_year = 2016;
date_4.tm_mon = 04;
date_4.tm_mday = 15;
Track song_4("Just Like Fire", date_3, 215);

std::tm date_5;
date_5.tm_year = 2023;
date_5.tm_mon = 01;
date_5.tm_mday = 12;
Track song_5("Flowers", date_3, 200);


Player player;
player.addTrack(song_1);
player.addTrack(song_2);
player.addTrack(song_3);
player.addTrack(song_4);
player.addTrack(song_5);

std::cout << "********Playlist********\n";
player.printPlaylist();
std::cout << "************************\n";

std::cout << "Enter the command: \n";
std::cout << "1 - Play; 2 - Pause; 3 - Next; 4 - Stop; 5 - Exit. ";

int choice;
std::cin >> choice;



return 0;
}