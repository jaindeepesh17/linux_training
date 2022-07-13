#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
int main()
 {
     unsigned int res;
     char buf[60];
     int nread,i=0,j,count=0;
     int fbfd = 0;
     int ibfd = 0;
     struct fb_var_screeninfo vinfo;// variable screen info
     struct fb_fix_screeninfo finfo;// fix screen info
     long int screensize = 0;
     unsigned int *fbp = 0;

     // Open the file for reading and writing
     fbfd = open("/dev/fb0", O_RDWR);
     if (fbfd == -1) {
         perror("Error: cannot open framebuffer device");
         exit(1);
     }
     printf("The framebuffer device was opened successfully.\n");


     // Get variable screen information
     if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
         perror("Error reading variable information");
         exit(3);
     }

     printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

     // Get fixed screen information
     if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
         perror("Error reading variable information");
         exit(3);
     }

	int size = finfo.line_length * vinfo.yres;
	printf("size %d\n",size);
     // Figure out the size of the screen in bytes
     screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	printf("screen size %ld\n",screensize);

     ibfd = open("/home/im-rt-lp-1134/Downloads/KM_LOGO_800x600_32.bmp", O_RDONLY);
     if (ibfd == -1) {
         perror("Error: cannot open framebuffer device");
         exit(1);
     }
     printf("The image was opened successfully.\n");

     nread = read( ibfd, buf , 60);

     int x_res = buf[18] | buf[19]<<8 | buf[20]<<16 | buf[21]<<24;
	printf("%d\n",x_res);

     int y_res = buf[22] | buf[23]<<8 | buf[24]<<16 | buf[25]<<24;
	printf("%d\n",y_res);

     int bpp = buf[28]| buf[29]<<8;
	printf("%d\n",bpp);

     int imagesize = x_res * y_res * bpp / 8;
	printf("image size %d\n",imagesize);

      if(imagesize >= screensize)
	{
	printf("bmp resolution is more than screensize\n");
	return -1;
	}


     // Map the device to memory
     fbp = (unsigned int *) mmap (0, size , PROT_READ | PROT_WRITE, MAP_SHARED,
                        fbfd, 0);

     if ((int)fbp == -1) {
         perror("Error: failed to map framebuffer device to memory");
         exit(4);
     }
     printf("The framebuffer device was mapped to memory successfully.\n");

     lseek(ibfd, 54, SEEK_SET);
	int line_length = finfo.line_length/4;
	for(i = y_res - 1;i >= 0;i--)
	{
		for(j = 0;j < x_res;j++)
		{
			read(ibfd, &res, 4);
			fbp[i * line_length + j] = res;
		}
	}
	munmap(fbp, screensize);
	close(fbfd);
	close(ibfd);
//	munmap(fbp, screensize);
}
