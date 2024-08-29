<h1>** Simple Shell Team Project (By Martain and Mostafa) **</h1>

<h2>---> Project Overview:</h2>

<p>The project was developed in C and adheres to the Shell Betty linter guidelines.</p>
<hr>
<h2>---> General Requirements:</h2>

<ul>
 <li>Compilation: All files must be compiled on Ubuntu 20.04 LTS using gcc with the following flags: <h3>[gcc -Wall -Werror -Wextra -pedantic -std=gnu89]</h3></li>
 <li>File Format: Ensure each file ends with a newline.</li>
 <li>Documentation: A README.md file must be present at the root of the project directory.</li>
 <li>Code Style: Code must be formatted according to Betty style, verified with betty-style.pl and betty-doc.pl.</li>
 <li>Memory Management: The shell should be free of memory leaks.</li>
 <li>Function Limit: Each file should contain no more than five functions.</li>
 <li>Header Files: All header files should use include guards.</li>
</ul>
<hr>
<h2>---> Project Description:</h2>

The hsh project involves creating a simple UNIX command language interpreter that can read and execute commands from a file or standard input.
<hr>
<h2>---> How hsh Works:</h2>

   <ul>
 <li> Prompt and Input: hsh displays a prompt and waits for user input.</li>
 <li> Process Handling: It spawns a child process to manage the command.</li>
 <li> Command Execution: The interpreter checks for built-in commands, aliases in the PATH, and local executable  programs. The command, along with its arguments, replaces the child process.</li>
  <li> Returning to Prompt: After the command execution, the program returns to the parent process and displays the prompt again, ready for a new command.</li>
  <li> Exit Options: To exit, press Ctrl-D or type exit (with or without a status).</li>
  <li> Non-Interactive Mode: The shell also supports non-interactive execution.</li>
  </ul>
