all:ser

GDB=-g //����ʡ�Բ��� -g  ����������Ϣ

ser:ser.o  socket.o  thread.o
	gcc -o ser ser.o socket.o thread.o -lpthread

ser.o:ser.c
	gcc -c ser.c  ${GDB}

socket.o:socket.c
	gcc -c socket.c  ${GDB}

thread.o:thread.c
	gcc -c thread.c  ${GDB}

clean:
    rm -rf *.o ser