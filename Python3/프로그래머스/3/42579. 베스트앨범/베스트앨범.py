def solution(genres, plays):
    answer = []
    dic={key:0 for key in genres}
    
    for genre, play in zip(genres, plays):
        dic[genre] += play
    
    genres_sort = list(dict(sorted(dic.items(), key=lambda items:items[1], reverse=True)).keys())
    
    dic2={key:[] for key in genres_sort}
    
    for i, genre in enumerate(genres):
        dic2[genre].append(i)
    
    for genre in genres_sort:
        dic2[genre] = list(sorted(dic2[genre], key=lambda gen: plays[gen], reverse=True))
    res = []  
    for genre, genre_lst in dic2.items():
        if len(genre_lst) >= 2:
            res.extend(genre_lst[:2])
        else:
            res.extend(genre_lst)
    

    return res