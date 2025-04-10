#include <iostream>
#include <string>

using namespace std;

// Base class
class MediaPlayer {
public:
    virtual void play() {
        cout << "Playing media..." << endl;
    }

    virtual void pause() {
        cout << "Pausing media..." << endl;
    }

    virtual void stop() {
        cout << "Stopping media..." << endl;
    }
};

// Derived class AudioPlayer
class AudioPlayer : public MediaPlayer {
public:
    void play() {
        cout << "Playing audio..." << endl;
    }

    void pause() {
        cout << "Pausing audio..." << endl;
    }

    void stop() {
        cout << "Stopping audio..." << endl;
    }
};

// Derived class VideoPlayer
class VideoPlayer : public MediaPlayer {
public:
    void play() {
        cout << "Playing video..." << endl;
    }

    void pause() {
        cout << "Pausing video..." << endl;
    }

    void stop() {
        cout << "Stopping video..." << endl;
    }
};

int main() {
    MediaPlayer* players[2];

    players[0] = new AudioPlayer();
    players[1] = new VideoPlayer();

    // Play media
    for (int i = 0; i < 2; ++i) {
        players[i]->play();
    }

    // Pause media
    for (int i = 0; i < 2; ++i) {
        players[i]->pause();
    }

    // Stop media
    for (int i = 0; i < 2; ++i) {
        players[i]->stop();
    }

    // Cleaning up dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}
