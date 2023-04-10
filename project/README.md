# Reading Record
#### Video Demo:  <URL https://youtu.be/fDrUdRu93RA>
#### Description:
    This is a reading record web application. I developed this application to
motivate those who are reluctant to read piled-up books like me by visualizing their achievements.
This application allows you to record title, author, published year, rating, and a brief note or review.
Moreover, you can edit record by simply clicking edit button in the record row shown on the main page.
In case you mistakenly add some books to the record, it is also allowed to you to delete books from them
by the similar way to that of edit function.

    This application consists of two program files, app.py and helpers.py as well as database file,
templates folder, static folder. Templates folder contains html files for each page. Using jinja templates, html files are hopefully neat.
Static folder include css file to decorate html files in templates folder. Finally, database file has three tables, users, users_books,
books. Each column on users_books table has on cascade delete option to make it easy to delete books from users' reading record.

    I am going to explain all the functions in app.py. Index function renders main page which shows reading record to users from the data
extracted from the database. With add function, users can add some books to the record. This function confirms all the input fields are completed
and remove extra spaces at the beginning and an the end of the input. Finally, the function will execute SQL query to record the data to database.
Delete function will execute query getting a url parameter which include book id. With this id, the function can deletethe exact row from the record.
Also, users are able to edit record with edit function. This function force users to complete all the input fields just like add function.
Login, logout and register functions are almost the same as I programmed in a week 9 assignment, finanction. Finally,
search function allows users to find records from fragmented memory. The most complecated part of this application is maybe this search method.
I had to edit query words to make it possible to extract partially matched rows from tables of the database.
Using slice and concatination operator, I implemented that function.

    Moreover, I paid attention to security. For fear that some bad users meight attempt to send form with invalid input by editing html
with developper tools, I made the program confirm all the inputs are what are expected which made this more secure.