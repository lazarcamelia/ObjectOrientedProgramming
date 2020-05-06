EC-PD morgue administrator mode: The program will have a database, which lists victim files stored in the morgue's backroom cabinets. 
The guys in the forensics department must be able to update the database, meaning: add a new victim file (you grit your teeth at the 
prospect), delete a victim file (in the event that a file is proven to be unconnected to the Slayer's rampage or is moved to another 
department for research) and update the information of a victim file. Each victim file has a name, a place of origin, an age and a 
photograph taken post-autopsy. The photo is memorized as a link to Tillyard's personal computer, which also keeps track of the morgue files.
The EC-PD administrators will also have the option to see all victim files that have been stored. Make sure to validate inputs, users will 
be human after all. Create your own DynamicVector, allocate resources only as needed, while also unit testing everything except the UI.

All commands must be in the form:

mode X (e.g. mode A)
add name, placeOfOrigin, age, photograph (e.g. add Jane Doe, unknown, 27, jd42185.jpg)
update name, newPlaceOfOrigin, newAge, newPhotograph (e.g. update Jane Doe, Hertfordshire, 28, jd42329.jpg)
delete name (e.g. delete Jane Doe)
list
exit

EC-PD morgue assistant mode: an assistant can access the program and choose one or more victim files to mark as unconnected to the string 
of murders or to move to other departments for research, in the event of new findings. The program will allow the assistant to:

1. See the victim files in the database, one by one. When the assistant chooses this option, the data of the first victim (place of origin, 
name, age) is displayed, along with its post-autopsy photograph.

2. Choose to transfer the file to another department, in which case the victim file is added to the assistant's “to be transferred” list.

3. Choose not to transfer the victim file and to continue to the next. In this case, the information corresponding to the next victim file
is shown and the assistant is again offered the possibility to transfer it. This can continue as long as the assistant wants, as when 
arriving to the end of the list, if the assistant chooses next, the application will again show the first victim file.

4. See all victim files of a given place of origin, having an age less than a given number. If the place of origin is empty, then all 
victim files will be considered. The same options (a, b and c) apply in this case.

5. See the list of victim files selected to be removed as irrelevant or transferred to other departments for additional research.

The DinamicVector that you created should now use template, now that you have access to them. All commands must take the form:

next
save name (e.g. save Jane Doe)
list placeOfOrigin, age (e.g. list Hertfordshire, 28)
mylist
