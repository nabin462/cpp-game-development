class bullet{
    private:
    int x,y,radius;
    int speed;
    Texture2D bulletTexture;
    public:
    void Draw();
    void update();
    bullet(int a,int b,Texture2D bulletTexture){
        x=a;
        y=b;
        speed=5;
        radius=30; 
        this->bulletTexture=bulletTexture;
    }


    void resetbullet();
    int GetY(){
        return y;
    }
   int Getx(){
    return x;

    }
    int Getradius(){
        return radius;
    }
};