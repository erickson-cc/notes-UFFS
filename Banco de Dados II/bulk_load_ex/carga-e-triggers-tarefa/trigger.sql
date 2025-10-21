-- 1. Quando inserir uma carreira para um funcionário, verificar se a carreira anterior(caso existir) tenta o enddt informado

create or replace function checkEndDate() returns trigger as $$
	-- quando inserir um novo atributo na table a emp_career
DECLARE
	enddate emp_career.enddt%type;
	cur_emp cursor for select enddt from emp_career where  ssn=NEW.ssn;
BEGIN
	open cur_emp;
	loop
		fetch next from cur_emp into enddate;
		exit when not found;
		if enddate is NULL then
			raise exception '% still has an open position', NEW.ssn;
		end if;
	end loop;
	close cur_emp;
	return NEW;
END; $$ language plpgsql;

create or replace TRIGGER trg_checkDate before insert on emp_career
	for each row execute procedure checkEndDate();
-- 2. Ao inserir um gerente do departamento, tem que estar num deparatamento que ele é chefe. E quando inserir uma divisão, ele tem que estar num departamento que é da divisão
