import java.util.Scanner;
import java.util.HashMap;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> phoneBook = new HashMap<>();

        System.out.println("Enter value of n: ");
        int n = sc.nextInt();
        sc.nextLine(); // Consume the newline character left by nextInt()

        String name;
        System.out.println("Enter values for Phone Book now");
        for (int i = 0; i < n; i++) {
            System.out.println("Enter Name: ");
            name = sc.nextLine();
            System.out.println("Enter Number: ");
            int number = sc.nextInt();
            sc.nextLine(); // Consume the newline character left by nextInt()
            phoneBook.put(name, number);
        }

        while (sc.hasNext()) {
            System.out.println("Enter Name to be searched: ");
            name = sc.nextLine();
            if (phoneBook.containsKey(name)) {
                System.out.println(name + "=" + phoneBook.get(name));
            } else {
                System.out.println("Not found");
            }
        }
    }
}
