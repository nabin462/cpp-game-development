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
   Rectangle resumeButton={300,350,200,60};
     Rectangle quitButton={300,280,200,60};
     Rectangle pauseButton={580,0,200,60};
     Rectangle enterButton={280,300,200,60};
     Rectangle reStart={250,480,200,60};

     float spawnTimer=0.0f;
     float spawnInterval=2.0f;

    
    srand(time(0));
    Enemy e1(rand()%760,rand()%400);
    Enemy e2(rand()%760,rand()%400);
    Enemy e3(rand()%760,rand()%400);
    Enemys.push_back(e1);
     Enemys.push_back(e2);
      Enemys.push_back(e3);

    
   

    InitWindow(800,800,"My shoter game");
    SetTargetFPS(60);
    double lastDamageTime=3;
    double damageCoolDown=1;

      Player p;
        p.LoadPlayerTexture("Shoter-game/assets/playerShip2_blue.png");
          Texture2D bulletTexture = LoadTexture("Shoter-game/assets/laserBlue06.png");
          Texture2D enemyTexture=LoadTexture("Shoter-game/assets/enemyRed2.png");
   
 
        
    bool hover=true;
        
    while(!WindowShouldClose()){
        BeginDrawing();
          
        ClearBackground(BLACK);
        
        

        if(gameState==Menu){
           // DrawText("MENU STATE ACTIVE", 200, 100, 30, GREEN);
           
            DrawText("MY SHOTER GAME",250,0,40,WHITE);
              DrawRectangleRec(enterButton,BLUE);
        DrawText("ENTER",300 ,310 , 30, YELLOW);
            if(CheckCollisionPointRec(GetMousePosition(),enterButton)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                gameState=Playing;
                 
            }
           
        }
        if(CheckCollisionPointRec(GetMousePosition(),enterButton)&&gameState==Menu){
            if(hover){
                DrawRectangleRec(enterButton,RED);
                 DrawText("ENTER",300 ,310 , 30, YELLOW);
            }
            else{
                DrawRectangleRec(enterButton,BLUE);
            }
        }


        if(gameState==Playing){
            DrawRectangleRec(pauseButton,BLUE);
       DrawText("PASUED",590,10,30,WHITE);

        }
        
        if(CheckCollisionPointRec(GetMousePosition(),pauseButton)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
              gameState=Pasued;
        }
        if(gameState==Pasued){
            DrawRectangleRec(resumeButton,BLUE);
                    DrawText("RESUME",350,360,30,WHITE);
                    DrawRectangleRec(quitButton,BLUE);
                     DrawText("QUIT",380,290,30,WHITE);
                      if(CheckCollisionPointRec(GetMousePosition(),quitButton)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            CloseWindow();

        }

          if(CheckCollisionPointRec(GetMousePosition(),resumeButton)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    
                    gameState=Playing;
     }
                    
        }
    

      
        if(p.Health()>0&&gameState==Playing){
            //DrawText("PLAYER DRAW CODE REACHED", 100, 100, 20, GREEN);
            spawnTimer+=GetFrameTime();
            if(spawnTimer>=spawnInterval){
                Enemy e4(rand()%760,0);
                e4.enemyTextureload(enemyTexture);
                  if(score>=15){
                e4.setSpeed(10.5);
            }
        
       else if(score>=10){
               e4.setSpeed(8.5);
            }

       else if(score>=5){  
            e4.setSpeed(6.5);
        }
        else if (score<5){
              e4.setSpeed(5.5);
        }

                Enemys.push_back(e4);
                spawnTimer=0.0f;
            
            }
       p.Update();

        if(IsKeyPressed(KEY_SPACE)){
            bullet b(p.GetX()+40,p.GetY(), bulletTexture);
        
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
            Enemys[i].enemyTextureload(enemyTexture);

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
                DrawRectangleRec(reStart,BLUE);
                DrawText("Restart",260,490,30,WHITE);
            }

            if(gameState==Game_Over){
                if(CheckCollisionPointRec(GetMousePosition(),reStart)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
           p.Reset();
           for(int i=0;i<Enemys.size();i++){
            Enemys[i].resetEnemy();
           }

          bullets.clear();
           score=0;
           gameState=Playing;
        }
        }

         if(score>=15){
            for(int i=0;i<Enemys.size();i++){
                Enemys[i].setSpeed(10.5);
            }
        }
         
       else if(score>=10){
            for(int i=0;i<Enemys.size();i++){
                Enemys[i].setSpeed(8.5);
            }
        }

       else if(score>=5){
            for(int i=0;i<Enemys.size();i++){
                Enemys[i].setSpeed(6.5);
            }
        }
        else if (score<5){
            for(int i=0;i<Enemys.size();i++){
                Enemys[i].setSpeed(5.5);
            }
        }
       
        
           
           

        
    
       
        EndDrawing();

    }
    CloseWindow();

    return 0;
}