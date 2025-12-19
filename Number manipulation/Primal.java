/* PrimalityTest.java */
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;


public class Primal {

    public static int isPrime(numberList){ // Prime checker function for integers
        int i = 0;
        List<Integer> primes = new ArrayList<>();
        while(n >= i){
            for (int j = 0; j < numberList.size(); j++) {
                n = numberList.get(i);
                if (!(n % i == 0 && n != 0 && n != 1)) {
                    primes.add(n); 
            }
         i++;
        }
        return primes;
    }

//apply isPrime to a list using .map
public static List<Integer> mapHelper(List<Integer> inputList) {
//using stream collection
    return inputList.stream().map(i -> isPrime(i)).collect(Collectors.toList()); 
    }
  }
}

public static void main(String[] args) {
    /*
    String filePath = "numbers.txt"; // Path to the input file
    List<Integer> numbers = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            
            // Read each line, convert to integer, and add to the list
            while ((line = br.readLine()) != null) {
                try {
                    numbers.add(Integer.parseInt(line.trim())); // Convert str to int and add to list
                } catch (NumberFormatException e) {
                   return; // Handle invalid lines
                }
            }
        } catch (IOException e) {
            System.exit(1);
        }
    
*/
    // Test numbers
    int[] testNumbers = {1, 2, 3, 4, 5, 10, 11, 13, 25, 29};

    List<Integer> numberList = new ArrayList<>();
        for (int num : testNumbers) {
            numberList.add(num); // Add each int to numberList
        }
     Primal.mapHelper(numberList);
}