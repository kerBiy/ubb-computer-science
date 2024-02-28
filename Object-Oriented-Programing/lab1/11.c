#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;


int doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Găsește orientarea a 3 puncte
    int orient1 = ((q1.y - p1.y) * (p2.x - q1.x)) - ((q1.x - p1.x) * (p2.y - q1.y));
    int orient2 = ((q1.y - p1.y) * (q2.x - q1.x)) - ((q1.x - p1.x) * (q2.y - q1.y));
    int orient3 = ((q2.y - p2.y) * (p1.x - q2.x)) - ((q2.x - p2.x) * (p1.y - q2.y));
    int orient4 = ((q2.y - p2.y) * (q1.x - q2.x)) - ((q2.x - p2.x) * (q1.y - q2.y));

    if (((orient1 > 0 && orient2 < 0) || (orient1 < 0 && orient2 > 0)) &&
        ((orient3 > 0 && orient4 < 0) || (orient3 < 0 && orient4 > 0)))
        return 1; 

    return 0;
}

Point findIntersection(Point p1, Point q1, Point p2, Point q2) {
    Point intersection;

    // Calcularea coeficienților pentru segmentul 1
    float a1 = q1.y - p1.y;
    float b1 = p1.x - q1.x;
    float c1 = a1 * (p1.x) + b1 * (p1.y);

    // Calcularea coeficienților pentru segmentul 2
    float a2 = q2.y - p2.y;
    float b2 = p2.x - q2.x;
    float c2 = a2 * (p2.x) + b2 * (p2.y);

    // Calcularea determinantului
    float determinant = a1 * b2 - a2 * b1;

    // Verifică dacă determinantul este zero, caz în care segmentele sunt paralele și nu se intersectează
    if (determinant == 0) {
        intersection.x = -1;
        intersection.y = -1;
    } else {
        // Calcularea punctului de intersectare
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
    Point p2 = {2, 2};
    Point q2 = {3, 3};

    // Verificarea dacă segmentele se intersectează
    if (doIntersect(p1, q1, p2, q2)) {
        Point intersection = findIntersection(p1, q1, p2, q2);
        printf("Segmentele se intersectează în punctul (%.2f, %.2f)\n", intersection.x, intersection.y);
    } else {
        printf("Segmentele nu se intersectează.\n");
    }

    return 0;
}
