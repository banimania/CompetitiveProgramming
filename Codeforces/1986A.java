import java.util.Scanner;

public class IIP {
    
    public static void solve(int a, int b, int c) {
        System.out.println(Math.max(Math.abs(b - a), Math.max(Math.abs(b - c), Math.abs(c - a))));
    }
    
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int t = teclado.nextInt();
        for (int i = 0; i < t; i++) {
            int a = teclado.nextInt(), b = teclado.nextInt(), c = teclado.nextInt();
            solve(a, b, c);
        }
    }
}
