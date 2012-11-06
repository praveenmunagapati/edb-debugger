/*
Copyright (C) 2006 - 2011 Evan Teran
                          eteran@alum.rit.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ELF64_20070718_H_
#define ELF64_20070718_H_

#include "IBinary.h"
#include "elf_binary.h"

class ELF64 : public IBinary {
public:
	ELF64(const IRegion::pointer &region);
	virtual ~ELF64();

public:
	virtual bool validate_header();
	virtual edb::address_t entry_point();
	virtual edb::address_t calculate_main();
	virtual bool native() const;
	virtual edb::address_t debug_pointer();
	virtual size_t header_size() const;

private:
	void read_header();

private:
	elf64_header *header_;
};

#endif

