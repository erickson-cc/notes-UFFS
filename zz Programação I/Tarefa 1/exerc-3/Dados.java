//3- Solicitar Nome, Idade e altura e imprimir desse jeito:
// Nome: <nome>
// Idade:<idade>, Altura:<altura>
import java.util.Scanner;

public class Dados {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Digite seu nome: ");
		String nome = sc.nextLine();

		System.out.println("Digite sua idade: ");
		byte idade = sc.nextByte();

		System.out.println("Digite sua altura: ");
		float altura = sc.nextFloat();

		System.out.println("Nome: "+nome);
		System.out.println("\nIdade: "+idade+"Altura: "+altura);
		
		sc.close();
	}
}


