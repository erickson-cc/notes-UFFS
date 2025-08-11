// preço do produto
// forma de pagamento (1 à vista, 2 à prazo)
// se forma de pagamento == 1 >> preço = preço*0.95
// se forma de pagamento == 2 >> preço = preço*1.1

let precoDoProduto;
let formaDePagamento;
let alerta;

precoDoProduto = parseInt(prompt("Informe o preço do produto: "));
formaDePagamento = parseInt(prompt("1- à vista \n 2- à prazo"));
const precoFinal = (precoDoProduto, formaDePagamento) => {
	if(formaDePagamento == '1'){
		precoDoProduto = precoDoProduto*0.95;
	}
	if(formaDePagamento == '2'){
		precoDoProduto = precoDoProduto*1.1;
	}
	return precoDoProduto;
	console.alert("ooo"

}

//console.log(precoFinal);
