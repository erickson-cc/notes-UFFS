CREATE TABLE product (			
	pid integer not null primary key,
	name varchar(30) not null,	
	pqty  integer not null
);
CREATE TABLE sale (
	sid integer not null primary key,
	sdate date not null,
	address varchar(30) not null
);
CREATE TABLE sale_item (
	sid integer not null,
	pid integer not null,
	sqty integer not null,
	CONSTRAINT pk_sale_item PRIMARY KEY (sid,pid),
	CONSTRAINT fk_sale_item_sale FOREIGN KEY (sid) REFERENCES sale(sid),
	CONSTRAINT fk_sale_item_product FOREIGN KEY (pid) REFERENCES product(pid)
);

