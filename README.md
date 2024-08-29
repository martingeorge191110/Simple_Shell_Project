<h1 align="center">** Simple Shell Team Project **</h1>
<h3 align="center">By Martain and Mostafa</h3>

---

<h2>📝 Project Overview</h2>
<p>
  The project is developed in C and follows the <b>Shell Betty linter</b> guidelines to ensure code consistency and quality.
</p>

---

<h2>✅ General Requirements</h2>
<ul>
  <li><strong>Compilation:</strong> All files are compiled on <b>Ubuntu 20.04 LTS</b> using <code>gcc</code> with the following flags: <h3><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89</code></h3></li>
  <li><strong>File Format:</strong> Each file must end with a newline.</li>
  <li><strong>Documentation:</strong> A <code>README.md</code> file must be present at the root of the project directory.</li>
  <li><strong>Code Style:</strong> Code must be formatted according to the <b>Betty style</b>, verified with <code>betty-style.pl</code> and <code>betty-doc.pl</code>.</li>
  <li><strong>Memory Management:</strong> The shell should be free of memory leaks.</li>
  <li><strong>Function Limit:</strong> Each file should contain no more than five functions.</li>
  <li><strong>Header Files:</strong> All header files should use include guards.</li>
</ul>

---

<h2>📄 Project Description</h2>
<p>
  The <b>hsh</b> project involves creating a simple UNIX command language interpreter that can read and execute commands from a file or standard input.
</p>

---

<h2>⚙️ How hsh Works</h2>
<ul>
  <li><strong>Prompt and Input:</strong> <code>hsh</code> displays a prompt and waits for user input.</li>
  <li><strong>Process Handling:</strong> It spawns a child process to manage the command execution.</li>
  <li><strong>Command Execution:</strong> The interpreter checks for <b>built-in commands</b>, aliases in the <b>PATH</b>, and local executable programs. The command, along with its arguments, replaces the child process.</li>
  <li><strong>Returning to Prompt:</strong> After the command execution, the program returns to the parent process and displays the prompt again, ready for a new command.</li>
  <li><strong>Exit Options:</strong> To exit, press <code>Ctrl-D</code> or type <code>exit</code> (with or without a status).</li>
  <li><strong>Non-Interactive Mode:</strong> The shell also supports non-interactive execution.</li>
</ul>

---

<p>
  <b>Note:</b> This project is an updated version of the original Simple Shell project. You can find the original repository here: <a href="https://github.com/M-sharkawy/simple_shell">Simple Shell Project</a>.
</p>