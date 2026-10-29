#include<raylib.h>
class bullet{
    private:
    int x,y,radius;
    int speed;
    Texture2D bulletTexture;
    public:
    void Draw();
    void update();
    bullet(int a,int b,Texture2D texture){
        x=a;
        y=b;
        speed=5;
        radius=6; 
        bulletTexture=texture;
    }


    void resetbullet();
    int GetY(){
        return y;
    }
   int Getx(){
    return x;

    }
    int Getradius(){
        return radius;
    }
};