class MyPoint {
    int mPosX;
    int mPosY;
    public:
    MyPoint();
    MyPoint(int, int);
    void Display();
    int GetX();
    int GetY();
    void SetX(int);
    void SetY(int);
    float Distance(MyPoint p);
};