-- Using temperature data set from ex.18
-- Display top 3 cities by temperature during July and August
-- ordered by temperature descending
-- This throws an error if ONLY_FULL_GROUP_BY is enabled. This disable this,
-- run: SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));
SELECT city, month, AVG(value) AS avg_temp FROM temperatures
WHERE (month=7 OR month=8)
GROUP BY city
ORDER BY avg_temp DESC
LIMIT 3;