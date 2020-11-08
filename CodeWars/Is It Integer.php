<!-- In this Kata we are passing a number (n) into a function.
Your code will determine if the number passed is integer (or not).
The function needs to return either a true or false.
Numbers may be positive or negative, string or null. -->

function isInt($n){
  if (is_int($n))
    return true;
  else
    return false;
}