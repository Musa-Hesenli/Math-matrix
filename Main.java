import java.util.ArrayList;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> triangleMatrix = new ArrayList<>();
        int[][] numbers = {
            {4, 5, 6},
            {7, 8, 9},
            {10, 14, 23}
        };
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        System.out.println("Enter row&column number:");
        int row_number = scan.nextInt();
        for(int i = 0; i < row_number; i++) {
            System.out.println("Enter entries for " + (i + 1) + ". row");
            ArrayList<Integer> row = new ArrayList<>();
            for(int j = 0; j < row_number;j++) {
                int num = scan.nextInt();
                row.add(num);
            }
            matrix.add(row);
        }    
        System.out.println("Original matrix:");
        for(ArrayList<Integer> arr : matrix) {
            System.out.print("[ ");
            for(int n : arr) {
                System.out.print(n + " ");
            };
            System.out.println("]");
        }
        final int elements_in_one_column = matrix.get(0).size() - 1;
        for(int sequence = 0; sequence < elements_in_one_column; sequence++) {
            for(int i = sequence + 1; i < row_number; i++) {
                final int divider = - (matrix.get(i).get(sequence) / matrix.get(sequence).get(sequence));
                for(int j = 0; j < matrix.get(i).size(); j++) {
                    int value = matrix.get(i).get(j) + divider * (matrix.get(sequence).get(j));
                    matrix.get(i).set(j, value);
                }
            }
        }
        System.out.println("Upper matrix:");
        for(ArrayList<Integer> arr : matrix) {
            System.out.print("[ ");
            for(int n : arr) {
                System.out.print(n + " ");
            };
            System.out.println("]");
        }
    }
}