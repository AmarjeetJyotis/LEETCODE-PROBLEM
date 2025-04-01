# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT u.user_id AS buyer_id, join_date, IFNULL(COUNT(order_id),0) AS orders_in_2019
FROM Users AS u LEFT JOIN Orders AS o
ON u.user_id = o.buyer_id
AND YEAR(order_date) = '2019'
GROUP BY u.user_id