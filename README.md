# julia-var-logger
(NOTE: THIS IS ONLY FOR SINGLE FUNCTION FILES)

This program can take as input a file, to append logging material. By default, it scans the file for all declared variables-- note that there must be a space before and after equal signs -- and then appends println() at the bottom of the file. The program will create an exit-code, which just tells the program what to cut so that it doesn't create a bunch of unnecessary  println statements. For first time use, make sure that your file has no end at the bottom. In order to use this, call the program and add your file as an argument (i.e. ./jvl foo.jl). Note that having 'end' at the end of your file, without  will mess with it. It is, however, recommended to add this to a vim config so that you can easily run it.
Running the below command will add the program to ~/.bin and append a vim keybind ( space + j ) to your ~/.config/nvim/init.lua. 
```
curl | bash
```
Feel free to add requests and stuff, I'm pretty happy to add whatever mostly. One thing to note is that this is made for single function files, so if you have multiple functions in one file you're going to run into some issues. You can fix it or ask me to :)
