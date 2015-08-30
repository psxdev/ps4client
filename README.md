PS4CLIENT FOR PC/MAC
=================
 
===================
 What does this do?
===================
 
  ps4client is a host tool providing host fileio system for PS4. It is the same method that we used in ps2dev days, so basically it is the same protocol than ps2link and ps2client have been using since 2003.
  
  It provide all io request operation availables on ps4link library. Now commands are not implemented but it can be easily incorporated.
  
  By now only osx confirmed to run fine. 
  
==================
  How do I use it?
==================

 1) Compile and install ps4client

  You need a gcc installed in your environment 
  
  ```
  make
  make install
  ```
  

 2) Run sample provided in ps4link in your PS4, after run html button is freezed waiting connection from ps4client, so run in your computer;
   
  ```
  psp2client -h ipofyourps4 listen 
  ```
  
 
 You will see logs in terminal window output from your PlayStation 4 using libdebugnet udp log feauture 
 
 Sample is showing only open, read , write and directory entry list operations, you have full io r/w access to your hard disk
 
 ```
 ./ps4client -h yourps4ip listen
 Client connected from xxx.xxx.xxx.xxx port: 49859
  Client reconnected
 sock ps4link_fileio set 86 connected 1
 Waiting for connection
 ps4link initialized and connected from pc/mac
 file open req (host0:/usr/local/ps4dev/test.txt, 0 0)
 Opening /usr/local/ps4dev/test.txt flags 0
 Open return 5
 file open reply received (ret 5)
 file lseek req (fd: 5)
 32 result of lseek 0 offset 2 whence
 ps4link_lseek_file: lseek reply received (ret 32)
 file lseek req (fd: 5)
 0 result of lseek 0 offset 0 whence
 ps4link_lseek_file: lseek reply received (ret 0)
 ps4link_read_file: Reply said there's 32 bytes to read (wanted 32)
 Content of file: Hello world from txt file on pc
 ps4link_file: file close req (fd: 5)
 ps4link_close_file: close reply received (ret 0)
 file open req (host0:/usr/local/ps4dev/test1.txt, 101 0)
 Opening /usr/local/ps4dev/test1.txt flags 601
 Open return 5
 file open reply received (ret 5)
 file write req (fd: 5)
 wrote 21 bytes (asked for 21)
 ps4LinkWrite wrote 21 bytes
 ps4link_file: file close req (fd: 5)
 ps4link_close_file: close reply received (ret 0)
 dir open req (host0:/usr/local/ps4dev)
 dir open reply received (ret 0)
 List entries
 dir read req (0)
 dir read reply received (ret 1)
 . [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 .. [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 .DS_Store [FILE]
 dir read req (0)
 dir read reply received (ret 1)
 bigbsd [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 core [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 doc [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 git [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 mount_bigbsd.sh [FILE]
 dir read req (0)
 dir read reply received (ret 1)
 nuevo [DIR]
 dir read req (0)
 dir read reply received (ret 1)
 test.txt [FILE]
 dir read req (0)
 dir read reply received (ret 1)
 test1.txt [FILE]
 dir read req (0)
 dir read reply received (ret 0)
 ps4link_file: dir close req (fd: 0)
 dir close reply received (ret 0)
 Aborting server_requests_sock
 sceNetAccept error (0x80410104)
 exit thread requests
 closing fileio_sock
 closing server_request_sock
 ```
 
 3) ready to have a lot of fun :P
 
===================
 What next?
===================
  
  Add commands support
  
===========================
  Credits
===========================
  
  Special thanks goes to:
  
  - ps2dev old comrades. 
  - All people collaborating in PS4SDK
  
