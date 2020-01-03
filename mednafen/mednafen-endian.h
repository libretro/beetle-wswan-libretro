#ifndef __MDFN_ENDIAN_H
#define __MDFN_ENDIAN_H

#include <stdio.h>
#include <stdint.h>


// The following functions can encode/decode to unaligned addresses.

static INLINE void MDFN_en16lsb(uint16 *a, uint16 v)
{
#ifdef MSB_FIRST
   #ifdef ARCH_POWERPC
      __asm__ ("sthbrx %0, %y1" : : "r"(v), "Z"(*a));
   #else
      uint16 tmp = (v << 8) | (v >> 8);
      *a = tmp;
   #endif
#else
   *a = v;
#endif
}

static INLINE void MDFN_en32lsb(uint32 *a, uint32 v)
{
#ifdef MSB_FIRST
   #ifdef ARCH_POWERPC
      __asm__ ("stwbrx %0, %y1" : : "r"(v), "Z"(*a));
   #else
      uint32 tmp = (v << 24) | ((v & 0xFF00) << 8) | ((v >> 8) & 0xFF00) | (v >> 24);
      *a = tmp;
   #endif
#else
   *a = v;
#endif
}

static INLINE void MDFN_en64lsb(uint64 *a, uint64 v)
{
#ifdef MSB_FIRST
   a[0] = v >> 0;
   a[1] = v >> 8;
   a[2] = v >> 16;
   a[3] = v >> 24;
   a[4] = v >> 32;
   a[5] = v >> 40;
   a[6] = v >> 48;
   a[7] = v >> 56;
#else
   *a = v;
#endif
}


static INLINE void MDFN_en16msb(uint16 *a, uint16 v)
{
#ifdef MSB_FIRST
   *a = v;
#else
   uint16 tmp = (v << 8) | (v >> 8);
   *a = tmp;
#endif
}

static INLINE void MDFN_en32msb(uint32 *a, uint32 v)
{
#ifdef MSB_FIRST
   *a = v;
#else
   uint32 tmp = (v << 24) | ((v & 0xFF00) << 8) | ((v >> 8) & 0xFF00) | (v >> 24);
   *a = tmp;
#endif
}

static INLINE void MDFN_en64msb(uint64 *a, uint64 v)
{
#ifdef MSB_FIRST
   *a = v;
#else
   a[0] = v >> 56;
   a[1] = v >> 48;
   a[2] = v >> 40;
   a[3] = v >> 32;
   a[4] = v >> 24;
   a[5] = v >> 16;
   a[6] = v >> 8;
   a[7] = v;
#endif
}


static INLINE uint16 MDFN_de16lsb(const uint16 *a)
{
#ifdef MSB_FIRST
   #ifdef ARCH_POWERPC
      uint16_t tmp;
      __asm__ ("lhbrx %0, %y1" : "=r"(tmp) : "Z"(*a));
      return(tmp);
   #else
      return((*a << 8) | (*a >> 8));
   #endif
#else
   return *a;
#endif
}

static INLINE uint32 MDFN_de32lsb(const uint32 *a)
{
#ifdef MSB_FIRST
   #ifdef ARCH_POWERPC
      uint32_t tmp;
      __asm__ ("lwbrx %0, %y1" : "=r"(tmp) : "Z"(*a));
      return(tmp);
   #else
      uint32 tmp = *a;
      return((tmp << 24) | ((tmp & 0xFF00) << 8) | ((tmp >> 8) & 0xFF00) | (tmp >> 24));
   #endif
#else
   return *a;
#endif
}

static INLINE uint64 MDFN_de64lsb(const uint64 *a)
{
#ifdef MSB_FIRST
   return ((a[0] << 0) |
           (a[1] << 8) |
           (a[2] << 16) |
           (a[3] << 24) |
           (a[4] << 32) |
           (a[5] << 40) |
           (a[6] << 48) |
           (a[7] << 54));
#else
   return *a;
#endif
}


static INLINE uint16 MDFN_de16msb(const uint16 *a)
{
#ifdef MSB_FIRST
   return *a;
#else
   return((*a << 8) | (*a >> 8));
#endif
}

