#
# Copyright 2017 Alexander Dahl <post@lespocky.de>
#
# SPDX-License-Identifier: 0BSD
# License-Filename: LICENSE
#

cmake_minimum_required(VERSION 3.0)

project(vigilant-enigma
	VERSION 0.1.0
	LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_library(NETSNMP_LIBRARY netsnmp)
find_library(NETSNMP_AGENT_LIBRARY netsnmpagent)

add_executable(vigilant-enigma
	ve_data.c
	ve_main.c
	nstMIBObjects.c
)
target_link_libraries(vigilant-enigma
	"${NETSNMP_LIBRARY}"
	"${NETSNMP_AGENT_LIBRARY}"
)
