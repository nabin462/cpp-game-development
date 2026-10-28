#include"bullet.h"
#include"raylib.h"
#include<iostream>
using namespace std;
void bullet::Draw(){
    //DrawCircle(x,y,radius,BLUE);
  // DrawTexture(texture,x-radius,y-radius,WHITE);
DrawTexturePro(
    texture,
    Rectangle{0, 0, (float)texture.width, (float)texture.height},
    Rectangle{(float)x - radius, (float)y - radius,
              (float)(radius * 2), (float)(radius * 2)},
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
