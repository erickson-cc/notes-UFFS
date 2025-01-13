abstract class Animal{
	String nome;
	int idade;

	Animal(String nome, int idade){
		this.nome = nome;
		this.idade = idade;
	}

	public void imprimirAnimal(){
		System.out.printf("%s, %d\n",this.nome, this.idade);
	}
	abstract void fazerSom();

}

class Gato extends Animal{

	Gato(String nome, int idade){
		super(nome, idade);
	}
	
	public void escalar(){
		System.out.printf("O gato %s está escalando", this.nome);
	}

	public void fazerSom(){
		System.out.printf("Miau\n");
	}
}

class Cachorro extends Animal{

	Cachorro(String nome, int idade){
		super(nome, idade);
	}
	
	public void correr(){
		System.out.printf("O cachorro %s está correndo\n", this.nome);
	}

	public void fazerSom(){
		System.out.printf("Au Au\n");
	}

}

public class Main{
	public static void main(String[] args){
		//Animal urso1 = new Animal("Pooh", 7);
		Gato gato1 = new Gato("Garfield",10);
		Cachorro cachorro1 = new Cachorro("Snoopy", 50);
		
		//Tarefa 2d
		//urso1.imprimirAnimal();
		gato1.imprimirAnimal();
		gato1.fazerSom();
		cachorro1.imprimirAnimal();
		cachorro1.fazerSom();
	}
}
