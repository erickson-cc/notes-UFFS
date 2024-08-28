class Conta{
	// atributos
	private int banco;
	private int agencia;
	private int numero;
	private float saldo;
	private String titular;
	private String tipo;

	// métodos
	public void depositar(float valor){
		this.saldo = this.saldo += valor;
	}

	public void sacar(float valor){
		this.saldo = this.saldo -= valor;
	}

}

class Funcionario{
	private String nome;
	private float salario;
	Data dataNascimento;

	public void setNome(String nome){
		this.nome = nome;
	}
	public void setSalario(float valor){
		this.salario=valor;
	}

	public String getNome(){
		return this.nome;
	}
	public float getSalario(){
		return this.salario;
	}

	// construtores
	Funcionario(String nome, float salario){
		this.nome = nome;
		this.salario = salario;
	}
	Funcionario(String nome, float valor, Data data){
		this.nome = nome;
		this.salario = valor;
		this.dataNascimento = data;
	}
	
	public void printFuncionario(){
		System.out.println("\n-----Informações Funcionário-----");
		System.out.println("Nome: "+this.nome);
		System.out.printf("Salário: R$%.2f\n",this.salario);
		if(this.dataNascimento!=null){
			System.out.printf("Data de Nascimento: %s/%s/%s\n",this.dataNascimento.dia,this.dataNascimento.mes,this.dataNascimento.ano);
		}
	}
}
class Cliente{
	private String nome;
	private String cpf;
	Data dataNascimento;
	int telefone;

	public void setNome(String nome){
		this.nome = nome;
	}
	public void setCPF(String cpf){
		this.cpf = cpf;
	}
	public String getNome(){
		return this.nome;
	}
	public String getCPF(){
		return this.cpf;
	}

	// construtores
	Cliente(String nome, String cpf){
		this.nome = nome;
		this.cpf = cpf;
	}
	Cliente(String nome, String cpf, Data data){
		this.nome = nome;
		this.cpf = cpf;
		this.dataNascimento = data;
	}
}
class Banco{
	private String razaoSocial;
	private String nomeFantasia;
	private String cnpj;
	private Data dataCriacao;
	private String endereco;
	private int telefone;

	public void setRazaoSocial(String razaoSocial){
		this.razaoSocial = razaoSocial;
	}
	public void setNomeFantasia(String nomeFantasia){
		this.nomeFantasia = nomeFantasia;
	}
	public void setCNPJ(String cnpj){
		this.cnpj = cnpj;
	}
	public void setDataCriacao(Data dataCriacao){
		this.dataCriacao = dataCriacao;
	}
	public void setEndereco(String endereco){
		this.endereco = endereco;
	}
	public void setTelefone(int telefone){
		this.telefone = telefone;
	}

	public String getRazaoSocial(){
		return this.razaoSocial;
	}
	public String getNomeFantasia(){
		return this.nomeFantasia;
	}
	public String getCNPJ(){
		return this.cnpj;
	}
	public Data getDataCriacao(){
		return this.dataCriacao;
	}
	public String getEndereco(){
		return this.endereco;
	}
	public int getTelefone(){
		return this.telefone;
	}

	public void printBanco(){
		System.out.println("\n--------Informações Banco--------");
		System.out.println("Razão Social: "+this.razaoSocial);
		System.out.println("Nome Fantasia: "+this.nomeFantasia);
		System.out.println("CNPJ: "+this.cnpj);
		System.out.printf("Data de Criação: %s/%s/%s\n",this.dataCriacao.dia,this.dataCriacao.mes,this.dataCriacao.ano);
		System.out.println("Endereço: "+this.endereco);
		System.out.println("Telefone: "+this.telefone);
	}
	
	// construtores
	Banco(String razaoSocial, String nomeFantasia, String cnpj, Data dataCriacao){
		this.razaoSocial = razaoSocial;
		this.nomeFantasia = nomeFantasia;
		this.cnpj = cnpj;
		this.dataCriacao = dataCriacao;
	}
	Banco(String razaoSocial, String nomeFantasia, String cnpj, Data dataCriacao, String endereco, int telefone){
		this.razaoSocial = razaoSocial;
		this.nomeFantasia = nomeFantasia;
		this.cnpj = cnpj;
		this.dataCriacao = dataCriacao;
		this.endereco = endereco;
		this.telefone = telefone;
	}
}
	

class Data{
	int dia;
	int mes;
	int ano;
	
	Data(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
}
// MAIN MAIN MAIN MAIN MAIN MAIN MAIN //

public class Main{
	public static void main(String[] args){
		Funcionario func1 = new Funcionario("Marcela",1900);
		Funcionario func2 = new Funcionario("Orivaldo", 2100);
		Data CriacaoBB = new Data(12,10,1808);
		Banco bb = new Banco("Banco do Brasil SA","Banco do Brasil","00.000.000/0001-91", CriacaoBB);

		bb.printBanco();
		func1.printFuncionario();
		func2.printFuncionario();
	}
}
