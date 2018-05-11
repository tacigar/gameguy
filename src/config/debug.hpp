#ifndef GAMEGUY_CONFIG_DEBUG_HPP
#define GAMEGUY_CONFIG_DEBUG_HPP

#ifdef DEBUG
#    define DEBUG_STDERR(x) (std::cerr << (x))
#    define DEBUG_STDOUT(x) (std::cout << (x))
#else
#    define DEBUG_STDERR(x)
#    define DEBUG_STDOUT(x)
#endif

#endif // GAMEGUY_CONFIG_DEBUG_HPP
