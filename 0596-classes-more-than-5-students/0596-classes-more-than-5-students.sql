# Write your MySQL query statement below
SELECT e1.class
FROM Courses e1 LEFT JOIN Courses e2
ON e1.class = e2.class
GROUP BY e1.class HAVING COUNT(DISTINCT e2.student)>=5
