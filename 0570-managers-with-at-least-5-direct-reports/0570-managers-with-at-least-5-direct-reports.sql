# Write your MySQL query statement below
SELECT m.name
FROM employee m
JOIN Employee emp
on m.id = emp.managerId
GROUP BY m.id , m.name
HAVING COUNT(emp.id) >=5;

