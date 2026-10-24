#include<iostream>
#include"enemy.h"
#include<raylib.h>
#include<cstdlib>
using namespace std;
void Enemy::resetEnemy(){
    
      x=rand()%760;
      y=rand()%400;
}
void Enemy::Draw(){
    if(Getali()){
    DrawRectangle(x,y,width,height,RED);
    }
}
void Enemy::update(){
    if(Getali()){
    y=y+speed;

  if(y+height>GetScreenHeight())
    {
        y=0;x=rand()%760;
    }
   
}
  
}