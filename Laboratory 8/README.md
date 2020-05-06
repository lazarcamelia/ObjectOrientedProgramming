Continue your previous assignment, add the following features:


Use exceptions to signal errors:

from the repository

validation errors – validate your entities using Validator classes

create your own exception classes

Store mylist in a CSV(Comma Separated Values) or HTML(Hypertext Markup Language) file, depending on what you get as input for mylistLocation.

the CSV file will contain each entity on one line and the attributes will be separated by comma (,)

in the HTML file you will have a table, in which each row holds the data of one entity. The columns of the table will contain the names of the data attributes. You may find an example of a valid html structure here: https://www.cs.ubbcluj.ro/~iuliana/oop/Laboratories/Lab8-9.pdf

Open mylist with the correct application:

CSV file – with Notepad, Notepad++, Microsoft Excel or OpenOffice Calc

HTML file – with a browser

Create a UML diagram for your entire application. For this, you can use any tool that you like (StarUML is an example of open source software for UML). Do not draw the diagram by hand.

All commands must be in the form:


mylistLocation fullPath (e.g. mylistLocation c:\some really long\path\with spaces\myFileName.XXX) - use the file extension given (XXX) to save in the appropriate format (.txt or .csv or .html)

Example test run: (make sure to create the files at the provided path)


call: fileLocation c:\some really long\path\with spaces\myFileName.txt

call: mylistLocation c:\some really long\path\with spaces\myfile.csv

call: mode A

call: add [valid input]

call: mode B

call: save [id from valid input]


call: exit

Check for [valid input in specified format, in c:\some really long\path\with spaces\myfile.csv]
