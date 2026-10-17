class bullet{
    private:
    int x,y,radius;
    int speed;
    public:
    void Draw();
    void update();
    bullet(){
        x=300;
        y=200;
        speed=5;
        radius=20;
    }
};