class Enemy{
    int x,y,width,height;
    float speed;
    public:
    Enemy(){
        x=40;
        y=30;
        width=100;
        height=80;
        speed=5.5;
    }
    void Draw();
    void update();
};