#ifndef __MDFN_ENDIAN_H
#define __MDFN_ENDIAN_H

#include <stdio.h>
#include <stdint.h>

#ifdef MSB_FIRST
   #ifndef le32toh
      #define le32toh(l)      ((((l)>>24) & 0xff) | (((l)>>8) & 0xff00) \
                            | (((l)<<8) & 0xff0000) | (((l)<<24) & 0xff000000))
   #endif

   #ifndef le16toh
      #define le16toh(l)      ((((l)>>8) & 0xff) | (((l)<<8) & 0xff00))
   #endif

#else
   #ifndef le32toh
      #define le32toh(l)      (l)
   #endif

   #ifndef le16toh
      #define le16toh(l)      (l)
   #endif
#endif

#ifndef htole32
   #define htole32 le32toh
#endif

#ifndef htole16
   #define htole16 le16toh
#endif

int write16le(uint16 b, FILE *fp);
int write32le(uint32 b, FILE *fp);
int read32le(uint32 *Bufo, FILE *fp);

void Endian_A16_Swap(void *src, uint32 nelements);
void Endian_A32_Swap(void *src, uint32 nelements);
void Endian_A64_Swap(void *src, uint32 nelements);

void Endian_A16_LE_to_NE(void *src, uint32 nelements);
void Endian_A16_BE_to_NE(void *src, uint32 nelements);
void Endian_A32_LE_to_NE(void *src, uint32 nelements);
void Endian_A64_LE_to_NE(void *src, uint32 nelements);

void FlipByteOrder(uint8 *src, uint32 count);


// The following functions can encode/decode to unaligned addresses.

static INLINE void MDFN_en16lsb(uint8 *buf, uint16 morp)
{
  buf[0] = morp >> 0;
  buf[1] = morp >> 8;
}

static INLINE void MDFN_en24lsb(uint8 *buf, uint32 morp)
{
  buf[0] = morp >> 0;
  buf[1] = morp >> 8;
  buf[2] = morp >> 16;
}

static INLINE void MDFN_en32lsb(uint8 *buf, uint32 morp)
{
  buf[0] = morp >> 0;
  buf[1] = morp >> 8;
  buf[2] = morp >> 16;
  buf[3] = morp >> 24;
}

static INLINE void MDFN_en64lsb(uint8 *buf, uint64 morp)
{
  buf[0] = morp >> 0;
  buf[1] = morp >> 8;
  buf[2] = morp >> 16;
  buf[3] = morp >> 24;
  buf[4] = morp >> 32;
  buf[5] = morp >> 40;
  buf[6] = morp >> 48;
  buf[7] = morp >> 56;
}

static INLINE void MDFN_en16msb(uint8 *buf, uint16 morp)
{
  buf[0] = morp >> 8;
  buf[1] = morp >> 0;
}

static INLINE void MDFN_en24msb(uint8 *buf, uint32 morp)
{
  buf[0] = morp >> 16;
  buf[1] = morp >> 8;
  buf[2] = morp >> 0;
}

static INLINE void MDFN_en32msb(uint8 *buf, uint32 morp)
{
  buf[0] = morp >> 24;
  buf[1] = morp >> 16;
  buf[2] = morp >> 8;
  buf[3] = morp >> 0;
}

static INLINE void MDFN_en64msb(uint8 *buf, uint64 morp)
{
  buf[0] = morp >> 56;
  buf[1] = morp >> 48;
  buf[2] = morp >> 40;
  buf[3] = morp >> 32;
  buf[4] = morp >> 24;
  buf[5] = morp >> 16;
  buf[6] = morp >> 8;
  buf[7] = morp;
}

static INLINE uint16 MDFN_de16lsb(const uint8 *morp)
{
  return(morp[0] | (morp[1] << 8));
}

static INLINE uint32 MDFN_de24lsb(const uint8 *morp)
{
  return(morp[0] | (morp[1]<<8) | (morp[2]<<16));
}

static INLINE uint32 MDFN_de32lsb(const uint8 *morp)
{
  return(morp[0] | (morp[1]<<8) | (morp[2]<<16) | (morp[3]<<24));
}

static INLINE uint64 MDFN_de64lsb(const uint8 *morp)
{
  return (((uint64)morp[0]) |
          ((uint64)morp[1] << 8) |
          ((uint64)morp[2] << 16) |
          ((uint64)morp[3] << 24) |
          ((uint64)morp[4] << 32) |
          ((uint64)morp[5] << 40) |
          ((uint64)morp[6] << 48) |
          ((uint64)morp[7] << 54));
}

