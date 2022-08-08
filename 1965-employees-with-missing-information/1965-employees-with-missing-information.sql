select sub.employee_id
from (
    select e.employee_id, name, salary
    from employees as e
    left join salaries as s
    on e.employee_id = s.employee_id
    
    UNION
    
    select s.employee_id, name, salary
    from employees as e
    right join salaries as s
    on e.employee_id = s.employee_id
)
AS sub
where sub.name is null
or
sub.salary is null
order by sub.employee_id;