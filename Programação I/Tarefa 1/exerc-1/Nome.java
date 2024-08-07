//1- Solicitar ao usuário que digite seu nome e osteriormente imprime no console
import java.util.Scanner;

public class Nome {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite seu nome: ");
		
		String nome = sc.nextLine();
		System.out.println("Seu nome é: " + nome);
		sc.close();
	}
}
