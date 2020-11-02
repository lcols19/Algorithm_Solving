// Write a program that finds the summation of every number from 1 to num. The 
// number will always be a positive integer greater than 0.

int summation(int n) {
  int res = 0;
  int i;
  for (i = 1; i <= n; i++)
    res += i;
  return res;
}