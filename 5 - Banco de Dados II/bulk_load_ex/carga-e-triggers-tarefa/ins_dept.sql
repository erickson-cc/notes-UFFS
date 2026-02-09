delete from dept;
create or replace procedure ins_dept() language plpgsql as $$
declare
	array_qt int[3]:= '{4,5,6}';
	name varchar(30);
	nemp int:=0;
	iddiv int:=1;
	tup_dept dept%rowtype;
	counter_dept int:=0;
	counter_div int:=1;
	qttd int:=0;

begin
	raise notice 'Creating dept';
	loop -- Criar o dept
		qttd := array_qt[(random()*2)::int+1];
		counter_dept := 0;

		loop -- Inserir o dept na divisão xyz
			tup_dept.name:='Dept ' || counter_dept+1;
			tup_dept.iddiv:=counter_div;
			tup_dept.nemp:=0;

			insert into dept(name,nemp, iddiv) values (tup_dept.name, tup_dept.nemp, tup_dept.iddiv);

			counter_dept := counter_dept+1;
			exit when counter_dept >= qttd;
		end loop;

		counter_div:= counter_div+1;
		exit when counter_div >=6;
	end loop;
end; $$;
