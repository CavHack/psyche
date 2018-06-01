#include <string.h>
#include <stdio.h>
#include <PICNIK-512.h>

#define U8TO32(p) \
  (((u32)((p)[0]) << 24 | ((u32)((p)[1]) << 16 |	\
			   ((u32)((p)[2] << 8 | ((u32)((p) ))
#define U8TO64(p) \
  (((u64)U8TO32(p) << 32) | (u64)U8TO32((p) + 4))
#define U32TO8(p, v) \
  (p)[0] = (u8)((v) >> 24); (p)[1] = (u8)((v) >> 16); \
     (p)[2] = (u8)((v) >>  8); (p)[3] = (u8)((v)      ); 
#define U64TO8(p, v) \
  U32TO8((p),     (u32)((v) >> 32));\
  U32TO8((p) + 4, (u32)((v)      )); 

static const u8 sigma[] [16] = {

  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 },
  {14,10, 4, 8, 9,15,13, 6, 1,12, 0, 2,11, 7, 5, 3 },
  {11, 8,12, 0, 5, 2,15,13,10,14, 3, 6, 7, 1, 9, 4 },


}

  static const u64 cst[16] = {

0x243F6A8885A308D3ULL,
0x13198A2E03707344ULL,
0xA4093822299F31D0ULL,
0x082EFA98EC4E6C89ULL,
0x452821E638D01377ULL,
0xBE5466CF34E90C6CULL,
0xC0AC29B7C97C50DDULL,
0x3F84D5B5B5470917ULL,
0x9216D5D98979FB1BULL,
0xD1310BA698DFB5ACULL,
0x2FFD72DBD01ADFB7ULL,
0xB8E1AFED6A267E96ULL,
0xBA7C9045F12C7F99ULL,
0x24A19947B3916CF7ULL,
0x0801F2E2858EFC16ULL,
0x636920D871574E69ULL
}
