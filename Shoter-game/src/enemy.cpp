#include<iostream>
#include"enemy.h"
#include<raylib.h>
using namespace std;
void Enemy::Draw(){
    DrawRectangle(x,y,width,height,RED);
}
void Enemy::update(){
    x=x+speed;

  if(x+width>GetScreenWidth())
    {
        speed=-speed;
    }
    if(x<0){

    speed=-speed;
    }
  
}