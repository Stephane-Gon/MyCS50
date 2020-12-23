SELECT movies.title, ratings.rating
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
where year = 2010 AND rating >= 0 AND rating <= 10
ORDER BY rating DESC, title ASC