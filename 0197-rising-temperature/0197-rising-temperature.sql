SELECT s2.id AS id
FROM Weather s1,Weather s2
WHERE DATEDIFF(s2.recordDate,s1.recordDate)=1 AND s1.temperature<s2.temperature;
