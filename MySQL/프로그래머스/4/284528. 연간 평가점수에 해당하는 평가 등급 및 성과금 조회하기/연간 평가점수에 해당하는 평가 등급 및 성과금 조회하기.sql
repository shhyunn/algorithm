-- 코드를 작성해주세요
select a.EMP_NO as EMP_NO, a.EMP_NAME as EMP_NAME, 
case
when avg(b.SCORE) >= 96 then 'S'
when avg(b.SCORE) >= 90 then 'A'
when avg(b.SCORE) >= 80 then 'B'
else 'C'
end as GRADE,
case
when avg(b.SCORE) >= 96 then a.SAL * 0.2
when avg(b.SCORE) >= 90 then a.SAL * 0.15
when avg(b.SCORE) >= 80 then a.SAL * 0.1
else 0
end as BONUS
from HR_EMPLOYEES as a join HR_GRADE as b on a.EMP_NO = b.EMP_NO
group by a.EMP_NO
order by a.EMP_NO;