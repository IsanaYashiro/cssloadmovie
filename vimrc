set nocompatible

syntax on

filetype on

set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

" github 仓库中的插件 "
"

Plugin 'VundleVim/Vundle.vim'

Plugin 'vim-airline/vim-airline'

"vim-airline配置:优化vim界面"

"let g:airline#extensions#tabline#enabled = 1

" airline设置

" 显示颜色

set t_Co=256

set laststatus=2

" 使用powerline打过补丁的字体

let g:airline_powerline_fonts = 1

" 开启tabline

let g:airline#extensions#tabline#enabled = 1

" tabline中当前buffer两端的分隔字符

let g:airline#extensions#tabline#left_sep = ' '

" tabline中未激活buffer两端的分隔字符

let g:airline#extensions#tabline#left_alt_sep = ' '

" tabline中buffer显示编号

let g:airline#extensions#tabline#buffer_nr_show = 1

" 映射切换buffer的键位

nnoremap [b :bp<CR>

nnoremap ]b :bn<CR>

" 映射<leader>num到num buffer

map <leader>1 :b 1<CR>

map <leader>2 :b 2<CR>

map <leader>3 :b 3<CR>

map <leader>4 :b 4<CR>

map <leader>5 :b 5<CR>

map <leader>6 :b 6<CR>

map <leader>7 :b 7<CR>

map <leader>8 :b 8<CR>

map <leader>9 :b 9<CR>

 

Plugin 'The-NERD-tree'

"NERDTree 配置:F2快捷键显示当前目录树

map <F2> :NERDTreeToggle<CR>

let NERDTreeWinSize=25 



Plugin 'indentLine.vim'

Plugin 'delimitMate.vim'



" 非 github 仓库的插件"

" Plugin 'git://git.wincent.com/command-t.git'

" 本地仓库的插件 "

 

call vundle#end()

 

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"""""新文件标题

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"新建.c,.h,.sh,.java文件，自动插入文件头 

autocmd BufNewFile *.cpp,*.c,*.sh exec ":call SetTitle()" 

""定义函数SetTitle，自动插入文件头 

func SetTitle() 

	if &filetype == 'cpp'  

		call setline(1, "/*****************************************************")

		call append(line("."), "	> File Name: ".expand("%"))

		call append(line(".")+1, "	> Author: hshuang")

		call append(line(".")+2, "	> Created Time: ".strftime("%c"))

		call append(line(".")+3, " ****************************************************/")
		
		call append(line(".")+4, "#include<iostream>")

		call append(line(".")+5, "int main()")

		call append(line(".")+6, "{")

    	call append(line(".")+7, "	return 0;")
		
		call append(line(".")+8, "}")

		call append(line(".")+9, "")

	endif

	if &filetype == 'c'

		call setline(1, "/*****************************************************")

		call append(line("."), "	> File Name: ".expand("%"))

		call append(line(".")+1, "	> Author: hshuang")

		call append(line(".")+2, "	> Created Time: ".strftime("%c"))

		call append(line(".")+3, " ****************************************************/")
		
		call append(line(".")+4, "#include<stdio.h>")

		call append(line(".")+5, "int main()")

		call append(line(".")+6, "{")

		call append(line(".")+7, "	return 0;")

		call append(line(".")+8, "}")

		call append(line(".")+9, "")

	endif

	"新建文件后，自动定位到文件末尾

	autocmd BufNewFile * normal G

endfunc 

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"键盘命令

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 

nmap <leader>w :w!<cr>

nmap <leader>f :find<cr>

 

" 映射全选+复制 ctrl+a

map <C-A> ggVGY

map! <C-A> <Esc>ggVGY

map <F12> gg=G

" 选中状态下 Ctrl+c 复制

vmap <C-c> "+y


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

""实用设置

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 设置当文件被改动时自动载入

set autoread

" quickfix模式

autocmd FileType c,cpp map <buffer> <leader><space> :w<cr>:make<cr>

"代码补全 

set completeopt=preview,menu 

"允许插件  

filetype plugin on

"共享剪贴板  

set clipboard=unnamed 

"从不备份  

set nobackup

"make 运行

:set makeprg=g++\ -Wall\ \ %

"自动保存

set autowrite

set ruler                   " 打开状态栏标尺

set cursorline              " 突出显示当前行

set magic                   " 设置魔术

set guioptions-=T           " 隐藏工具栏

set guioptions-=m           " 隐藏菜单栏

"set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\

" 设置在状态行显示的信息

set foldcolumn=0

set foldmethod=indent 

set foldlevel=3 

set foldenable              " 开始折叠

" 不要使用vi的键盘模式，而是vim自己的

set nocompatible

" 语法高亮

set syntax=on

" 去掉输入错误的提示声音

set noeb

" 在处理未保存或只读文件的时候，弹出确认

set confirm

" 自动缩进

set autoindent

set cindent

" Tab键的宽度

set tabstop=4

" 统一缩进为4

set softtabstop=4

set shiftwidth=4

" 不要用空格代替制表符

set noexpandtab

" 在行和段开始处使用制表符

set smarttab

" 显示行号

set number

" 历史记录数

set history=1000

"禁止生成临时文件

set nobackup

set noswapfile

"搜索忽略大小写

set ignorecase

"搜索逐字符高亮

set hlsearch

set incsearch

"行内替换

set gdefault

"编码设置

set enc=utf-8

set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936

"语言设置

set langmenu=zh_CN.UTF-8

set helplang=cn

" 我的状态行显示的内容（包括文件类型和解码）

set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}

set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]

" 总是显示状态行

set laststatus=2

" 命令行（在状态行下）的高度，默认为1，这里是2

set cmdheight=2

" 侦测文件类型

filetype on

" 载入文件类型插件

filetype plugin on

" 为特定文件类型载入相关缩进文件

filetype indent on

" 保存全局变量

set viminfo+=!

" 带有如下符号的单词不要被换行分割

set iskeyword+=_,$,@,%,#,-

" 字符间插入的像素行数目

set linespace=0

" 增强模式中的命令行自动完成操作

set wildmenu

" 使回格键（backspace）正常处理indent, eol, start等

set backspace=2

" 允许backspace和光标键跨越行边界

set whichwrap+=<,>,h,l

" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）

set mouse=a

set selection=exclusive

set selectmode=mouse,key

" 通过使用: commands命令，告诉我们文件的哪一行被改变过

set report=0

" 在被分割的窗口间显示空白，便于阅读

set fillchars=vert:\ ,stl:\ ,stlnc:\

" 高亮显示匹配的括号

set showmatch

" 匹配括号高亮的时间（单位是十分之一秒）

set matchtime=1

" 光标移动到buffer的顶部和底部时保持3行距离

set scrolloff=3

" 为C程序提供自动缩进

set smartindent

" 高亮显示普通txt文件（需要txt.vim脚本）

 au BufRead,BufNewFile *  setfiletype txt

"自动补全

:inoremap ( ()<ESC>i

:inoremap ) <c-r>=ClosePair(')')<CR>

":inoremap { {<CR>}<ESC>O

":inoremap } <c-r>=ClosePair('}')<CR>

:inoremap [ []<ESC>i

:inoremap ] <c-r>=ClosePair(']')<CR>

:inoremap " ""<ESC>i

:inoremap ' ''<ESC>i

function! ClosePair(char)

	if getline('.')[col('.') - 1] == a:char

		return "\<Right>"

	else

		return a:char

	endif

endfunction

filetype plugin indent on 

"打开文件类型检测, 加了这句才可以用智能补全

set completeopt=longest,menu

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

