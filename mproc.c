/*

 mproc Copyright (C) <2016>  <matthias holl>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>

 mproc.c

 admin tool

 by mah00

 www.mahoosoft.com

 gcc -o mproc mproc.c

 sudo ./mproc

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define puffer 32768

enum {
	processor,
	diskstats,
	mountinfo,
	mountstats,
	mounts,
	iomem,
	interrupts,
	statt,
	softirqs,
	limits,
	maps,
	smaps,
	ip_conntrack,
	sockstat,
	protocols,
	netdev,
	ioports,
	modules,
	vmstat,
	device,
	memory,
	scsi,
	bye
};
static const char *call[] = { "/proc/cpuinfo", "/proc/diskstats",
		"/proc/self/mountinfo", "/proc/self/mountstats", "/proc/self/mounts",
		"/proc/iomem", "/proc/interrupts", "/proc/stat", "/proc/softirqs",
		"/proc/self/limits", "/proc/self/maps", "/proc/self/smaps",
		"/proc/net/ip_conntrack", "/proc/net/sockstat", "/proc/net/protocols",
		"/proc/net/dev", "/proc/ioports", "/proc/modules", "/proc/vmstat",
		"/proc/devices", "/proc/meminfo", "/proc/scsi/scsi" };
static void callinfo(const int a) {
	FILE *mahoofile;
	char buffer[puffer];
	size_t bytes_read;
	if ((mahoofile = fopen(call[a], "r")) == NULL ) {

		return;
	}
	bytes_read = fread(buffer, 1, sizeof(buffer), mahoofile);
	fclose(mahoofile);
	if (bytes_read == 0 || bytes_read == sizeof(buffer))
		return;
	buffer[bytes_read] = '\0';

	printf("%s", buffer);
	printf("press enter");
	getchar();
	return;
}
int main(void) {
	int menu;
	do {

		printf("\n");
		printf("This is free software! GNU General Public License \n");
		printf("This program comes with ABSOLUTELY NO WARRANTY \n");
		printf("mproc Copyright (C) 2016 by Matthias Holl \n");
		printf("\n");
		printf(">procinfo:<\n");
		printf("-%d-  processor\n", processor);
		printf("-%d-  diskstats\n", diskstats);
		printf("-%d-  mountinfo\n", mountinfo);
		printf("-%d-  mountstats\n", mountstats);
		printf("-%d-  mounts\n", mounts);
		printf("-%d-  iomem\n", iomem);
		printf("-%d-  interrupts\n", interrupts);
		printf("-%d-  stat\n", statt);
		printf("-%d-  softirqs\n", softirqs);
		printf("-%d-  limits\n", limits);
		printf("-%d- maps\n", maps);
		printf("-%d- smaps\n", smaps);
		printf("-%d- net/ip_conntrack\n", ip_conntrack);
		printf("-%d- sockstat\n", sockstat);
		printf("-%d- net/protocols\n", protocols);
		printf("-%d- net/dev\n", netdev);
		printf("-%d- ioports\n", ioports);
		printf("-%d- modules\n", modules);
		printf("-%d- vmstat\n", vmstat);
		printf("-%d- device\n", device);
		printf("-%d- memory\n", memory);
		printf("-%d- scsi\n", scsi);
		printf("-%d- quit\n", bye);
		printf("your choice:");

		do {
			scanf("%d", &menu);
		} while (getchar() != '\n');

		switch (menu) {

		case processor:
			callinfo(processor);
			break;
		case diskstats:
			callinfo(diskstats);
			break;
		case mountinfo:
			callinfo(mountinfo);
			break;
		case mountstats:
			callinfo(mountstats);
			break;
		case mounts:
			callinfo(mounts);
			break;
		case iomem:
			callinfo(iomem);
			break;
		case interrupts:
			callinfo(interrupts);
			break;
		case statt:
			callinfo(statt);
			break;
		case softirqs:
			callinfo(softirqs);
			break;
		case limits:
			callinfo(limits);
			break;
		case maps:
			callinfo(maps);
			break;
		case smaps:
			callinfo(smaps);
			break;
		case ip_conntrack:
			callinfo(ip_conntrack);
			break;
		case sockstat:
			callinfo(sockstat);
			break;
		case protocols:
			callinfo(protocols);
			break;
		case netdev:
			callinfo(netdev);
			break;
		case ioports:
			callinfo(ioports);
			break;
		case modules:
			callinfo(modules);
			break;
		case vmstat:
			callinfo(vmstat);
			break;
		case device:
			callinfo(device);
			break;
		case memory:
			callinfo(memory);
			break;
		case scsi:
			callinfo(scsi);
			break;
		case bye:
			callinfo(bye);
			break;

		}
	} while (menu != bye);
	printf("bye... mproc\n");
	printf("GNU General Public License\n\n\n");
	return EXIT_SUCCESS;
}
