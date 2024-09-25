abstract class Conta{
	String numero;
	double saldo;
	Conta(String numero, double saldo){
		this.numero = numero;
		this.saldo = saldo;
	}
}

class ContaCorrente extends Conta{//taxmnt; 
	double taxmnt;
	ContaCorrente(String numero, double saldo, double taxmnt){
		super(numero, saldo);
		this.taxmnt = taxmnt;
	}
}
interface AplicarRendimento{
	public void AplicarRendimento();
}
class ContaPoupanca extends Conta implements AplicarRendimento{//rendimento; qtsaques<=5; taxsaque;
	double rendimento;
	ContaPoupanca(String numero, double saldo, double rendimento){
		super(numero, saldo);
		this.rendimento = rendimento;
	}
	@Override
	public void AplicarRendimento(){
		this.saldo = this.saldo*this.rendimento;
	}
}

class ContaAplicacao extends Conta implements AplicarRendimento{//rendimento; disponibilidade; 
	double rendimento;
	ContaAplicacao(String numero, double saldo, double rendimento){
		super(numero, saldo);
		this.rendimento = rendimento;
	}
	@Override
	public void AplicarRendimento(){
		this.saldo = this.saldo*this.rendimento;
	}
}



public class Main{
	public static void main(String[] args){
		ContaCorrente conta1 = new ContaCorrente("12345",0,1.0005);
		ContaPoupanca conta2 = new ContaPoupanca("54321",100,1.008);
		ContaAplicacao conta3 = new ContaAplicacao("111111",100,1.01);
	}
}

