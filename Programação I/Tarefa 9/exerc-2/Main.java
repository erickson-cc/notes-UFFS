class SaldoInsuficienteException extends RuntimeException{
	public SaldoInsuficienteException(String mensagem){
		super(mensagem);
	}
}

class Conta{
	String numero;
	double saldo;
	Conta(String numero, double saldo){
		this.numero = numero;
		this.saldo = saldo;
	}

	public void Depositar(double valor){
		if (valor < 0){
			throw new IllegalArgumentException("Valor negativo inválido");
		}
		this.saldo = this.saldo + valor;
	}
	public void Sacar(double valor) throws SaldoInsuficienteException{
		if (this.saldo<valor){
			throw new SaldoInsuficienteException("Saldo Insuficiente");}
		else{
			this.saldo = this.saldo-valor;
		}
	}


}

public class Main{
	public static void main(String[] args){
	
	Conta bb = new Conta("12345",100);
	bb.Depositar(200);
	//Testes
	//
	//bb.Depositar(-100);
	bb.Sacar(2000);
	bb.Depositar(-200);
	}
}	
