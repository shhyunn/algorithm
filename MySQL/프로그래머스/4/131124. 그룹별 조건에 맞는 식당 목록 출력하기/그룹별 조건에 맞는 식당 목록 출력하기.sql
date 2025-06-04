-- 코드를 입력하세요
select A.MEMBER_NAME, B.REVIEW_TEXT, DATE_FORMAt(B.REVIEW_DATE, '%Y-%m-%d') as REVIEW_DATE
from MEMBER_PROFILE as A JOIN REST_REVIEW as B ON A.MEMBER_ID = B.MEMBER_ID
where A.MEMBER_ID = (
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID
    order by COUNT(*) desc
    LIMIT 1
)
order by B.REVIEW_DATE, B.REVIEW_TEXT;