#include<iostream>
#include"player.h"
#include"raylib.h"
using namespace std;
int main(){
    Player p;
    InitWindow(800,800,"My shoter game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        p.Update();
        p.Draw();
        DrawCircle(400,400,50,RED);
        EndDrawing();

    }
    CloseWindow();

    return 0;
}