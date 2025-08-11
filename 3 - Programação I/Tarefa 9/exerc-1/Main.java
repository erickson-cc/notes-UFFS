import java.util.ArrayList;

public class Main{
	public static void main(String[] args){
		int i;
		int vetoranos[];
		// Criar Objetos
		ArrayList<Integer> anos = new ArrayList<>();
		vetoranos = new int[2025];
		long startTime = System.nanoTime();
		for(i=0;i<=2024;i++){
			anos.add(i);
		}
		long endTime = System.nanoTime();
		System.out.println("ArrayList = "+(endTime-startTime));
		
		long startTimeV = System.nanoTime();
		for(i=0;i<=2024;i++){
			vetoranos[i] = i;
		}
		long endTimeV = System.nanoTime();
		System.out.println("Vetor = "+(endTimeV-startTimeV));

	}
}
