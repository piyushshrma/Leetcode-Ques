# Write your MySQL query statement below
select e.name from Employee e
join Employee f on f.managerid=e.id
group by f.managerId,e.id
having count(*) >= 5
order by e.name;
