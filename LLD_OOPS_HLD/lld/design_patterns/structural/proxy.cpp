#include <bits/stdc++.h>
using namespace std;

/**
 * Proxy Design Pattern
 * Controls access to RealVideo (lazy loading)
 */

class VideoInterface {
public:
    virtual void play() = 0;
    virtual ~VideoInterface() {}
};

// ✅ Real Object
class RealVideo : public VideoInterface {
    string filename;

    void loadFromDisk() {
        cout << "Loading video from disk: " << filename << endl;
    }

public:
    RealVideo(const string& filename) : filename(filename) {
        loadFromDisk();
    }

    void play() override {
        cout << "Playing video: " << filename << endl;
    }
};

// ✅ Proxy
class VideoProxy : public VideoInterface {
    string filename;
    RealVideo* realVideo;

public:
    VideoProxy(const string& filename)
        : filename(filename), realVideo(nullptr) {}

    void play() override {
        if (realVideo == nullptr) {
            realVideo = new RealVideo(filename); // lazy init
        }
        realVideo->play();
    }

    ~VideoProxy() {
        delete realVideo;
    }
};

int main() {
    VideoInterface* video = new VideoProxy("my_video.mp4");

    video->play(); // loads + plays
    cout << "-----\n";
    video->play(); // plays directly (no loading again)

    delete video;
}
