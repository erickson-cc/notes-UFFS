-- usar o site  explain.dalibo.com
explain
--analyze
select c.name, s.sdate,p.name,si.sqty
	from customer c join sale s on c.cid=s.cid
		join sale_item si on s.sid=si.sid
		join product p on si.pid=p.pid
where si.sqty>5
limit 10;
