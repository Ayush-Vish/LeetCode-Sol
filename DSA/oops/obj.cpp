#include<bits/stdc++.h>
using namespace std;

class Hero{
      public:
      int health;
      const int aura;
      static  int timeToComplete;
      // A Read Only Function.
      static int  getTimeToComplete() {
            return timeToComplete;
      }
      void getHealth() const{
            
            cout << health << endl;
      }
      friend void printHealth(Hero h );
      // Hero(int health , int aura ) {
      //       (*this).health = health;
      //       aura = 1;
            // this means the const memmber is assigned After Creation of obj 
             
      // }
      Hero(int health) : health(health) ,aura(2){
            cout << "Initialization List Callled " << endl;
      }

};
void printHealth(Hero h ) {
      cout << "Health -> " << h.health << endl;
}
int Hero::timeToComplete = 2 ;

int main () {
      // Static Allocaation 
      
      Hero h1(1 ) ;
      cout << &(h1.health) << endl;
      Hero h3(h1);
      

      // Dynamic Allocaation 

      // Hero *h2 = new Hero(20 ,3 );






      return 0 ;
}
