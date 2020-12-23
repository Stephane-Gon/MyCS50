SELECT people.name
FROM people
JOIN movies, stars
ON people.id = stars.person_id AND stars.movie_id = movies.id
WHERE year = 2004
GROUP BY people.id
ORDER BY birth DESC


