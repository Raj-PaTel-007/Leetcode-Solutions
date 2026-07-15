# Write your MySQL query statement below
SELECT unique_id,name 
FROM Employees as a left join EmployeeUNI as b on a.id = b.id;