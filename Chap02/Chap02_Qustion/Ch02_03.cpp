#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point * result_point = new Point;

    result_point->xpos = (p1.xpos + p2.xpos);
    result_point->ypos = (p1.ypos + p2.ypos);

    return *result_point;
}

int main(void)
{
    Point * p1 = new Point;
    p1->xpos = 1;
    p1->ypos = 1;

    Point * p2 = new Point;
    p2->xpos = 2;
    p2->ypos = 2;

    Point &newPoint = PntAdder(*p1, *p2);

    cout<<"newPoint: "<<"("<<newPoint.xpos<<", "<<newPoint.ypos<<")"<<endl;

    delete p1;
    delete p2;
    delete &newPoint;

    return 0;
}