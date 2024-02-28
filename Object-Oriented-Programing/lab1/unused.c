// int orientation(Point p, Point q, Point r) {
//     /*
//     This function determines the orientation of three points, i.e., whether point r lies to the left, right, or on the line defined by points p and q.
//     Params: p, q, r. The points for which orientation is to be determined.
//     Returns: 0 if the points are collinear, 1 if r lies to the left of line pq, and 2 if r lies to the right of line pq.
//     */
//     int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

//     if (val == 0) 
//         return 0; 
//     return (val > 0) ? 1 : 2;
// }

// int doIntersect(Point p1, Point q1, Point p2, Point q2) {
//     /*
//     This function checks if two segments defined by points p1, q1 and p2, q2 intersect.
//     Params: p1, q1: The points defining the first segment.
//             p2, q2: The points defining the second segment.
//     Returns: 1 if the segments intersect, otherwise 0.
//     */
//     int o1 = orientation(p1, q1, p2);
//     int o2 = orientation(p1, q1, q2);
//     int o3 = orientation(p2, q2, p1);
//     int o4 = orientation(p2, q2, q1);

//     if (o1 != o2 && o3 != o4)
//         return 1;

//     if (o1 == 0 && onSegment(p1, p2, q1)) return 1;
//     if (o2 == 0 && onSegment(p1, q2, q1)) return 1;
//     if (o3 == 0 && onSegment(p2, p1, q2)) return 1;
//     if (o4 == 0 && onSegment(p2, q1, q2)) return 1;

//     return 0;
// }
