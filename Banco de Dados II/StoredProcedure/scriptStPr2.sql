CREATE OR REPLACE FUNCTION  check_stock () RETURNS trigger AS $check_stock$ -- cria fun nome_função() retorna tipo_trigger as $$
DECLARE -- declarar
	pqtty product.pqty%type; -- parametros
BEGIN -- iniciar função SQL
 	SELECT pqty INTO pqtty FROM product WHERE pid=NEW.pid;
	IF TG_OP='INSERT' THEN
		IF NEW.sqty > pqtty THEN
			RAISE EXCEPTION 'No Stock for product %', NEW.pid;
			RETURN OLD;
		END IF;
		UPDATE product SET pqty=pqty-NEW.sqty WHERE pid=NEW.pid;
	ELSE 
		IF NEW.sqty > OLD.sqty THEN
			IF (NEW.sqty-OLD.sqty>pqty) THEN
				RAISE EXCEPTION 'No Stock for product %',  NEW.pid;
				RETURN OLD;
			END IF;
			UPDATE product SET pqty=pqty-(NEW.sqty-OLD.sqty) WHERE pid=NEW.pid;
			RETURN NEW;
		ELSE
			UPDATE product SET pqty=pqty+(OLD.sqty-NEW.sqty) WHERE pid=NEW.pid;
			RETURN NEW;
		END IF;
	END IF;
	RETURN NEW;
END; -- Terminar função SQL
$check_stock$ LANGUAGE plpgsql; -- $$ declara o tipo de linguagem.

