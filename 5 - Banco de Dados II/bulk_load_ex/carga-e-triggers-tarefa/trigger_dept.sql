-- duarte@uffs.edu.br Assunto: team09
create or replace function link_emp() returns trigger as $$
	-- quando inserir um novo atributo na table a emp_career
DECLARE
	nemp employee.ssn%type;
	curr_emp cursor for select ssn from employee where iddept=NEW.iddept;
	--curr_dept cursor for select * from dept where iddept = NEW.iddept;
BEGIN
	raise notice 'trigger acionada';
	open curr_emp;
	loop
		fetch next from curr_emp into nemp;
		exit when not found;
		raise notice 'entrou no loop';
	if TG_OP ='insert' then
		raise notice 'entrou no insert';
		update dept set nemp = (select t.nemp from dept as t where t.iddept = NEW.iddept)+1 where iddept = NEW.iddept;
		raise notice 'employee inserido';
	else
		update dept set nemp = (select t.nemp from dept as t where t.iddept = NEW.iddept)-1 where iddept = NEW.iddept;
		raise notice 'employee removido';
		update dept set nemp = (select t.nemp from dept as t where t.iddept = NEW.iddept)-1 where iddept = NEW.iddept;
		raise notice 'employee adicionado';
	end if;
		raise notice 'saiu do if';
	end loop;
	close curr_emp;
	return NEW;
END; $$ language plpgsql;

create or replace TRIGGER trg_nempdept before insert or update on employee
	for each statement execute procedure link_emp();

