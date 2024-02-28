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
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return 1;
    return 0;
}

Point findIntersection(Point p1, Point q1, Point p2, Point q2) {
    /*
    This function calculates the intersection point of two line segments defined by the endpoints p1, q1 and p2, q2, respectively.
    Params: p1, q1: The endpoints of the first line segment.
            p2, q2: The endpoints of the second line segment.
    Returns: intersection: The intersection point of the two line segments. If the segments are parallel or colinear but do not overlap, the coordinates of the intersection point are (-1, -1).
    */
    Point intersection;

    float a1 = q1.y - p1.y;
    float b1 = p1.x - q1.x;
    float c1 = a1 * (p1.x) + b1 * (p1.y);

    float a2 = q2.y - p2.y;
    float b2 = p2.x - q2.x;
    float c2 = a2 * (p2.x) + b2 * (p2.y);

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

int main() {
    // Definirea coordonatelor pentru segmentul 1
    Point p1 = {1, 1};
    Point q1 = {4, 4};
    // Definirea coordonatelor pentru segmentul 2
    Point p2 = {1, 4};
    Point q2 = {4, 1};

    // Verificarea dacă segmentele se intersectează
    Point intersection = findIntersection(p1, q1, p2, q2);
    if (intersection.x != -1 && intersection.y != -1 && onSegment(p1, intersection, q1) && onSegment(p2, intersection, q2)) {
        printf("Segmentele se intersectează în punctul (%.2f, %.2f)\n", intersection.x, intersection.y);
    } else {
        printf("Segmentele nu se intersectează.\n");
    }

    return 0;
}
