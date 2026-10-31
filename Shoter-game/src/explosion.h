#pragma once
#include<raylib.h>
class Explosion
{
private:
Texture2D frames[8];

int currentFrame = 0;
int totalFrames = 8;

float frameTimer = 0.0f;
float frameDuration = 0.05f;

float x, y;
bool finished = false;

public:
Explosion(float posX,float posY){
    x=posX;
    y=posY;
    for(int i=0;i<totalFrames;i++){
       frames[i] = LoadTexture(
    TextFormat("Shoter-game/assets/explosion%02d.png", i + 1)
);
    }

}
Explosion(const Explosion&) = delete;
Explosion& operator=(const Explosion&) = delete;

~Explosion()
{
    for(int i = 0; i < totalFrames; i++)
    {
        UnloadTexture(frames[i]);
    }
}


void Update();
void Draw();
bool IsFinished();
    

};


