#include"bullet.h"
#include<iostream>
#include"player.h"
#include"raylib.h"
using namespace std;
#include<vector>
vector<bullet>bullets;
int main(){
    Player p;
    bullet b(p.GetX()+40,p.GetY());

    InitWindow(800,800,"My shoter game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
       p.Update();
        if(IsKeyPressed(KEY_SPACE)){
            bullet b(p.GetX()+40,p.GetY());
            bullets.push_back(b);
        }
        for(int i=0;i<bullets.size();i++){
     bullets[i].update();
     if(bullets[i].GetY()<0){
        bullets.erase(bullets.begin()+i);
        --i;
     }
     else{
        bullets[i].Draw();
     }
        }
        
        
        p.Draw();
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}