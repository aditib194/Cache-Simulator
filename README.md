# Cache-Simulator
Simulates the behaviour of a cache memory:
1) Implements make_cache, make_sets, make_lines, make_block functions to allocate the cache data structure.
2) Implements get_set, get_line, and get_byte functions that extract bits from an address to index into the cache correctly to determine if you have a hit or a miss, etc.
3) Implements the LRU algorithm to properly evict the least recently used lines from the cache.
