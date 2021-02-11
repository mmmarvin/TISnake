/**********
 *
 *     Snake for TI-84
 *     by Marvin Manese
 *     
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>. 
 *
 **********/
#pragma less_pedantic

#include <ti83p.h>
#include <stdbool.h>
#include "game.h"

static void runAbout()
{
	unsigned char k;
	bool exitKeyPressed = false;
	while(!exitKeyPressed) {
		ClrScrnFull();
		HomeUp();

		NewLine();
		PutS("    Snake by");
		NewLine();
		PutS(" Marvin Manese");
		NewLine();
		PutS("    (c) 2019");
		
		k = GetKey();
		if(k == 0x05)
			exitKeyPressed = true;
	}
}

static void runMainMenuPlay()
{
	unsigned char k;
	bool exitKeyPressed = false;
	int choice = 0;

	while(!exitKeyPressed) {
		ClrScrnFull();
		HomeUp();

		PutS("  Snake v.1.00");
		NewLine();
		NewLine();
		PutS("> Play");
		NewLine();
		if(choice == 0)
			PutS(" > With walls");
		else
			PutS("   With walls");
		NewLine();
		if(choice == 1)
			PutS(" > Without walls");
		else
			PutS("   Without walls");
		NewLine();
		PutS("  About");
		NewLine();
		PutS("  Exit");

		k = GetKey();
		if(k == 0x05) {
			switch(choice) {
			case 0:
				gameRun(true);
			break;
			case 1:
				gameRun(false);
			break;
			}
		} else if(k == 0x04) {
			++choice;
			if(choice > 1)
				choice = 0;
		} else if(k == 0x03) {
			--choice;
			if(choice < 0)
				choice = 1;
		} else if(k == 0x09)
			exitKeyPressed = true;
	}
}

static void runMainMenu()
{
	unsigned char k;
	bool exitKeyPressed = false;
	int choice = 0;

	while(!exitKeyPressed) {
		ClrScrnFull();
		HomeUp();

		NewLine();
		PutS("  Snake v.1.00");
		NewLine();
		NewLine();
		if(choice == 0)
			PutS("> Play");
		else 
			PutS("  Play");
		NewLine();
		if(choice == 1)
			PutS("> About");
		else 
			PutS("  About");
		NewLine();
		if(choice == 2)
			PutS("> Exit");
		else 
			PutS("  Exit");

		k = GetKey();
		if(k == 0x05) {
			switch(choice) {
			case 0:
				runMainMenuPlay();
			break;
			case 1:
				runAbout();
			break;
			case 2:
				exitKeyPressed = true;
			break;
			}
		} else if(k == 0x04) {
			++choice;
			if(choice > 2)
				choice = 0;
		} else if(k == 0x03) {
			--choice;
			if(choice < 0)
				choice = 2;
		} else if(k == 0x09)
			exitKeyPressed = true;
	}
}

int main()
{
	runMainMenu();

	return 0;
}