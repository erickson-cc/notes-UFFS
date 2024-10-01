abstract class Conta{
	String numero;
	double saldo;
	Conta(String numero, double saldo){
		this.numero = numero;
		this.saldo = saldo;
	}

	public void Depositar(int valor){
		this.saldo = this.saldo + valor;
	}
	public void ImprimirSaldo(){
		System.out.println("O saldo da conta "+this.numero+" é: R$ "+this.saldo);
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
		// Criar os Objetos
		ContaCorrente conta1 = new ContaCorrente("12345",0,1.0005);
		ContaPoupanca conta2 = new ContaPoupanca("54321",0,1.008);
		ContaAplicacao conta3 = new ContaAplicacao("111111",0,1.01);
		
		// Depositar 100 reais
		conta2.Depositar(100);
		conta3.Depositar(100);

		// Aplicar Rendimento
		conta2.AplicarRendimento();
		conta3.AplicarRendimento();

		// Imprimir Saldo
		conta1.ImprimirSaldo();
		conta2.ImprimirSaldo();
		conta3.ImprimirSaldo();
	}
}

