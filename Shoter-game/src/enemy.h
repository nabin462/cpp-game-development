#include<raylib.h>
class Enemy{
    int x,y,width,height;
    float speed;
    bool alive;
    public:
    Enemy(int a,int b){
        x=a;
        y=b;
        width=100;
        height=80;
        speed=5.5;
        alive=true;
    }
    void resetEnemy();
    void Draw();
    void update();
    int GETx(){
        return x;
    }
    int GETY(){
        return y;
    }

    int Getwidth(){
        return width;
    }
    
    int Getheight(){
        return height;
    }
    Rectangle rectangle(){
        Rectangle name={x,y,width,height};
        return name;
    }
    bool Getali(){
        return alive;
    }

    void destroy(){
        alive=false;
    }
    float setSpeed(float speed){
        return  this->speed=speed;
    }


};