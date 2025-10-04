# Copyright (C) 2025  Giulio Salvi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

CV=17
CC=gcc
CC_FLAGS=-Wall -Wextra -Wpedantic -g --std=c$(CV) -I./h/

ifeq ($(OS), Windows_NT)
	SO_EXT=.dll
	LINKER_FLAGS=-lws2_32

	SHELL := C:/Windows/System32/cmd.exe
else
	SO_EXT=.so

	SHELL := /usr/bin/env bash
endif

.PHONY: all setup gen-docs static shared

all: static shared

setup:
	mkdir bin

gen-docs:
	doxygen docs/Doxyfile

static: src/libsocks.c h/libsocks.h
	$(CC) $(CC_FLAGS) src/libsocks.c -o bin/libsocks.o $(LINKER_FLAGS)

shared: src/libsocks.c h/libsocks.h
	$(CC) $(CC_FLAGS) src/libsocks.c -o bin/libsocks$(SO_EXT)
