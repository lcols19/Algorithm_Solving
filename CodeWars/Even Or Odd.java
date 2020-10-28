// Create a function (or write a script in Shell) that takes an integer as an 
// argument and returns "Even" for even numbers or "Odd" for odd numbers.

public class EvenOrOdd {
    public static String even_or_odd(int number) {
      int  res;
      String o = "Odd";
      String e = "Even";
      
      res = number % 2;
      if (res != 0)
        return o;
      return e;
        
    }
}