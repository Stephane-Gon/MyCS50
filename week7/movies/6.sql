SELECT avg(rating)
FROM ratings
WHERE (SELECT year FROM movies WHERE id = ratings.movie_id) = 2012