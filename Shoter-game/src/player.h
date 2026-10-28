#include<raylib.h>
class Player{
    int x,y,width,height,health;//X,Y are the player position, width and height is the player dimension
    float speed;//speed of player on the screen.
    Texture2D texture;
    public:
     void Draw();//draw the player on the screen.
     void Update();//update the position of player on the screen
     Player(){
    x=200;
    y=300;
    width=80;
    height=100;
    speed=5.5;
    health=100;
    texture={0};
   

}
void LoadPlayerTexture(const char* filename);
int Health(){
    return health;
}

void Reset(){
    
       health=100;
       x=400;
       y=300;
    
}

void TakeDamage(){
    if(health>0){

    health-=20;
    }
    if(health<0){
        health=0;
    }
}
int GetX(){
    return x;
}
int GetY(){
    return y;
}

  Rectangle rectangle(){
        Rectangle name={x,y,width,height};
        return name;
    }

};