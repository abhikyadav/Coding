# Write your MySQL query statement below

select A.name AS Customers from Customers A where A.id NOT IN (select B.customerId from Orders B);