const pgp = require("pg-promise")({});
const usuario = "postgres";
const senha = "postgres";
const host = "localhost";
const banco_de_dados = "postgres";

const express = require("express");
const app = express();
const porta = 3002;
app.use(express.json());


const db = pgp(`postgres://${usuario}:${senha}@${host}:${porta}/${banco_de_dados}`);
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

app.get(
	// recurso
	"/cliente",
	// callback
	(request, response) => {
		try{
			let clientes =  db.any("SELECT * FROM clientes;");
			response.json(clientes).status(200);
		} catch(error){
			console.log(error);
			response.sendStatus(404);
		}
	}
)
