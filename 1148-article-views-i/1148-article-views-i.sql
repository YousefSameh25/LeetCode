/* Write your T-SQL query statement below */
select distinct V.author_id id
from Views V
where V.viewer_id = V.author_id 
order by V.author_id 