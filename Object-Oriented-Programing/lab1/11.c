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

void prob11() {
    Point a, b, c, d;

    printf("Enter the coords for a: ");
    scanf("%f %f", &a.x, &a.y);
    printf("Enter the coords for b: ");
    scanf("%f %f", &b.x, &b.y);
    printf("Enter the coords for c: ");
    scanf("%f %f", &c.x, &c.y);
    printf("Enter the coords for d: ");
    scanf("%f %f", &d.x, &d.y);

    Point intersection = findIntersection(a, b, c, d);

    if (intersection.x != -1 && intersection.y != -1 && onSegment(a, intersection, b) && onSegment(c, intersection, d)) {
        printf("The segments are intersecting in: (%.2f, %.2f).\n", intersection.x, intersection.y);
    } else {
        printf("The segments are not intersecting.\n");
        }
}

int isPrime(int nr) {
    /*
        This function checks if a number is prime
        param nr: a integer number
        return: 1 if a is a prime number 0 otherwise
    */
    if (nr <= 1) 
        return 0;
    if (nr != 2 && nr % 2 == 0) 
        return 0;

    for (int i = 3; i * i <= nr; i += 2) {
        if (nr % i == 0)
            return 0;
    }
    return 1;
}

void prob14() {
    /*Descompune un numar natural par, mai mare strict ca 2, intr-o suma
    de doua numere prime (verificarea ipotezei lui Goldbach).*/
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    if (n % 2 != 0 || n < 4) {
        printf("The number is invalid for the theorem.\n");
        return;
    }

    for (int i = 2; i <= n; ++i)
        if (isPrime(i) && isPrime(n - i))
            printf("The numbers are %d + %d\n", i, n - i);
}

int main() {

    while (1) {
        int option = 0;

        printf("Enter the mode: ");
        scanf("%d", &option);

        if (option == 1) 
            prob11();
        else if (option == 2)
            prob14();
        else if (option == 0)
            break;
        else 
            printf("The command is not valid.\n");
    }

    return 0;
}
// problema 1