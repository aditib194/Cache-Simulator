#include "bits.h"
#include "cache.h"
#include "math.h"

int get_set(Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
  return (address >> (cache->block_bits)) % (int) exp2(cache->set_bits);
  return 0;
}

int get_line(Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  return address / exp2(cache->block_bits + cache->set_bits);
}

int get_byte(Cache *cache, address_type address) {
  // TODO
  // Extract the block offset (byte index) bits from a 32-bit address.
  //
  return address % (int) exp2(cache->block_bits);
}
