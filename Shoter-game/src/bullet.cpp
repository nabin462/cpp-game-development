#include"bullet.h"
#include"raylib.h"
#include<iostream>
using namespace std;
void bullet::Draw(){
    //DrawCircle(x,y,radius,BLUE);
 //  DrawTexture(bulletTexture,x-radius,y-radius,WHITE);
 
// Outer energy glow
DrawRectangle(
    x - 9, y - 25,
    18, 50,
    Fade(SKYBLUE, 0.30f)
);

// Inner energy glow
DrawRectangle(
    x - 5, y - 25,
    10, 50,
    Fade(BLUE, 0.45f)
);
 
DrawTexturePro(
    bulletTexture,
    Rectangle{0, 0, (float)bulletTexture.width, (float)bulletTexture.height},
    Rectangle{(float)x - 5,
    (float)y - 25,
    10,
    50},
    Vector2{0, 0},
    0.0f,
    WHITE

    
);
}
void bullet::update(){
   y=y-speed;
}
void bullet::resetbullet(){
    x=240;
    y=300;
}
