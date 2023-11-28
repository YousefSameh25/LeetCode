/* Write your T-SQL query statement below */
select T.tweet_id 
from Tweets T
where len(T.content) > 15