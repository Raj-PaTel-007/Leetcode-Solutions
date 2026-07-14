# Write your MySQL query statement below
SELECT product_name,year,price
FROM Sales Inner JOIN Product On Sales.product_id = Product.product_id;