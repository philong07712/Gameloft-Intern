# include "MyPoint.cpp"
int main() {
    MyPoint p1(3, 2);
    MyPoint p2(7, 8);
    p1.Display();
    p1.SetX(5);
    cout << p1.GetX() << " " << p1.GetY();
}