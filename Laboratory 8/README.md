For your previous assignment, add the following features:

Replace your DynamicVector template with the STL vector. Use STL algorithms wherever possible in your application (e.g. in your filter function you could use copy_if, count_if). Replace all your for loops either with STL algorithms, or with the ranged-based for loop (C++11).
Create and use a new repository to store your domain data in a text file, but not the "mylist". Do not cache the data in memory, all operations will only use files. If there is no file at the provided location create one. For this feature, use the iostream library. Create insertion and extraction operators for your entities and use these when reading/writing to files or console.
All the functions in your application must be specified and tested. Using the OpenCppCoverage tool, make sure you have at least 99% coverage for all your modules, except for the UI. For Linux, you may use any appropriate tool you find.
All commands must be in the form:

fileLocation fullPath (e.g. fileLocation c:\some really long\path\with spaces\myFileName.txt) - the commands must use this location from now on
All previous commands must work with the given file (add, update, delete, etc.)
Example test run:

call: fileLocation c:\some really long\path\with spaces\myFileName.txt

call: mode A

call: add [valid input]

call: list

Check for [valid input in any format, in c:\some really long\path\with spaces\myFileName.txt]

Note:The server will call list just in case you use that as a trigger to save, but will only test the file contents for correctness.

