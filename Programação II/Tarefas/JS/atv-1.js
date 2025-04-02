// numero de horas trabalhadas
// valor da hora de funcionário x
// calcular salario
// se horas > 200 salario = 105%

let horasTrabalhadas;
let valorHora;
let salario;
function calcularSalario(valorHora, horasTrabalhadas){
	if(horasTrabalhadas>200){
		return valorHora*horasTrabalhadas*1.05;
	}
	return valorHora*horasTrabalhadas;
}

horasTrabalhadas = parseInt(prompt("Insira as horas trabalhadas:"));
valorHora = parseInt(prompt("Insira o valor da hora:"));
salario = alert("O salário do funcionário é: R$ " + calcularSalario(valorHora, horasTrabalhadas));

