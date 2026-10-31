#include<raylib.h>
#include"explosion.h"
void  Explosion::Update(){
    frameTimer+=GetFrameTime();
    if(frameTimer>=frameDuration){
        currentFrame++;
        frameTimer=0.0f;
    }
    if(currentFrame>=totalFrames){
        finished=true;
    }
}
void Explosion::Draw(){
    if(!finished){
        DrawTexturePro(
            frames[currentFrame],
            Rectangle{0, 0,
                (float)frames[currentFrame].width,
                (float)frames[currentFrame].height
            },
            Rectangle{x - 40, y - 40, 80, 80},
            Vector2{0, 0},
            0.0f,
            WHITE
        );
    }
}



bool Explosion::IsFinished(){
    return finished;
}