:
cwd=`pwd`
proj=$1
shift


echo $cwd

CFLAG="-Wall -Wextra -Werror -ansi"
CC="gcc"


if [ -f Makefile ]; then
  mv Makefile Makfile_`date +"%s"`
fi

touch Makefile

printf "CC=$CC\n" >> Makefile
printf "CFLAG=$CFLAG\n" >> Makefile
printf "OBJS=obj/*.o\n" >> Makefile
printf "\n\nall: $proj\n\n" >> Makefile

printf "$proj : \$(OBJS)\n" >> Makefile
printf "\t\$(CC) -o $proj \$(OBJS)\n\n" >> Makefile



mkdir $cwd/src
mkdir $cwd/include

for i in $@; do
  if [ -f $i ]; then
    ext=`echo $i | rev | cut -f1 -d"." | rev`
    fnm=`echo $i | cut -f1 -d"."`
    case "$ext" in
      c)
        printf "obj/$fnm.o: src/../include/*.h\n" >> Makefile
        printf "\t\$(CC) -o obj/$fnm.o -c \$(CFLAGS) src/$fnm.c\n\n" >> Makefile
        mv $cwd/$i $cwd/src/$i
        ;;
      h)
        mv $cwd/$i $cwd/include/$i
        ;;
    esac
  fi
done

printf "clean:\n" >> Makefile
printf "\trm -f obj/*.o\n" >> Makefile

printf "\nfclean:\n" >> Makefile
printf "\trm -f $proj\n" >> Makefile

printf "\nre:\t\tfclean all\n\n" >> Makefile
printf ".PHONY: all clean fclean re\n" >> Makefile
