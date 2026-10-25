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
enum GameState{
    Menu,
    Playing,
    Game_Over,
    Pasued,

};
 


int main(){
   GameState gameState=Menu;

    
    srand(time(0));
    Enemy e1(rand()%760,rand()%400);
    Enemy e2(rand()%760,rand()%400);
    Enemy e3(rand()%760,rand()%400);
    Enemys.push_back(e1);
     Enemys.push_back(e2);
      Enemys.push_back(e3);
    Player p;
    
   // bullet b(p.GetX()+40,p.GetY());

    InitWindow(800,800,"My shoter game");
    SetTargetFPS(60);
    double lastDamageTime=3;
    double damageCoolDown=1;
    while(!WindowShouldClose()){
        BeginDrawing();
          
        ClearBackground(BLACK);
        if(IsKeyPressed(KEY_P)){
            if(gameState==Playing){
                gameState=Pasued;
            }
            else if(gameState==Pasued){
            gameState=Playing;
                }
        }

        if(gameState==Pasued){
            DrawText("PAUSED", 150, 100, 50, YELLOW);
                     DrawText("press p to resume",150,200,30,WHITE);
        }
        
       
        if(gameState==Menu){
            DrawText("MY SHOTER GAME",250,0,40,WHITE);
            DrawText("PRESS ENTER TO STARE",300,50,30,WHITE);
            if(IsKeyPressed(KEY_ENTER)){
                gameState=Playing;
            }
        }

      
        if(p.Health()>0&&gameState==Playing){
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
            if(Enemys[i].Getali()&&CheckCollisionRecs(p.rectangle(),Enemys[i].rectangle())&&GetTime()-lastDamageTime>=damageCoolDown){
                
                p.TakeDamage();
                lastDamageTime=GetTime();
            }
        }


        for(int i=0;i<Enemys.size();i++){

        Enemys[i].update();
        Enemys[i].Draw();

        }
        p.Draw();
        DrawText(TextFormat("score:%i",score),10,10,30,WHITE);
        DrawText(TextFormat("Health:%i",p.Health()),30,50,30,WHITE);
    }
        if(p.Health()==0){
            
            gameState=Game_Over;
        }
            if(gameState==Game_Over){
                DrawText("GAME OVER!", 200,400,50,RED);
            }

            if(gameState==Game_Over&&IsKeyPressed(KEY_R)){
           p.Reset();
           for(int i=0;i<Enemys.size();i++){
            Enemys[i].resetEnemy();
           }

          bullets.clear();
           score=0;
           gameState=Playing;
        }
        
           

        
    
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}