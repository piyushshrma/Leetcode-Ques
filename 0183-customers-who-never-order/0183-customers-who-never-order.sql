# Write your MySQL query statement below

SELECT C.name as Customers from Customers C where C.id not in (select O.customerId from Orders O);