alert("Script Carregou");

var myNewElement = $("<p> Elemento inserido por jQuery</p>");
myNewElement.appendTo("#Bio");
$("#Bio").css("background-color", "magenta");
$("<li class =\"impar\">2033 em diante</li>").appendTo("#lista");
$("p#paraAlterar").html("Alterado com sucesso");

var diminuirFonte = $("<button>diminuir</button>").click(function(){alert("Inserir funçao de diminuir a fonte")});
var aumentarFonte = $("<button>aumentar</button>").click(function(){alert("Inserir função de aumentar a fonte")});
diminuirFonte.insertBefore("#titulo");
aumentarFonte.insertBefore("#titulo");