static INLINE uint32 MDFN_de32msb(const uint32 *a)
{
#ifdef MSB_FIRST
   return *a;
#else
   uint32 tmp = *a;
   return((tmp << 24) | ((tmp & 0xFF00) << 8) | ((tmp >> 8) & 0xFF00) | (tmp >> 24));
#endif
}

static INLINE uint64 MDFN_de64msb(const uint64 *a)
{
#ifdef MSB_FIRST
   return *a;
#else
   return ((a[7] << 0) |
           (a[6] << 8) |
           (a[5] << 16) |
           (a[4] << 24) |
           (a[3] << 32) |
           (a[2] << 40) |
           (a[1] << 48) |
           (a[0] << 54));
#endif
}


#ifdef __cplusplus
static INLINE void MDFN_en16lsb(uint8  *a, uint16 v) { MDFN_en16lsb((uint16*) a, v); }
static INLINE void MDFN_en16lsb(uint32 *a, uint16 v) { MDFN_en16lsb((uint16*) a, v); }

static INLINE void MDFN_en32lsb(uint8  *a, uint32 v) { MDFN_en32lsb((uint32*) a, v); }
static INLINE void MDFN_en32lsb(uint16 *a, uint32 v) { MDFN_en32lsb((uint32*) a, v); }

static INLINE void MDFN_en64lsb(uint8  *a, uint64 v) { MDFN_en64lsb((uint64*) a, v); }
static INLINE void MDFN_en64lsb(uint16 *a, uint64 v) { MDFN_en64lsb((uint64*) a, v); }
static INLINE void MDFN_en64lsb(uint32 *a, uint64 v) { MDFN_en64lsb((uint64*) a, v); }


static INLINE void MDFN_en16msb(uint8  *a, uint16 v) { MDFN_en16msb((uint16*) a, v); }
static INLINE void MDFN_en16msb(uint32 *a, uint16 v) { MDFN_en16msb((uint16*) a, v); }

static INLINE void MDFN_en32msb(uint8  *a, uint32 v) { MDFN_en32msb((uint32*) a, v); }
static INLINE void MDFN_en32msb(uint16 *a, uint32 v) { MDFN_en32msb((uint32*) a, v); }

static INLINE void MDFN_en64msb(uint8  *a, uint64 v) { MDFN_en64msb((uint64*) a, v); }
static INLINE void MDFN_en64msb(uint16 *a, uint64 v) { MDFN_en64msb((uint64*) a, v); }
static INLINE void MDFN_en64msb(uint32 *a, uint64 v) { MDFN_en64msb((uint64*) a, v); }


static INLINE uint16 MDFN_de16lsb(const uint8  *a) { return MDFN_de16lsb((const uint16*) a); }
static INLINE uint16 MDFN_de16lsb(const uint32 *a) { return MDFN_de16lsb((const uint16*) a); }

static INLINE uint32 MDFN_de32lsb(const uint8  *a) { return MDFN_de32lsb((const uint32*) a); }
static INLINE uint32 MDFN_de32lsb(const uint16 *a) { return MDFN_de32lsb((const uint32*) a); }

static INLINE uint64 MDFN_de64lsb(const uint8  *a) { return MDFN_de64lsb((const uint64*) a); }
static INLINE uint64 MDFN_de64lsb(const uint16 *a) { return MDFN_de64lsb((const uint64*) a); }
static INLINE uint64 MDFN_de64lsb(const uint32 *a) { return MDFN_de64lsb((const uint64*) a); }


static INLINE uint16 MDFN_de16msb(const uint8  *a) { return MDFN_de16msb((const uint16*) a); }
static INLINE uint16 MDFN_de16msb(const uint32 *a) { return MDFN_de16msb((const uint16*) a); }

static INLINE uint32 MDFN_de32msb(const uint8  *a) { return MDFN_de32msb((const uint32*) a); }
static INLINE uint32 MDFN_de32msb(const uint16 *a) { return MDFN_de32msb((const uint32*) a); }

static INLINE uint64 MDFN_de64msb(const uint8  *a) { return MDFN_de64msb((const uint64*) a); }
static INLINE uint64 MDFN_de64msb(const uint16 *a) { return MDFN_de64msb((const uint64*) a); }
static INLINE uint64 MDFN_de64msb(const uint32 *a) { return MDFN_de64msb((const uint64*) a); }
#endif

#endif
