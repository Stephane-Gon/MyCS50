SELECT movies.title
FROM movies
JOIN stars, people, ratings
ON movies.id = stars.movie_id AND movies.id = ratings.movie_id AND stars.person_id = people.id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5