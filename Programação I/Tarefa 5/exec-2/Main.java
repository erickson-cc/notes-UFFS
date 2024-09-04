class Acomodacao{
	private String nome;
	private String localizacao;
	private double precoPorNoite;

	public void setNome(string nome){
		this.nome = nome;
	}
	public void setLocalizacao(string local){
		this.localizacao = local;
	}
	public void setPrecoPorNoite(double valor){
		this.precoPorNoite = valor;
	}

	public String getNome(){
		return this.nome;
	}
	public String getLocalizacao(){
		return this.localizacao;
	}
	public double getPrecoPorNoite(){
		return this.precoPorNoite;
	}

	Acomodacao(String nome, String localizacao, double precoPorNoite){
		this.nome = nome;
		this.localizacao = localizacao;
		this.precoPorNoite = precoPorNoite;
	}

	public int calcularPrecoTotal(int numeroDeNoites){
		return  this.precoPorNoite*numeroDeNoites;
	}
}

class Hotel extends Acomodacao{
	public int classificacao;

	Hotel(String nome, String localizacao, double precoPorNoite, int classificacao){
		super(nome, localizacao, precoPorNoite);
		this.classificacao = classificacao;
	}

	public int calcularPrecoTotal(int numeroDeNoites){
		return this.precoPorNoite*numeroDeNoites*0.9;
	}
}

class CasaDeFerias extends Acomodacao{
	public double tamanhoArea;

	CasaDeFerias(String nome, String localizacao, double precoPorNoite, double tamanhoArea){
		super(nome,localizacao,precoPorNoite);
		this.tamanhoArea=tamanhoArea;
	}
	
	public int calcularPrecoTotal(int numeroDeNoites){
		return this.precoPornoite*numeroDeNoites+50;
	}
}

public class Main{
	public static void main(String[] args){
		Hotel hotel1= new Hotel("Hotel Estrela","Chapecó",120.00,4);
		//5 noites
		CasaDeFerias casa1 = new CasaDeFerias("Casa de Praia","Bombinhas",200,50);
		System.out.println(hotel1.calcularPrecoTotal(5));
	}
}
