/*
* Seven Kingdoms: Ancient Adversaries
*
* Copyright 1997,1998 Enlight Software Ltd.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

//Filename    : OSaveGameArray.h
//Description : Save/load game menu

#ifndef __OSAVEGAMEARRAY_H
#define __OSAVEGAMEARRAY_H

#ifndef __ODYNARR_H
#include <ODYNARR.h>
#endif

#include <OSaveGameInfo.h>


class SaveGameArray : private DynArray
{
public:
	bool     has_fetched_last_file_name_from_hall_of_fame;
	char     last_file_name[MAX_PATH+1]; // (persisted via HallOfFame)

	char		same_version;				// true if major version of the load game is same as that of the program

public:
	SaveGameArray();

	void init(const char *extStr);
	void deinit();

	int  menu(int, int *recno=NULL);

	int  save_game()    { return menu(1); }
	int  load_game()    { return menu(2); }

	int save_new_game(const char* =NULL); // save a new game immediately without prompting menu

	SaveGameInfo* operator[](int recNo);

private:
	void set_file_name(SaveGameInfo* /*in/out*/ saveGame);

	void disp_browse();
	static void disp_entry_info(const SaveGameInfo* entry, int x, int y);
	void load_all_game_header(const char *extStr);
	int  process_action(int=0);
	void del_game();
};

extern SaveGameArray save_game_array;
extern SaveGameInfo  save_game_info;        //**BUGHERE

#endif
