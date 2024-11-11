# Write your MySQL query statement below
select s.user_id, ifnull(Round((sum(if(c.action="confirmed",1,0)))/(count(*)),2),0) as confirmation_rate
from Signups s left join Confirmations c using(user_id)
group by s.user_id
