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

using namespace maw;

unsigned food(maw_tile tile) {
  if (tile.terr == 0) return 0;
  unsigned ret = terrains[tile.terr]->get_food();
  return ret;
}

unsigned prod(maw_tile tile) {
  if (tile.terr == 0) return 0;
  unsigned ret = terrains[tile.terr]->get_prod();
  return ret;
}

unsigned trade(maw_tile tile) {
  if (tile.terr == 0) return 0;
  unsigned ret = terrains[tile.terr]->get_trade();
  return ret;
}

float defense_bonus(maw_tile tile) {
  if (tile.terr == 0) return 0;
  float ret = terrains[tile.terr]->get_defense_bonus();
  return ret;
}  

std::vector<terrain*> terrains;

