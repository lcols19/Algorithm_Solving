// Write the following function: 
// double area_of_polygon_inside_circle(double circle_radius, int number_of_sides);
// It should calculate the area of a regular polygon of numberOfSides, 
// number-of-sides, or number_of_sides sides inside a circle of radius 
// circleRadius, circle-radius, or circle_radius which passes through all the 
// vertices of the polygon (such circle is called circumscribed circle or 
// circumcircle). The answer should be a number rounded to 3 decimal places. 

const double PI = 3.141592653589793;
double area_of_polygon_inside_circle(double circle_radius, int number_of_sides) {
  double res;
 
  res = (double)number_of_sides * (circle_radius * circle_radius) / 2.0;
  res *= sin((2.0 * PI) / (double)number_of_sides);
  NSLog(@"%u", res);
  if (fmod(res, 10.0) >= 5.0)
    res = ceil(round(res * 1000.0)) / 1000.0;
  else if (fmod(res, 10.0) < 5.0)
    res = floor(round(res * 1000.0)) / 1000.0;
  return res;
}