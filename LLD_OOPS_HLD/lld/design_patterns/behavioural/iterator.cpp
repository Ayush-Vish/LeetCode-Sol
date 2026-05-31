// iterator pattern in C++
/*
 * The Iterator pattern is a design pattern that provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation. It allows you to traverse a collection of objects without needing to know the details of how the collection is implemented.
 * 
 * In C++, the Iterator pattern can be implemented using classes and interfaces. The key components of the Iterator pattern include:
 * 
 * 1. **Iterator Interface**: This defines the methods for traversing the collection, such as `hasNext()`, `next()`, and `remove()`.
 * 2. **Concrete Iterator**: This implements the Iterator interface and maintains a reference to the collection it is iterating over. It keeps track of the current position in the collection.
 * 3. **Aggregate Interface**: This defines a method for creating an iterator, such as `createIterator()`.
 * 4. **Concrete Aggregate**: This implements the Aggregate interface and returns an instance of the Concrete Iterator.
 * 
 * The Iterator pattern promotes loose coupling between the client code and the collection, allowing for greater flexibility and maintainability.
 * 
 * Below is an example implementation of the Iterator pattern in C++:
 */ 
#include <bits/stdc++.h>

class PlaylistIterator {
public:
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
};
class SimplePlaylistIterator : public PlaylistIterator {
    std::vector<std::string> songs;
    int position;
public:
    SimplePlaylistIterator(std::vector<std::string> songs) : songs(songs), position(0) {}
    bool hasNext() override {
        return position < songs.size();
    }
    std::string next() override {
        if (hasNext()) {
            return songs[position++];
        }
        throw std::out_of_range("No more songs in the playlist");
    }
};
class RandomPlaylistIterator : public PlaylistIterator {
    std::vector<std::string> songs;
    std::vector<int> indices;
    int position;
public:
    RandomPlaylistIterator(std::vector<std::string> songs) : songs(songs), position(0) {
        indices.resize(songs.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::random_shuffle(indices.begin(), indices.end());
    }
    bool hasNext() override {
        return position < songs.size();
    }
    std::string next() override {
        if (hasNext()) {
            return songs[indices[position++]];
        }
        throw std::out_of_range("No more songs in the playlist");
    }
};
class Playlist {
    std::vector<std::string> songs;
public:
    void addSong(std::string song) {
        songs.push_back(song);
    }
    PlaylistIterator* createSimpleIterator() {
        return new SimplePlaylistIterator(songs);
    }
    PlaylistIterator* createRandomIterator() {
        return new RandomPlaylistIterator(songs);
    }
};

int main(){
    Playlist playlist;          
    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    
    PlaylistIterator* iterator = playlist.createSimpleIterator();
    std::cout << "Playing songs in order:" << std::endl;
    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }
    delete iterator;    

    iterator = playlist.createRandomIterator();
    std::cout << "Playing songs in random order:" << std::endl;
    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }
    delete iterator;



    return 0;

}
