//2- Solicitar ao usuário que digite seu Nome e posteriormente seu Sobrenome, e Impima no console no seguinte formato Nome: <sobrenome>,<nome>
import java.util.Scanner;

public class NomeSobrenome{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite seu primeiro nome: ");

		String nome = sc.nextLine();

		System.out.println("Digite seu sobrenome: ");

		String sobrenome = sc.nextLine();

		System.out.println("Nome: "+sobrenome+", "+nome);
		sc.close();
	}
}
