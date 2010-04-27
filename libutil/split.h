/*
 * Copyright (c) 2002, 2005 Tama Communications Corporation
 *
 * This file is part of GNU GLOBAL.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SPLIT_H_
#define _SPLIT_H_

#define NPART 10

typedef struct {
        int npart;
	struct part {
		char *start;
		char *end;
		int savec;
	} part[NPART];
} SPLIT;

int split(const char *, int, SPLIT *);
void recover(SPLIT *);
void split_dump(SPLIT *);
const char *parse_xid(const char *, char *, int *);

#endif /* ! _SPLIT_H_ */
