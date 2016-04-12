SELECT SUBSTR(REVERSE(telephone), 1, LENGTH(telephone) - 1) AS 'enohpelet' FROM distrib
WHERE telephone LIKE '05%';