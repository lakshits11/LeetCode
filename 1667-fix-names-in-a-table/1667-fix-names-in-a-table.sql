select Users.user_id,
CONCAT( UPPER(SUBSTR(Users.name, 1, 1)),
        LOWER(SUBSTR(Users.name, 2)))
as name
from Users
order by
Users.user_id;