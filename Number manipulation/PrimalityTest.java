import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.util.stream.Collectors;


public class PrimalityTest {
    // Prime checker function that returns boolean
    public static boolean isPrime(int n) {
        for (int i = 2; i < Math.sqrt(n); i++) { // i starts in 2, making sure n>=1
            if (n % i == 0 ) {
                return false;
            }
        }
            return true;
    }
    // Apply isPrime to a list using .map
    public static List<Boolean> mapHelper(List<Integer> inputList) {
        // Using stream to map each element
        return inputList.stream().map(PrimalityTest::isPrime).collect(Collectors.toList());
    }
    public static void main(String[] args) {
          String filePath = "numbers.txt"; // Path to the input file
         List<Integer> numbers = new ArrayList<>();
         BufferedReader br = new BufferedReader(new FileReader(filePath));
         String line;
            
            // Read each line, convert to integer, and add to the list
            while ((line = br.readLine()) != null) {
                try {
                    numbers.add(Integer.parseInt(line.trim())); // Convert str to int and add to list
                } catch (NumberFormatException e) { // handling non-integer lines
                   System.out.println("invalid line");
                }
            }
        // Apply the prime check and collect results
        List<Boolean> results = PrimalityTest.mapHelper(numbers);
        // Print the results
        System.out.println("Prime check results: ");
        for (int i = 0; i < numbers.size(); i++) {
            if (results.get(i) == false){
                System.out.println(numbers.get(i) + " is not prime");
            }
            if (results.get(i) == true){
                System.out.println(numbers.get(i) + " is prime");
            }
        }
    }
}