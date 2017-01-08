@echo ON

wiimake-isotool ../Melee.iso --load ../vanilla_melee.data --save-temps
wiimake ../Melee.iso config.ini
del *.o