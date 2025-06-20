# Write your MySQL query statement below
select w.id from weather w join weather p where w.temperature>p.temperature and DATEDIFF(w.recordDate,p.recordDate) = 1;
