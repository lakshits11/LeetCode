# Write your MySQL query statement below
SELECT employee_id,
IF (employee_id % 2 = 1 AND name not like "M%", salary, 0) as bonus
from Employees order by employee_id;