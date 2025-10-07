delete from sale_item;
delete from sale;
delete from product;

insert into product (pid, name, pqty) values (1, 'um' ,10), (2, 'dois', 15);
insert into sale (sid, sdate, address) values (101, '1-1-2000' ,'R.x'), (102, '1-1-1999', 'R.y');
select * from product;
select * from sale_item;
insert into sale_item (sid, pid, sqty) values (101, 1, 6);
select * from product;
select * from sale_item;
update sale_item set sqty = sqty-4 where sid=101 and pid=1;
insert into sale_item(sid,pid,sqty) values (102, 1, 8);

