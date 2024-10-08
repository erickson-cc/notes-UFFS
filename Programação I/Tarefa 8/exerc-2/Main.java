abstract class Pizza{
	public void preparar(){
		System.out.println("Preparando a Pizza");
	}
}
class SaborCalabresa extends Pizza{
	int qtdCalabresa;
	int qtdCebola;
	SaborCalabresa(int qtdCalabresa, int qtdCebola){
		this.qtdCalabresa = qtdCalabresa;
		this.qtdCebola = qtdCebola;
	}
	public int getCalabresa(){
		return this.qtdCalabresa;
	}
	public int getCebola(){
		return this.qtdCebola;
	}
	public void setCalabresa(int qtd){
		this.qtdCalabresa = qtd;
	}
	public void setCebola(int qtd){
		this.qtdCebola = qtd;
	}
	@Override
	public void preparar(){
		System.out.println("Preparando Pizza de Calabresa");
	}
}
class SaborMarguerita extends Pizza{
	int qtdManjericao;
	int qtdTomate;
	SaborMarguerita(int qtdManjericao, int qtdTomate){
		this.qtdManjericao = qtdManjericao;
		this.qtdTomate= qtdTomate;
	}
	public int getManjericao(){
		return this.qtdManjericao;
	}
	public int getTomate(){
		return this.qtdTomate;
	}
	public void setManjericao(int qtd){
		this.qtdManjericao = qtd;
	}
	public void setTomate(int qtd){
		this.qtdTomate = qtd;
	}
	@Override
	public void preparar(){
		System.out.println("Preparando Pizza de Marguerita");
	}
}
class SaborQuatroQueijos extends Pizza{
	int qtdQueijo;
	SaborQuatroQueijos(int qtdQueijo){
		this.qtdQueijo= qtdQueijo;
	}
	public int getQueijo(){
		return this.qtdQueijo;
	}
	public void setQueijo(int qtd){
		this.qtdQueijo = qtd;
	}
	@Override
	public void preparar(){
		System.out.println("Preparando Pizza de 4Queijos");
	}
}

public class Main{
	public static void main(String[] args){
		// Criar os Objetos
		SaborCalabresa pizza1 = new SaborCalabresa(40,40);
		SaborMarguerita pizza2 = new SaborMarguerita(10,30);
		SaborQuatroQueijos pizza3 = new SaborQuatroQueijos(120);
		
		Pizza Rodizio[] = new Pizza[5];

		Rodizio[0] = pizza1;
		Rodizio[1] = pizza2;
		Rodizio[2] = pizza3;

		int i;
		for(i=0;i<5;i++){
			Rodizio[i].preparar();
		}
	}
}

