/*
SDLPoP, a port/conversion of the DOS game Prince of Persia.
Copyright (C) 2013-2015  Dávid Nagy

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

The authors of this program may be contacted at http://forum.princed.org
*/

#include "common.h"

#ifdef VITA
#include <psp2/power.h>
#include <psp2/kernel/processmgr.h>
#endif

int main(int argc, char *argv[])
{
#ifdef VITA
	int ret = debugNetInit("192.168.1.30", 18194, DEBUG);
	sceKernelPowerTick(SCE_KERNEL_POWER_TICK_DISABLE_AUTO_SUSPEND);
	scePowerSetArmClockFrequency(444);
#endif
	g_argc = argc;
	g_argv = argv;
	pop_main();
#ifdef VITA
	debugNetFinish();
	sceKernelExitProcess(0);
#endif
	return 0;
}

