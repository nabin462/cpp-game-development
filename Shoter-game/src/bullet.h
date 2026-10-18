class bullet{
    private:
    int x,y,radius;
    int speed;
    public:
    void Draw();
    void update();
    bullet(int a,int b){
        x=a;
        y=b;
        speed=5;
        radius=30;
    }
    int GetY(){
        return y;
    }
};