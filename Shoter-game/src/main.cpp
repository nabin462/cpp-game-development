#include"bullet.h"
#include"enemy.h"
#include<iostream>
#include"player.h"
#include"raylib.h"
#include<cstdlib>
#include<ctime>
using namespace std;
#include<vector>
vector<bullet>bullets;
vector<Enemy>Enemys;
int score=0;
int main(){
    srand(time(0));
    Enemy e1(rand()%760,10);
    Enemy e2(rand()%760,200);
    Enemy e3(rand()%760,50);
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
            score+=1;
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
        DrawText(TextFormat("score:%i",score),10,10,30,WHITE);
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}