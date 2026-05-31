#include<bits/stdc++.h>
/**
 * 
 * a youtube Channel.
 *  will have a list of subscribers.
 *  when a new video is uploaded, the channel will notify all the subscribers.
 * 
 * now subscriver can be of different types, for example, email subscriber, sms subscriber, etc.
 * 
 * 
 * 
 * 
 * 
 * 
 */


class Subscriber {
public:
    virtual void update(std::string videoTitle) = 0;
};

class EmailSubscriber: public Subscriber {
    std::string email;
    
public:
    EmailSubscriber(std::string email) : email(email) {}
    void update(std::string videoTitle) override {
        std::cout << "Email sent to subscriber: " << email << " with video title: " << videoTitle << std::endl;
    }
};

class YoutubeChannel {
    std::vector<Subscriber*> subscribers;
public:
    void subscribe(Subscriber* subscriber) {
        subscribers.push_back(subscriber);
    }
    void uploadVideo(std::string videoTitle) {
        std::cout << "New video uploaded: " << videoTitle << std::endl;
        notify(videoTitle);
    }
    void notify(std::string videoTitle) {
        for (auto subscriber : subscribers) {
            subscriber->update(videoTitle);
        }
    }


};


int main(){
    YoutubeChannel channel;
    EmailSubscriber* subscriber1 = new EmailSubscriber("subscriber1@example.com");
    channel.subscribe(subscriber1);
    channel.uploadVideo("New Video Title");
    delete subscriber1;
    return 0;
}
