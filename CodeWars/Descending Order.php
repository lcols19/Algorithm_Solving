<!-- Your task is to make a function that can take any non-negative integer as 
an argument and return it with its digits in descending order. Essentially, 
rearrange the digits to create the highest possible number. -->

function descendingOrder(int $n): int {
  $toarr = array_map('intval', str_split($n));
  $outp = rsort($toarr);
  print_r($toarr);
  $join_string = join('',$toarr);
  echo $join_string;
  $nbr = (int)$join_string;  
  return ($nbr);
}