SELECT name
FROM Customer 
WHERE isnull(referee_id) OR referee_id<>2
