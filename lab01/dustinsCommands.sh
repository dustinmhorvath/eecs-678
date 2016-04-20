sed '1,12!d' simple.c | tee a.c b.c c.c

sed -e 's/^[ \t]*//' a.c

# in vim
1.
# copy 12 lines to file
#  apparently vim doesn't support copy to multiple files?
:1,12w a.c
:1,12w b.c
:1,12w c.c

2.
# vim supports splits with Ctrl-w
Ctrl-w v #split vertical
:e a.c #to open a new file in the buffer
Ctrl-w w # switches between windows 
:wq #close the current pane and save

3.
# search with tags
ctags -R # while in directory to source
Ctrl-] # while in vim command and selecting command in question


4.

5.
# This is easy enough to do in vim, and ports like normal to sed in bash
:s /Bill Self/basketball genius Bill Self/gi

# Format to fit 80 lines
gqG # should fix everything






Change comment into block:
1. Go to line
2. type 'gq' then hit hjkl*

Reformat block:
1. use v to switch to visual mode
2. highlight block
3. type '==' to format correctly

Uncomment block:
1. ma to mark beginning
2. mb to mark end
3. :'b, 'a s /^\/\/// # it didn't like this because the range was in reverse
# Seems more easily accomplished with sed, something like "sed -i 's:^[ ]*//::' filename" would, 
# uncomment everything, because it works from anywhere and doesn't require a user-run program
# It could be changed pretty easily to use line numbers

Uncommented "print_this_many" function manually
also,
`sed -i 's://print_this_many(:print_this_many(:' simple.c`
worked just fine to uncomment that as well.
