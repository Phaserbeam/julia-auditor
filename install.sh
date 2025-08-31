#! /bin/zsh

INSTALL_NVIM=false
while getopts "n" opt; do
  case $opt in
    n) INSTALL_NVIM=true;;
    *) echo "Invalid parameter!"
      exit 1;;
  esac
done


mkdir -p ~/.bin
curl -L -o ~/.bin/julia-auditor https://github.com/Phaserbeam/julia-auditor/releases/latest/download/julia-auditor
chmod +x ~/.bin/julia-auditor
if $INSTALL_NVIM; then
  mkdir -p ~/.config/nvim
  echo "vim.keymap.set('n', '<leader>j', '<cmd>silent ! ~/.bin/julia-auditor %<cr><cmd>edit<cr>',
  { desc = 'Audit file' })" >> ~/.config/nvim/init.lua
fi

echo "Installation complete!"
