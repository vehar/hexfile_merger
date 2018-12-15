/**
   \file hexfile.h
   
   \author G. Icking-Konert
   \date 2018-12-14
   \version 0.2
   
   \brief declaration of routines for HEX, S19 and table files
   
   declaration of routines for importing and exporting Motorola S19 and Intel HEX files, 
   as well as plain ASCII tables.  
   (format descriptions under http://en.wikipedia.org/wiki/SREC_(file_format) or
   http://www.keil.com/support/docs/1584.htm). 
*/

// for including file only once
#ifndef _HEXFILE_H_
#define _HEXFILE_H_

/// buffer size [B] for files
#define  LENFILEBUF   10*1024*1024

/// buffer size [B] for memory image
#define  LENIMAGEBUF  10*1024*1024


// read next line from RAM buffer
char  *get_line(char **buf, char *line);

// read file into memory buffer
void  load_file(const char *filename, char *fileBuf, uint32_t *lenFileBuf, uint8_t verbose);

// convert Motorola s19 format in memory buffer to memory image
void  convert_s19(char *fileBuf, uint32_t lenFileBuf, uint16_t *imageBuf, uint32_t *addrStart, uint32_t *addrStop, uint8_t verbose);

// convert Intel hex format in memory buffer to memory image
void  convert_ihx(char *fileBuf, uint32_t lenFileBuf, uint16_t *imageBuf, uint32_t *addrStart, uint32_t *addrStop, uint8_t verbose);

// convert plain text table (hex addr / data) in memory buffer to memory image
void  convert_txt(char *fileBuf, uint32_t lenFileBuf, uint16_t *imageBuf, uint32_t *addrStart, uint32_t *addrStop, uint8_t verbose);

// convert binary data in memory buffer to memory image
void  convert_bin(char *fileBuf, uint32_t lenFileBuf, uint16_t *imageBuf, uint32_t addrStart, uint32_t *addrStop, uint8_t verbose);


// export RAM image to file in Motorola s19 format
void  export_s19(char *filename, uint16_t *imageBuf, uint32_t addrStart, uint32_t addrStop, uint8_t verbose);

// export RAM image to file with plain text table (hex addr / data)
void  export_txt(char *filename, uint16_t *imageBuf, uint32_t addrStart, uint32_t addrStop, uint8_t verbose);

// export RAM image to binary file (w/o address)
void  export_bin(char *filename, uint16_t *imageBuf, uint32_t addrStart, uint32_t addrStop, uint8_t verbose);

// print RAM image to console
void  print_console(uint16_t *imageBuf, uint32_t addrStart, uint32_t addrStop, uint8_t verbose);

#endif // _HEXFILE_H_
