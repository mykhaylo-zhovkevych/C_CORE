- Scan all the executables on the os for virus
    - make a list of all files
    - selects the executables elf binaries
    - opening the files, at a time, and look for virus signatures
        birdflu - \x90\xab\x05
    -when virus detected:
            - alert the user
            - give options (delete the files, to clean file [if possible], reboot into safe mode then delete)
  - Prevent the user from executing a new executable file before it has been cleared by the anti virus software
  - will intercept the exec() call, scan the file (if i has not already been), and then execute the file
  - LKM Loadable Kernal Module
  execve() 
