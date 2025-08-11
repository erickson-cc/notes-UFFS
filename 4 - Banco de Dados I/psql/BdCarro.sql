\c locadoranome postgres
set datestyle to 'ISO,DMY';

create table if not exists veiculo (
   placa varchar(7) not null,
   modelo varchar(20) NOT NULL,
   ano integer not null,
   cor varchar(10) not null,
   kilom integer not null,
   constraint pk_veiculo primary key (placa));
--
create table if not exists cliente (
   codcli varchar(5) not null,
   cpf varchar(11) NOT NULL,
   nome varchar(30) not null,
   email varchar(30) not null,
   ender varchar(40) not null,
   ntel varchar(15) not null,
   constraint pk_cliente primary key (codcli),
   constraint uk_cpf_cliente unique (cpf),
   constraint uk_email_cliente unique (email));
--
create table if not exists tarifa (
   descr varchar(6) not null,
   valor numeric (10,2) not null,
   constraint pk_tarifca primary key (descr));
--
create table if not exists locacao (
   placa varchar(7) not null,
   codcli varchar(5) not null,
   dtloca date not null, 
   dtdevo date,
   tarifa varchar(6) not null,
   constraint pk_locacao primary key (placa, codcli, dtloca),
   constraint fk_locacao_veiculo foreign key (placa) references veiculo(placa),
   constraint fk_locacao_cliente foreign key (codcli) references cliente(codcli),
   constraint fk_locacao_tarifa foreign key (tarifa) references tarifa(descr));
--
insert into tarifa (descr,valor) values ('blue',100.34);
insert into tarifa (descr,valor) values ('red',80.99), ('green',77.89);  
--
insert into cliente (codcli,cpf,nome,email,ender,ntel) values ('C11','11111-1','Edgar Codd','codd@uffs','R. Stanford','234444'),
                              ('C22','22222-2','Alan Turing','turing@uffs', 'R. Londres','567755'),
                              ('C41','33333-3','Marie Curie','curie@uffs','R. Paris','673333'),
                              ('C05','44444-4','Grace Hopper','hopper@uffs','R. Nasa','567444'),
                              ('C34','55555-5','Tanenbaum','tanen@uffs','R. SO','333444');
--
insert into veiculo (placa,modelo,ano,cor,kilom) values ('MK-10','Audi Q3',2019,'branco',45455),
                                                        ('KK-10','Ka',2018,'prata',76890),
                                                        ('XX-77','HR-V',2020,'vermelho',21888);

insert into locacao (placa, codcli,dtloca,dtdevo,tarifa) values ('MK-10','C11','01/08/2020','10/08/2020','blue'),
                                                                ('KK-10','C22','25/09/2020',NULL,'green'),
                                                                ('XX-77','C34','15/08/2020','23/08/2020','blue'),
                                                                ('MK-10','C41','20/08/2020','24/08/2020','green'),
                                                                ('KK-10','C05','01/07/2020','30/07/2020','red'),
                                                                ('XX-77','C34','17/09/2020','21/09/2020','red');


