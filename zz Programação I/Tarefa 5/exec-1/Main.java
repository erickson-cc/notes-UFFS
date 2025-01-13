class DispositivoEletronico{
	public String marca;
	public String modelo;
	public int capacidadeArmazenamento;

	public void ligar(){
		System.out.println("O dispositivo está ligado");
	}

	//Construtor
	DispositivoEletronico(String marca, String modelo, int capacidadeArmazenamento){
		this.marca = marca;
		this.modelo = modelo;
		this.capacidadeArmazenamento = capacidadeArmazenamento; }

}	

class Smartphone extends DispositivoEletronico{
	public String numeroTelefone;
	
	public void fazerChamada(String numeroDestino){
		System.out.println("O dispositivo está fazendo chamada para o número " + numeroDestino);
	}

	//Construtor
	Smartphone(String marca, String modelo, int capacidadeArmazenamento, String numeroTelefone){
		//super.marca = marca;
		//super.modelo = modelo;
		//super.capacidadeArmazenamento = capacidadeArmazenamento; 
		super(marca,modelo,capacidadeArmazenamento);
		this.numeroTelefone = numeroTelefone;
	}

}

class Notebook extends DispositivoEletronico{
	public String sistemaOperacional;

	public void executarPrograma(String programa){
		System.out.println("O "+this.sistemaOperacional+" está executando o programa "+programa);
	}	
	//Construtor
	Notebook(String marca, String modelo, int capacidadeArmazenamento, String sistemaOperacional){
		//super.marca = marca;
		//super.modelo = modelo;
		//super.capacidadeArmazenamento = capacidadeArmazenamento; 
		super(marca,modelo,capacidadeArmazenamento);
		this.sistemaOperacional= sistemaOperacional;
	}

}

public class Main{
	public static void main(String[] args){
		Smartphone smartphone1 = new Smartphone("Apple","Iphone 15",128,"888-256");
		Notebook notebook1 = new Notebook("Dell","xperia",1048,"Linux");
		smartphone1.ligar();
		notebook1.ligar();
		smartphone1.fazerChamada(smartphone1.numeroTelefone);
		notebook1.executarPrograma("Facebook");
	}
}

