#include"bullet.h"
#include<iostream>
#include"player.h"
#include"raylib.h"
using namespace std;
int main(){
    Player p;
    bullet b;
    InitWindow(800,800,"My shoter game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        b.update();
        p.Update();
        b.Draw();
        p.Draw();
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}