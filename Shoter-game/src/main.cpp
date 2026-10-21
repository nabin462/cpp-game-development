#include"bullet.h"
#include"enemy.h"
#include<iostream>
#include"player.h"
#include"raylib.h"
using namespace std;
#include<vector>
vector<bullet>bullets;
vector<Enemy>Enemys;
int main(){
    Enemy e1(40,10);
    Enemy e2(100,200);
    Enemy e3(200,400);
    Enemys.push_back(e1);
     Enemys.push_back(e2);
      Enemys.push_back(e3);
    Player p;
    
   // bullet b(p.GetX()+40,p.GetY());

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
        continue;
     }
     else{
        Vector2 position={bullets[i].Getx(),bullets[i].GetY()};
        bool hit =false;
        for(int j=0;j<Enemys.size();j++){
        if(Enemys[j].Getali()&&CheckCollisionCircleRec(position,bullets[i].Getradius(),Enemys[j].rectangle())){
            Enemys[j].destroy();
            bullets.erase(bullets.begin()+i);
            --i;
            hit =true;
            break;
        }
      
     }
     if(!hit){
       bullets[i].Draw();
     }
    }
        }
        for(int i=0;i<Enemys.size();i++){

        Enemys[i].update();
        Enemys[i].Draw();

        }
        p.Draw();
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}