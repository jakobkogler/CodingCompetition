set nocompatible    " required
filetype off        " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

" Add all your plugins here (note older versions of Vundle used Bundle instead of Plugin)


" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

" Folding code
Plugin 'tmhedberg/SimpylFold'
let g:SimpylFold_docstring_preview=1

" configure expanding of tabs for various file types
au BufRead,BufNewFile *.py set expandtab
au BufRead,BufNewFile *.c set noexpandtab
au BufRead,BufNewFile *.h set noexpandtab
au BufRead,BufNewFile Makefile* set noexpandtab

" --------------------------------------------------------------------------------
" configure editor with tabs and nice stuff...
" --------------------------------------------------------------------------------
set expandtab           " enter spaces when tab is pressed
set textwidth=120       " break lines when line length increases
set tabstop=4           " use 4 spaces to represent tab
set softtabstop=4
set shiftwidth=4        " number of spaces to use for auto indent
set autoindent          " copy indent from current line when starting a new line
set fileformat=unix
set encoding=utf-8

" make backspaces more powerfull
set backspace=indent,eol,start

set ruler                           " show line and column number
syntax on   			" syntax highlighting
set showcmd 			" show (partial) command in status line

" run python
" nnoremap <silent> <F5> :!clear;python3 %<CR>
autocmd filetype python nnoremap <F5> :w <bar> exec '!python3 '.shellescape('%')<CR>
autocmd filetype c nnoremap <F5> :w <bar> exec '!gcc -g -std=c++11 '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
autocmd filetype cpp nnoremap <F5> :w <bar> exec '!g++ -g -std=c++11 '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>

" swich splits
nnoremap <C-L> <C-W><C-K>
nnoremap <C-A> <C-W><C-J>
nnoremap <C-I> <C-W><C-H>
nnoremap <C-E> <C-W><C-L>

" save
noremap <silent> <C-S>          :update<CR>
vnoremap <silent> <C-S>         <C-C>:update<CR>
inoremap <silent> <C-S>         <C-O>:update<CR>

" enable folding
set foldmethod=indent
set foldlevel=99
nnoremap <space> za

" auto-indentation
Plugin 'vim-scripts/indentpython.vim'

" youcompleteme
Bundle 'Valloric/YouCompleteMe'
let g:ycm_autoclose_preview_window_after_completion=1
let g:ycm_add_preview_to_completeopt=0
set completeopt-=preview
map <C-G>  :YcmCompleter GoToDefinitionElseDeclaration<CR>

" Syntax
Plugin 'scrooloose/syntastic'
Plugin 'nvie/vim-flake8'

let python_highlight_all=1
syntax on

" Color
Plugin 'jnurmine/Zenburn'
Plugin 'altercation/vim-colors-solarized'

"if has('gui_running')
"    set background=dark
"    colorscheme solarized
"else
"    colorscheme zenburn
"endif

call togglebg#map("<F6>")

" FileBrowsing
Plugin 'scrooloose/nerdtree'
let NERDTreeIgnore=['\.pyc$', '\~$'] "ignore files in NERDTree
map <C-n> :NERDTreeToggle<CR>

" Searching
Plugin 'kien/ctrlp.vim'

set nu

" Git
Plugin 'tpope/vim-fugitive'

Plugin 'Lokaltog/powerline', {'rtp': 'powerline/bindings/vim/'}


let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/.ycm_extra_conf.py"

Plugin 'SirVer/ultisnips'
let g:UltiSnipsExpandTrigger="<C-j>"
let g:UltiSnipsJumpForwardTrigger="<C-j>"
let g:UltiSnipsJumpBackwardTrigger="<C-z>"
let g:UltiSnipsSnippetsDir="~/.vim/snippets"
