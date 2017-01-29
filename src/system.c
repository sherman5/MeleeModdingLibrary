#include "../system.h"
#include "../melee.h"

/*
80003220   memcpy (void *dest, void *src, int len)
800031F4   memmove (void *dest, void *src, int len)
80003130   memset (void *addy, int value, int len)
803238C8   memcmp (void *one, void *two, int len)
80301E58   strcpy (needs verified)

8037F1E4   void *malloc(int size); [note: blocks allocated are cached elsewhere,
		so this func isn't the one called for ALL allocations, but it
		is still helpful enough to be listed here.]*/
