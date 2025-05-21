const express = require("express");
const app = express();
const porta = 3002;
app.use(express.json());


app.listen(
	// porta
	porta,
	// callback
	() => console.log(`Servidor rodando na porta ${porta}.`)
);

app.get(
	// recurso
	"/hello",
	// callback
	(request, response) => {
		const horasTrabalhadas = request.body.horasTrabalhadas;
		const valorHora = request.body.valorHora;
		const salario = request.body.salario;
		response.send("O salario é :" + salario);
		response.send("Hello World!");
	}
);

app.post(
	//recurso
	"/hello",
	//callback
	(request, response) => {
		const fulano = request.body.fulanoCliente;
		response.send(`Hello ${fulano}!`);
	}
);
