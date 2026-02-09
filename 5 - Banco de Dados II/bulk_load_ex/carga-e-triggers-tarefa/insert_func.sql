--5 - insert funcionario

create or replace procedure ins_emp() language plpgsql
as $$

declare
	cursor_dept CURSOR FOR SELECT * FROM dept;
	newemp employee%rowtype;
	curr_dept dept%rowtype;
	qtdemp int:= 0;
	count_emp int:=0;
BEGIN	
	OPEN cursor_dept;
	LOOP
		FETCH NEXT FROM cursor_dept INTO curr_dept;
		qtdemp:= 10;
		count_emp:= 0;
		LOOP
			newemp.ssn:= SELECT(random()*1000)::int+1;
			newemp.name:='Emp '||count_emp+1;
			newemp.salary:= SELECT round((random()*10000)::numeric,2);
			newemp.iddept := curr_dept.iddept;
			INSERT INTO employee (ssn, name, salary, iddept) values
			(newemp.ssn, newemp.name, newemp.salary, newemp.iddept);
			count_emp:= count_emp+1;
			
			exit when count_emp >= qtdemp;
			END LOOP;
	END LOOP;
END; $$;
