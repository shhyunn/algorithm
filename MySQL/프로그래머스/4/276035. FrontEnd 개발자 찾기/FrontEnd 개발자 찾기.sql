-- 코드를 작성해주세요
select D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
from DEVELOPERS as D JOIN (
    select SUM(CODE) as SUM_CODE
    from SKILLCODES
    where CATEGORY = 'Front End'
) as S ON (D.SKILL_CODE & S.SUM_CODE) > 0
order by D.ID;