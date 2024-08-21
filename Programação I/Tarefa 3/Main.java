class Conta{
	//Atributos
	int banco;
	int agencia;
	int numero;
	float saldo;
	String titular;
	String tipo;
	
	//Métodos
	
	public void printConta(){
		System.out.println("Conta: "+this.banco+" "+this.agencia+" "+this.numero);
		System.out.printf("Saldo: R$%.2f\n",this.saldo);
		System.out.println("Titular: "+this.titular);
		System.out.println("Tipo: "+this.tipo);
	}
	public void depositar(float valor){
		this.saldo = this.saldo += valor;
	}

	public void sacar(float valor){
		this.saldo = this.saldo -= valor;
	}

	public void transfere(float valor, Conta credor){
		if(this.saldo>=valor){
			this.saldo = this.saldo - valor;
			credor.saldo = credor.saldo + valor;
		}
		else{
			System.out.println("Saldo Insuficiente\n");	
		}
	}
}

public class Main{
	public static void main(String[] args){
		// Declarando as Contas
		//System.out.println("\nConta Nubank\n");
		Conta nubank = new Conta();
		nubank.banco = 128;
		nubank.agencia = 3333;
		nubank.numero = 4567;
		nubank.saldo = 100;
		nubank.titular = "Erickson";
		nubank.tipo = "corrente";
				
		//System.out.println("\nConta Banco do Brasil\n");
		Conta bb = new Conta();
		bb.banco = 001;
		bb.agencia = 3852;
		bb.numero = 1234;
		bb.saldo = 0;
		bb.titular = "Erickson";
		bb.tipo = "salario";
/*
   Desmarcar para imprimir as contas

		nubank.printConta();
		bb.printConta();
*/
/*
 * 		Etapa de transferência
 		System.out.println("\nTransferir 100 reais para a conta BB\n");
		*/
		nubank.transfere(100,bb);
/*
 * Desmarcar para conferir os valores
		//Conferir os saldos
		System.out.printf("nb = R$%.2f\n",nubank.saldo);	
		System.out.printf("bb = R$%.2f\n",bb.saldo);
		*/
		
		
	}
}

