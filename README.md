This program is a rudimentary simple shell based on bash.

This simple shell language interpreter can execute commands as output reads
based on simple inputs in the shell or a file.

Once compiled, this can be invoked both in an interactive and non interactive way
based on if it is connected to a terminal and the read.

Once opened and interactable, it uses the prompt ^-^

Some basic pulls it can call as example are CD, PWD, OLDPWd, and understanding the path.


-----

Once the shell receives a command, it will be tokenized with " " delimiting it.
The shell will interpet the first word as the command and all remaining as arguments to the input.

If the first character is not a slash or dot, it will attempt to search the bulitins.  If it exists, it will be called.

If the first character, following the above, is also not a builtin, it will surch the path variable for
a directory containing any file marked as executable by that name.

If the first character is a slash or dot, or if either of the above information is completely successful, it will execute the program or function
with the arguments given in a side environ.
