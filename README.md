# Auditor
Auditor is a simple program that scans a file (presumably Julia) and appends code to print all variables declared. A video below demos how to use Auditor via the terminal and Neovim: 

https://github.com/user-attachments/assets/536d1013-e86a-4466-a897-0a8a53935eee

## Installation:
You can either directly integrate Auditor into Neovim or simply download the binary and integrate into an IDE of your choosing/use it from the terminal.

**Installation to Neovim:**
Installing this on Neovim is pretty easy, you just have to run the command below which installs the binary to ~/.bin/ and appends a keybind, <leader>j, to Neovim's init.lua.  
```
bash <(curl -s https://raw.githubusercontent.com/Phaserbeam/julia-auditor/refs/heads/main/install.sh)
```
The above command assumes that you're config is located in ~/.config/ and will create it if it doesn't exist, however in the case in which your config is located elsewhere simply copy and paste the following piece of code into your init.lua:
```
vim.keymap.set('n', '<leader>j', '<cmd>silent ! ~/.bin/auditor %<cr><cmd>edit<cr>',
  { desc = 'Audit file' })

```

**Using with terminal**
To install for terminal (or other) use, simply run the below command which installs the binary to ~/.bin.
```
bash <(curl -s https://raw.githubusercontent.com/Phaserbeam/julia-auditor/refs/heads/main/install.sh) -n
```
If ~/.bin isn't in your path add the following line to your .bashrc/.zshrc:
```
export PATH=~/.bin:$PATH
```
I use Neovim, but I'm sure you can figure out how to add a similar functionality to your favorite IDE.

## Known Issues
It should be noted that Auditor is pretty dumb right now, and thus it really only works in single function files.... if someone does want this I'm happy to add it but otherwise one function files it is.

## Contributing
Feel free to open a pull request or issue. Build process is nonexistent :)
If you have any questions feel free to reach out!
