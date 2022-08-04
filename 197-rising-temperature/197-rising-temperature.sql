# Write your MySQL query statement below
select distinct a.Id
from Weather a, Weather b
where a.temperature > b.temperature
and DATEDIFF(a.recorddate , b.recorddate) = 1;