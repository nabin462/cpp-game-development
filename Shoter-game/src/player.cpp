#include"player.h"
#include"raylib.h"

void Player::Draw(){
    DrawRectangle(x,y,width,height,WHITE);
}
void Player::Update(){
    if(IsKeyDown(KEY_W)){
        y-=3;
    }
    if(IsKeyDown(KEY_S)){
        y+=3;

    }
    if(IsKeyDown(KEY_A)){
        x-=3;
    }
    if(IsKeyDown(KEY_D)){
        x+=3;
    }
    if(x+width/2<GetScreenWidth()){
        x=0;
        x+4;
    }
}