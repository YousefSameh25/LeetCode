# Write your MySQL query statement below
select name as name, sum(amount) as balance
from Users inner join Transactions 
on Users.account = Transactions.account
group by name
having sum(amount) > 10000