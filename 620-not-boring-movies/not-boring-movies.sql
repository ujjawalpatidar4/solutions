# Write your MySQL query statement below
select * from cinema
where id%2!=0 AND description!="boring"
ORDER BY rating DESC;