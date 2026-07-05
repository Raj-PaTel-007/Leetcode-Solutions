# Write your MySQL query statement below
SELECT name
FROM Customer 
Where referee_id IS NULL OR referee_id != 2;