# Write your MySQL query statement below
select p.project_id , 
    -- ROUND(
    --     sum(e.experience_years)/count(e.employee_id),2) as average_years
    ROUND(
        avg(experience_years),2) as average_years
from Project p
left join Employee e
on p.employee_id = e.employee_id
group by p.project_id