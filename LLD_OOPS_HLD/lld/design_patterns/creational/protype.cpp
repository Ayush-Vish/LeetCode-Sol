#include<bits/stdc++.h>
using namespace std;



class Prototype {
public:
      virtual Prototype* clone() const = 0;
      virtual void show() const = 0;
      virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype {
      private:
      int data ;
      public:
      ConcretePrototype(int data): data(data) {}
      Prototype*clone() const override {
            return new ConcretePrototype(*this);
      }
      void show() const override {
            std::cout << "Data = " << data << std::endl;
        }
};


int main() {
      Prototype* original = new ConcretePrototype(42);
  
      Prototype* copy = original->clone();
  
      original->show();
      copy->show();
  
      delete original;
      delete copy;
  }
