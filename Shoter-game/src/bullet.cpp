#include"bullet.h"
#include"raylib.h"
#include<iostream>
using namespace std;
void bullet::Draw(){
    DrawCircle(x,y,radius,BLUE);

}
void bullet::update(){
   y=y-speed;
}
void bullet::resetbullet(){
    x=240;
    y=300;
}