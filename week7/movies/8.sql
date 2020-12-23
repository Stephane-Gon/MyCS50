SELECT people.name
FROM people
JOIN movies, stars
on people.id = stars.person_id AND movies.id = movie_id
WHERE title = "Toy Story"