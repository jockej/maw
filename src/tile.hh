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
#include "terrain.hh"

namespace maw {

/*!
 * A tile on the map
 */
typedef struct {
  /*! The terrain on this tile */
  uint32_t terr:8;
  /*! The resource on this tile */
  uint32_t resc:6;
  /*! Quantity of that resource */
  uint32_t qty:4;
  /*! The improvement on this tile */
  uint32_t imprv:7;
  /*! What kind of roads are on this tile */
  uint32_t road:2;
  /*! What kind of river or canal is on this tile */
  uint32_t rivr:2;
  /*! If this tile is visible or not */
  uint32_t visn:1;
} maw_tile;

inline bool has_road(maw_tile tile) {
  return tile.road == 1;
}

inline bool has_railroad(maw_tile tile) {
  return tile.road == 2;
}

inline bool has_river(maw_tile tile) {
  return tile.rivr == 1;
}

inline bool has_canal(maw_tile tile) {
  return tile.rivr == 2;
}

/*!
 * Total amount of food from this tile
 */
unsigned food(maw_tile tile);

/*!
 * 
 */
unsigned prod(maw_tile tile);

/*!
 * 
 */
unsigned trade(maw_tile tile);


extern std::vector<terrain*> terrains;


} // end namespace maw
