select product_id, 'store1' as store, store1 AS price FROM Products where store1 is not NULL
UNION
select product_id, 'store2' as store, store2 AS price FROM Products where store2 is not NULL
UNION
select product_id, 'store3' as store, store3 AS price FROM Products where store3 is not NULL