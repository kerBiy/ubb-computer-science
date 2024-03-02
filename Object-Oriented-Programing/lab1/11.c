#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

typedef struct {
    float x;
    float y;
} Point;


int onSegment(Point p, Point q, Point r) {
    /*
    This function checks if point q lies on the segment defined by points p and r.
    Params: p, q, r. The points defining the segment and the point to check for membership.
    Returns: 1 if point q lies on segment pr, otherwise 0.
    */
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) 
            && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
            ? 1 : 0;
}

Point findIntersection(Point a, Point b, Point c, Point d) {
    /*
    This function calculates the intersection point of two line segments defined by the endpoints a, b and c, d, respectively.
    Params: a, b: The endpoints of the first line segment.
            c, d: The endpoints of the second line segment.
    Returns: intersection: The intersection point of the two line segments. If the segments are parallel or colinear but do not overlap, the coordinates of the intersection point are (-1, -1).
    */
    Point intersection;

    float a1 = b.y - a.y;
    float b1 = a.x - b.x;
    float c1 = a1 * (a.x) + b1 * (a.y);

    float a2 = d.y - c.y;
    float b2 = c.x - d.x;
    float c2 = a2 * (c.x) + b2 * (c.y);

    float determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        intersection.x = -1;
        intersection.y = -1;
    } else {
        intersection.x = (b2 * c1 - b1 * c2) / determinant;
        intersection.y = (a1 * c2 - a2 * c1) / determinant;
    }

    return intersection;
}

void getUserInput(Point *a, Point *b, Point *c, Point *d) {
    printf("Enter the coords for a: ");
    scanf("%f %f", &a->x, &a->y);
    printf("Enter the coords for b: ");
    scanf("%f %f", &b->x, &b->y);
    printf("Enter the coords for c: ");
    scanf("%f %f", &c->x, &c->y);
    printf("Enter the coords for d: ");
    scanf("%f %f", &d->x, &d->y);
}

int main() {
    Point a, b, c, d;

    while (1) {
        getUserInput(&a, &b, &c, &d);

        Point intersection = findIntersection(a, b, c, d);

        if (intersection.x != -1 && intersection.y != -1 && onSegment(a, intersection, b) && onSegment(c, intersection, d)) {
            printf("The segments are intersecting in: (%.2f, %.2f).\n", intersection.x, intersection.y);
        } else {
            printf("The segments are not intersecting.\n");
        }
    }

    return 0;
}
