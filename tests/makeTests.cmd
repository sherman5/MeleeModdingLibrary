@echo ON

wiimake-isotool ../Melee.iso --load ../vanilla_melee.data
wiimake ../Melee.iso config.ini
del *.o