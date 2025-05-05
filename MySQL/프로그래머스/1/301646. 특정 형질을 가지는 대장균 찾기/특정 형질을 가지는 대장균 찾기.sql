-- 코드를 작성해주세요
# select COUNT(*) as COUNT
# from ECOLI_DATA
# where ((GENOTYPE & 1) != 0 or (GENOTYPE & 3) != 0) and ((GENOTYPE & 2) = 0);

SELECT COUNT(*) AS COUNT
FROM ECOLI_DATA
WHERE GENOTYPE & 2 = 0 AND ((GENOTYPE & 1) > 0 OR (GENOTYPE & 4) > 0);