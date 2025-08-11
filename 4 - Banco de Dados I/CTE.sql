-- Nesse exemplo, o CTE foi implementado no banco de dados da locadora de veículos
with	cte_qreserva as (select count(codcli) as qt from locacao group by codcli),
	cte_maxreserva as (select max(qt) as mx from cte_qreserva)
select	c.nome
from	cliente as c join locacao as l on c.codcli=l.codcli
group by c.nome
having count(*)=(select mx from cte_maxreserva);

