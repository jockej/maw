/*
 * Copyright (C) 2016 The MaW Team
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

typedef union {
  uint32_t full;
  struct {
    uint32_t terr:8;
    uint32_t resc:7;
    uint32_t imprv:7;
    uint32_t road:3;
    uint32_t rivr:2;
    uint32_t visn:1;
  };
} maw_tile;

typedef struct maw_pos {
  uint16_t x, y;
} maw_pos;

typedef struct maw_map {
  uint16_t xsize, ysize;
  maw_tile* map;
} maw_map;

