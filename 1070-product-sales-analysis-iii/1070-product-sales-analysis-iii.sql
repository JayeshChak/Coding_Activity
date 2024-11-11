# Write your MySQL query statement below
SELECT product_id, year as first_year, quantity, price
FROM Sales s
WHERE (product_id, year) in 
(
    SELECT product_id, min(year) from sales
    Group by product_id
)