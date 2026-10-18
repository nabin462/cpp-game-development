class Player{
    int x,y,width,height;//X,Y are the player position, width and height is the player dimension
    float speed;//speed of player on the screen.
    public:
     void Draw();//draw the player on the screen.
     void Update();//update the position of player on the screen
     Player(){
    x=200;
    y=300;
    width=80;
    height=100;
    speed=5.5;
}
int GetX(){
    return x;
}
int GetY(){
    return y;
}

};