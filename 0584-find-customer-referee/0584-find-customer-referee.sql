/* Write your T-SQL query statement below */
select C.name
from Customer C
where C.referee_id != 2 or C.referee_id is null