static INLINE uint16 MDFN_de16msb(const uint8 *morp)
{
  return(morp[1] | (morp[0]<<8));
}

static INLINE uint32 MDFN_de24msb(const uint8 *morp)
{
  return(morp[2] | (morp[1]<<8) | (morp[0]<<16));
}

static INLINE uint32 MDFN_de32msb(const uint8 *morp)
{
  return(morp[3] | (morp[2]<<8) | (morp[1]<<16) | (morp[0]<<24));
}


#ifdef __cplusplus
static INLINE void MDFN_en16lsb(uint16 *buf, uint16 morp) { MDFN_en16lsb((uint8*) buf, morp); }
static INLINE void MDFN_en16lsb(uint32 *buf, uint16 morp) { MDFN_en16lsb((uint8*) buf, morp); }

static INLINE void MDFN_en24lsb(uint16 *buf, uint32 morp) { MDFN_en24lsb((uint8*) buf, morp); }
static INLINE void MDFN_en24lsb(uint32 *buf, uint32 morp) { MDFN_en24lsb((uint8*) buf, morp); }

static INLINE void MDFN_en32lsb(uint16 *buf, uint32 morp) { MDFN_en32lsb((uint8*) buf, morp); }
static INLINE void MDFN_en32lsb(uint32 *buf, uint32 morp) { MDFN_en32lsb((uint8*) buf, morp); }

static INLINE void MDFN_en64lsb(uint16 *buf, uint64 morp) { MDFN_en64lsb((uint8*) buf, morp); }
static INLINE void MDFN_en64lsb(uint32 *buf, uint64 morp) { MDFN_en64lsb((uint8*) buf, morp); }

static INLINE void MDFN_en16msb(uint16 *buf, uint16 morp) { MDFN_en16msb((uint8*) buf, morp); }
static INLINE void MDFN_en16msb(uint32 *buf, uint16 morp) { MDFN_en16msb((uint8*) buf, morp); }

static INLINE void MDFN_en24msb(uint16 *buf, uint32 morp) { MDFN_en24msb((uint8*) buf, morp); }
static INLINE void MDFN_en24msb(uint32 *buf, uint32 morp) { MDFN_en24msb((uint8*) buf, morp); }

static INLINE void MDFN_en32msb(uint16 *buf, uint32 morp) { MDFN_en32msb((uint8*) buf, morp); }
static INLINE void MDFN_en32msb(uint32 *buf, uint32 morp) { MDFN_en32msb((uint8*) buf, morp); }

static INLINE void MDFN_en64msb(uint16 *buf, uint64 morp) { MDFN_en64msb((uint8*) buf, morp); }
static INLINE void MDFN_en64msb(uint32 *buf, uint64 morp) { MDFN_en64msb((uint8*) buf, morp); }

static INLINE uint16 MDFN_de16lsb(const uint16 *morp) { return MDFN_de16lsb((const uint8*) morp); }
static INLINE uint16 MDFN_de16lsb(const uint32 *morp) { return MDFN_de16lsb((const uint8*) morp); }

static INLINE uint32 MDFN_de24lsb(const uint16 *morp) { return MDFN_de24lsb((const uint8*) morp); }
static INLINE uint32 MDFN_de24lsb(const uint32 *morp) { return MDFN_de24lsb((const uint8*) morp); }

static INLINE uint32 MDFN_de32lsb(const uint16 *morp) { return MDFN_de32lsb((const uint8*) morp); }
static INLINE uint32 MDFN_de32lsb(const uint32 *morp) { return MDFN_de32lsb((const uint8*) morp); }

static INLINE uint64 MDFN_de64lsb(const uint16 *morp) { return MDFN_de64lsb((const uint8*) morp); }
static INLINE uint64 MDFN_de64lsb(const uint32 *morp) { return MDFN_de64lsb((const uint8*) morp); }

static INLINE uint16 MDFN_de16msb(const uint16 *morp) { return MDFN_de16msb((const uint8*) morp); }
static INLINE uint16 MDFN_de16msb(const uint32 *morp) { return MDFN_de16msb((const uint8*) morp); }

static INLINE uint32 MDFN_de24msb(const uint16 *morp) { return MDFN_de24msb((const uint8*) morp); }
static INLINE uint32 MDFN_de24msb(const uint32 *morp) { return MDFN_de24msb((const uint8*) morp); }

static INLINE uint32 MDFN_de32msb(const uint16 *morp) { return MDFN_de32msb((const uint8*) morp); }
static INLINE uint32 MDFN_de32msb(const uint32 *morp) { return MDFN_de32msb((const uint8*) morp); }
#endif

#endif
