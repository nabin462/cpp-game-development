#include<iostream>
#include"enemy.h"
#include<raylib.h>
#include<cstdlib>
using namespace std;
void Enemy::resetEnemy(){
    
      x=rand()%760;
      y=rand()%400;
}
void Enemy::enemyTextureload(Texture2D texture){
    enemyTexture=texture;
}
void Enemy::Draw(){
    if(Getali()){

   // DrawRectangle(x,y,width,height,RED);
   DrawTexturePro(

    enemyTexture,
    Rectangle{0, 0, (float)enemyTexture.width, (float)enemyTexture.height},
    Rectangle{(float)x, (float)y, (float)width, (float)height},
    Vector2{0, 0},
    0.0f,
    WHITE
);
   

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