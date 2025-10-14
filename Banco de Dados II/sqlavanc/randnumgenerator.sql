--select (random()*9)::int+1 from generate_series (1,2);
--select md5(random()::text);
--select left(md5(random()::text), 5);

-- Gerar 1000 tuplas randômicas de uma vez

-- insert into dummy (type, name) select
-- 	(random()*50)::int+1,
-- 	left(md5(random()::text), 5)
--  from generate_series(1,1000);

-- Agora fazer isso com uma stored procedure

DROP PROCEDURE createDummy;
CREATE PROCEDURE createDummy(qt int) as $$
DECLARE
	--dtype INT[5]:= array[1,2,3,4,5];
	dtype INT[5]:= '{1,2,3,4,5}';
	rdummy dummy%rowtype; -- cria um registro com (id, type, name)
	counter int := 0;
BEGIN
	loop
		counter := counter+1;
		rdummy.type := dtype[(random()*4)::int+1];
		rdummy.name := 'Dummy' || counter::text;
		insert into dummy (type, name) values (rdummy.type, rdummy.name);
		if (mod(counter, 5000)=0) then
			commit;
			raise notice 'commit + %' , counter/5000;
		end if;
		exit when counter = qt;
	end loop;

END; $$ language plpgsql;

call createDummy(500000);
