! Write a program that finds the summation of every number from 1 to num. The 
! number will always be a positive integer greater than 0.

module Solution
  implicit none
contains
  integer pure function summation(n) result (res)
    integer, intent(in) :: n
    res = n * (n + 1) / 2 ! your code here
  end function summation
end module Solution