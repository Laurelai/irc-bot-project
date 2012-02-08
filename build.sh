MOWGLI_CFLAGS="-I/usr/include/libmowgli-2"
MOWGLI_LIBS="-lmowgli-2"

SOURCES="bot.c parse.c"
OBJECTS=""
for file in $SOURCES; do
	echo "Compiling $file..."
	gcc -c -o $file.o $file ${MOWGLI_CFLAGS}
	OBJECTS="$OBJECTS $file.o"
done

echo "Linking..."
gcc -o bot $OBJECTS ${MOWGLI_LIBS}

echo "Everything seems OK!"
