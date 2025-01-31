import java.util.Scanner;

public class Vendedor {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        String frase = teclado.nextLine();
        
        String[] vocales = {"a", "o", "y", "e", "u", "i"};
        
        frase = frase.toLowerCase();
        for (int i = 0; i < vocales.length; i++) {
            frase = frase.replaceAll(vocales[i], "");
        }
        for (int i = 0; i < frase.length(); i++) {
            if (i % 2 == 0) frase = frase.substring(0, i) + "." + frase.substring(i);
        }
        System.out.println(frase);
    }


}
