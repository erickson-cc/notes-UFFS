import java .util.Scanner;

public class Conversor{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		float celsius;
		float fahrenheit;

		System.out.println("Digite a temperatura em Celsius: ");	
		celsius = sc.nextFloat();
		
		fahrenheit = celsius*1.8f+32;

		System.out.printf("Temperatura %.2f F", fahrenheit);
		sc.close();
	}
}

