-- begin; -- inicia uma transação concorrente

update customer
	set age = age+1 where cid = 10;

-- vai ficar em await
update product
	set pqty = 0 where pid = 5;


