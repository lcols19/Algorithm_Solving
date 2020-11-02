// Create a function (or write a script in Shell) that takes an integer as an 
// argument and returns "Even" for even numbers or "Odd" for odd numbers.

#import <Foundation/Foundation.h>
NSString* evenOrOdd (NSInteger n){
  NSString *even = @"Even";
  NSString *odd = @"Odd";
  if ((n % 2) == 0)
    return even;
  else
    return odd;
}