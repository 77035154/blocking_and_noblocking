#include <sys/ioctl.h> 
#include <stdio.h>
#include <fcntl.h> 


int main(int argc, char const *argv[])
{          
     
   int i;
   char buf[10] = {0};

  int fd = open(argv[1], O_RDWR);      
  if (fd < 0) 
  {         
    printf("open %s failed!\n", argv[1]);          
    return 0;     
  } 
  printf("open %s success!\n", argv[1]); 
   
  while(buf[0] != 1)
  {
    read(fd, &buf, 1);
  }

  printf("buf: %d\n", buf[0]);

  close(fd); 
      
    return 0; 
} 




// #include <sys/ioctl.h> 
// #include <stdio.h>
// #include <fcntl.h> 
// #include <linux/i2c-dev.h> 
// #include <linux/i2c.h> 

// #define CHIP "/dev/i2c-1" 
// #define CHIP_ADDR 0x20
// int main(int argc, char const *argv[])
// {           
//    int fd = open(argv[1], O_RDWR);      
//    if (fd < 0) 
//    {         
//       printf("open %s failed\n", argv[1]);          
//       goto exit;      
//    }      

//    if (ioctl(fd, I2C_SLAVE_FORCE, CHIP_ADDR) < 0) 
//    {         /* 设置芯片地址 */         
//       printf("oictl:set slave address failed\n");        
//       goto close;      
//     }

//    unsigned char rddata;      
//    unsigned char rdaddr[6][2] = {{0x03, 0}, {0x0D, 0}, {0x0E, 0}, {0x0F, 0}, {0x10, 0}, {0x17, 0}};      将要读取的数据在芯片中的偏移量       
//    unsigned char wrbuf[6][3] = {{0x03, 0, 0xDA}, {0x0D, 0, 0x03}, {0x0E, 0, 0x33}, {0x0F, 0, 0x03}, {0x10, 0, 0x33}, {0x17, 0, 0x9E}};     /* 要写的数据，头两字节为偏移量 */         

//    int i;
//    // for(i=0; i< 6; i++)
//    // {
//    //      printf("write return:%d, write data:%x\n", write(fd, wrbuf[i], 3),      wrbuf[i][2]);     
//    //     sleep(1);     

//    // }
//    for(i=0; i< 6; i++)
//    {
//        printf("write address return: %d\n",write(fd, rdaddr[i], 2));     /* 读取之前首先设置读取的偏移量 */     
//        printf("read data return:%d\n", read(fd, &rddata, 1));    
//        printf("rddata: 0x%x\n", rddata); 
//         sleep(1);   
// }
// close:      
//   close(fd); 
// exit:      
//   return 0; 
// } 
