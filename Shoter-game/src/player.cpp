#include"player.h"
#include"raylib.h"
void Player::LoadPlayerTexture(const char* filename){
    texture=LoadTexture(filename);

  

}
void Player::Draw(){
    //DrawRectangle(x,y,width,height,WHITE);
    // DrawRectangle(x, y, width, height, GREEN);
   DrawTexturePro(

    texture,
    Rectangle{0, 0, (float)texture.width, (float)texture.height},
    Rectangle{(float)x, (float)y, (float)width, (float)height},
    Vector2{0, 0},
    0.0f,
    WHITE
);
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
    if(x<0){
        x=0;
        
    }
  
    if(y<0){
y=0;

    }


      if(x+width>GetScreenWidth()){
        x=GetScreenWidth()-width;
    }

    
    if(y+height>GetScreenHeight()){
        y=GetScreenHeight()-height;
    }
}
