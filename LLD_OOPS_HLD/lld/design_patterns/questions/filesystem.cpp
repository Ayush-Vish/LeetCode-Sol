#include<bits/stdc++.h>
using namespace std;

/*
Designn a FS.
-> it has hierarchical structure (directories and files)
-> we can do CRUD operations on files and directories
-> Each file has attributes like name, size, creation date, etc.
-> We can navigate through the file system using paths (e.g., /home/user/documents)


*/



/**
 * 
 * 
 * 
 * key Components:
 * 1. FS Node-> represents a file or directory in the file system. 
 * 2. File System Manager -> manages the overall structure and operations of the file system.
 * 3. File Class -> represents a file in the file system, with attributes like name, size, creation date, etc.
 * 4. Directory Class -> represents a directory in the file system, which can contain files and other directories.
 */



class FSNode{
    string name;
    time_t creationDate;
    time_t modifiedDate;
    size_t size;  
    bool isDirectory;
    FSNode* parent;
    vector<FSNode*> children; // only for directories

public:
    FSNode(string name, bool isDirectory, FSNode* parent = nullptr) : name(name), isDirectory(isDirectory), parent(parent) {
        creationDate = time(0);
        modifiedDate = creationDate;
        size = 0;
    }
};

class File : public FSNode {
public:
    File(string name, FSNode* parent = nullptr) : FSNode(name, false, parent) {}
};

class Directory : public FSNode {
    vector<FSNode*> children;
public:
    Directory(string name, FSNode* parent = nullptr) : FSNode(name, true, parent) {}
};


class FileSystemManager {
    FSNode*root;
public:
    FileSystemManager(){
        root = new FSNode("root", true  , nullptr);
    }
    FSNode* getRoot(){
        return root;
    }

    FSNode* createPath(string path, bool isDirectory){
        
    }
};

int main(){
    FileSystemManager fsManager;
    
    

    return 0 ;


}
