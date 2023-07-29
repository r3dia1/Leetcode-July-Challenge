# 550. Game Play Analysis IV
> Solution: Subquery with date_add
>> Q: How to choose the day after the day they first logged in?
>> A: Use DATE_ADD(MIN(event_date), INTERVAL 1 DAY).