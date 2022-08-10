select id, (
    CASE
    when p_id is NULL then 'Root'
    when p_id is not NULL and id in(SELECT p_id from Tree) then 'Inner'
    else 'Leaf'
    END
)
as type from Tree