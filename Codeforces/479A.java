import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner tcl = new Scanner(System.in);
        int a = tcl.nextInt();
        int b = tcl.nextInt();
        int c = tcl.nextInt();

        int max = Math.max(Math.max(a + b + c, a * (b + c)), Math.max((a + b) * c, a * b * c));

        System.out.println(max);
    }
}

