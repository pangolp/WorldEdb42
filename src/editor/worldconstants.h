/*
 * Copyright 2023, Tim Baker <treectrl@users.sf.net>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WORLDCONSTANTS_H
#define WORLDCONSTANTS_H

// Cell-size constants are defined in lotfilesmanager.h (300-tile B41 cells)
// and lotfilesmanager256.h (256-tile B42 cells).

#ifndef WORLD_GROUND_LEVEL
#define WORLD_GROUND_LEVEL 8
#endif

#ifndef MIN_WORLD_LEVEL
#define MIN_WORLD_LEVEL -8
#endif

#ifndef MAX_WORLD_LEVEL
#define MAX_WORLD_LEVEL 7
#endif

#ifndef MAX_WORLD_LEVELS
#define MAX_WORLD_LEVELS 16
#endif

#endif // WORLDCONSTANTS_H
