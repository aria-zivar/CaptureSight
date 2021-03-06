#include <csight/RNG.hpp>

namespace csight::rng {
  namespace lcrng {
    u32 advance(u32 seed) { return seed * 0x41C64E6D + 0x6073; }
  }  // namespace lcrng

  xoroshiro::xoroshiro(ulong seed) { m_prng = swsh_xoroshiro(seed, 0x82A2B175229D6A5B); }

  u64 xoroshiro::nextulong() { return m_prng(); }
  u32 xoroshiro::nextuint() { return (u32)this->nextulong(); }
  u32 xoroshiro::next(u32 mask) { return m_prng() & mask; }
  u32 xoroshiro::next(u32 max, u32 mask) {
    u32 rand = m_prng() & mask;

    while (rand >= max) {
      rand = m_prng() & mask;
    }

    return rand;
  }
}  // namespace csight::rng
