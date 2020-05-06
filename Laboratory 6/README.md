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
