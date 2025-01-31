import java.util.Scanner;

public class IIP {
    
    public static String solve(long n) {
        if (n < 14) return "NO";
        
        long nDices = n / 14 - 1;
        
        for (long i = nDices * 14 + 15; i < nDices * 14 + 21; i++) {
            if (i == n) {
                return "YES";
            }
        }
        
        return "NO";
    }
    
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int t = teclado.nextInt();
        
        for (int i = 0; i < t; i++) {
            System.out.print(solve(teclado.nextLong()) + " ");
        }
    }
}
