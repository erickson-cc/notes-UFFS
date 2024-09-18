import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;

public class Main{
	public static void main(String [] args){
		int lenList = 15;
		int[] lista = new int[lenList];
		int i;
    		Scanner sc = new Scanner(System.in);
		Random random = new Random();
		


		for(i=0; i<lenList;i++){
			//lista[i] = sc.nextInt();
			lista[i] = random.nextInt(100);
		}
		int maior = lista[0];
		for(i=0;i<lenList;i++){
			if (lista[i]>maior){
				maior = lista[i];
			}
		}
		System.out.printf("O maior número digitado foi: %d\n",maior);
		System.out.println(Arrays.toString(lista));
		////Imprimir lista
		//System.out.printf("[");
		//for(i=0;i<5;i++){
		//	System.out.printf("%d", lista[i]);
		//		if(i!=4){
		//			System.out.printf(", ");
		//	}
		//}
		//System.out.printf("]");
		///////////////////

		//Sort Lista
		Arrays.sort(lista);

		//Imprimir do jeito certo
		System.out.println(Arrays.toString(lista));
		sc.close();
	}
}
