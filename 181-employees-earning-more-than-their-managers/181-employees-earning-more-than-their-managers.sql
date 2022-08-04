# Write your MySQL query statement below
select a.Name as 'Employee'
FROM
    Employee as a,
    Employee as b
WHERE
    a.ManagerId = b.Id AND a.Salary > b.Salary;