JsonString class is smart enough to recognize if the string passed into its constructor is json string or a normal string. It does thie by looking for double quotes, if none are found, their it assumes that it is a regular string and that the user is using the class to create a json string rather than to parse it.
