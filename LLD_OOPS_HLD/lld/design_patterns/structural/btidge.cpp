#include<bits/stdc++.h>
using namespace std;
/**
 * 
 * 
 * 
*       So the bridge design Pattern is used to decouple an abstraction from its implementation
        so that the two can vary independently.
 
        Its like the abstracion uses the implementation
        but the abstraction and the implementation are independent of each other so 
        that we can change the implementation without changing the abstraction and vice versa.
 
    */

class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
};
class OpenGLAPI : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        cout << "Drawing circle using OpenGL\n";
    }
};

class DirectXAPI : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        cout << "Drawing circle using DirectX\n";
    }
};


class Shape {
protected:
    DrawingAPI* api;
public:
    Shape(DrawingAPI* api) : api(api) {}
    virtual void draw() = 0;
};

class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x, double y, double r, DrawingAPI* api)
        : Shape(api), x(x), y(y), radius(r) {}

    void draw() override {
        api->drawCircle(x, y, radius);
    }
};

class Square : public Shape {
    double x, y, side;
public:    Square(double x, double y, double s, DrawingAPI* api)
        : Shape(api), x(x), y(y), side(s) {}    
};

int main (){
    DrawingAPI* opengl = new OpenGLAPI();
    DrawingAPI* directx = new DirectXAPI();
    Shape* circle1 = new Circle(1, 2, 3, opengl);
    Shape* circle2 = new Circle(4, 5, 6, directx);
    circle1->draw();
    circle2->draw();
    
    
    return 0;
}
