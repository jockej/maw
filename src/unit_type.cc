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

namespace maw {

void unit_type::default_reinit_movs(maw_unit_info *unit) const {
  // units always start a turn with an integral number of moves
  unit->movp_den = 1;  
  switch (get_mvmt_cls()) {
    // air units always have all their moves the next turn
  case AIR:
    unit->movp_num = movs;
    unit->movp_den = 1;
    break;
  case SEA:
  case HELI:
  case LAND:
    unit->movp_num = movs;
    // if the unit has less than half health left it gets on move less
    // but it can neer get less than one.
    if (unit->hlth < get_hlth()/2 && movs > 1) --unit->movp_num;
    break;

  default:
    // error
  }
}

float unit_type::default_atk(maw_unit_info unit, maw_unit_info against,
                             maw_tile from, maw_tile to) const {
  
}


float unit_type::default_dfns(maw_unit_info unit, maw_unit_info attacker,
                              maw_tile from, maw_tile to) const {
  
}

maw_movp unit_type::default_mov_cst(maw_tile to) const {
  // the default move 
  maw_movp r = {1, 1};
  return r;
}



void unit_type::reinit_movs(maw_unit_info *unit) const {
  
}

std::vector<unit_type> units;

} // end namespace maw
