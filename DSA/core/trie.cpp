#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
      char data;
      TrieNode *children[26];
      bool isTerminal;
      TrieNode(char data)
      {
            this->data = data;
            for (int i = 0; i < 26; i++)
            {
                  children[i] = NULL;
            }
            isTerminal = false;
      }
};
class Trie
{
public:
      TrieNode *root;

      Trie()
      {
            root = new TrieNode('\0');
      }
      void insertUtil(TrieNode *&root, string word)
      {

            if (word.size() == 0)
            {
                  root->isTerminal = true;
                  return;
            }
            int index = word[0] - 'a';
            TrieNode *child;

            if (root->children[index] == NULL)
            {
                  child = new TrieNode(word[0]);
                  root->children[index] = child;
            }
            else
            {
                  child = root->children[index];
            }

            insertUtil(child, word.substr(1));
      }
      void insert(string word)
      {
            TrieNode *node = root;
            for (auto it : word)
            {
                  int index = it - 'a';
                  if (node->children[index] == NULL)
                  {
                        node->children[index] = new TrieNode(it);
                  }
                  node = node->children[index];
            }
            node->isTerminal = true;
      }
      bool searchUtil(TrieNode *&root, string word)
      {
            TrieNode *node = root;
            for (auto it : word)
            {
                  int index = it - 'a';
                  if (node->children[index] == NULL)
                  {
                        return false;
                  }
                  else
                  {
                        node = node->children[index];
                  }
            }
            return node->isTerminal;
      }
      bool search(string word)
      {
            return searchUtil(root, word);
      }

      bool startUtil(TrieNode *&root, string s)
      {
            if (s.size() == 0)
            {
                  return true;
            }
            cout << " top  " << s << endl;
            int index = s[0] - 'a';

            TrieNode *child;
            cout << index << " " << s << endl;
            if (root->children[index] != NULL)
            {

                  child = root->children[index];
            }
            else
            {
                  cout << s << " false " << endl;
                  return false;
            }
            cout << " HERE " << endl;
            return startUtil(child, s.substr(1));
      }
      bool startsWith(string prefix)
      {
            // return startUtil(root, prefix ) ;
            TrieNode *node = root;

            for (auto it : prefix)
            {
                  int index = it - 'a';
                  if (node->children[index] == NULL)
                  {
                        return false;
                  }
                  else
                  {
                        node = node->children[index];
                  }
            }

            return true;
      }
      bool deleteWordUtil(TrieNode *&root, string word)
      {
            if (word.length() == 0)
            {
                  root->isTerminal = false;
                  // Check if the node has any children
                  for (int i = 0; i < 26; i++)
                  {
                        if (root->children[i] != NULL)
                        {
                              return false; // Node cannot be deleted as it has children
                        }
                  }
                  delete root;
                  root = NULL;
                  return true; // Node can be deleted
            }

            int index = word[0] - 'a';
            TrieNode *child = root->children[index];
            if (child == NULL)
            {
                  return false; 
            }

            bool shouldDeleteChild = deleteWordUtil(child, word.substr(1));

            if (shouldDeleteChild)
            {
                  root->children[index] = NULL;
                  if (!root->isTerminal)
                  {
                        for (int i = 0; i < 26; i++)
                        {
                              if (root->children[i] != NULL)
                              {
                                    return false; 
                              }
                        }
                        delete root;
                        root = NULL;
                        return true; 
                  }
            }

            return false; 
      }

      bool deleteWord(string word)
      {
            return deleteWordUtil(root, word);
      }
};


int main()
{
      Trie t = new Trie();


      return 0;
}
