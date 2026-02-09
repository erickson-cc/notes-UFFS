create table dummy (
	id serial not null primary key, -- Serial é um atributo que vai ser incrementado de forma automática
	type integer not null,
	name varchar(30) not null
);
