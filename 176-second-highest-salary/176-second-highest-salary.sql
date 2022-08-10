select (
    select distinct
    salary as SecondHighestSalary
    from Employee
    order by Salary DESC
    limit 1 offset 1
) 
AS SecondHighestSalary;