SELECT people.name
FROM people
JOIN directors, ratings
ON people.id = directors.person_id AND directors.movie_id = ratings.movie_id
WHERE rating >= 9.0
GROUP BY people.id