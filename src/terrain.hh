/*
 * Copyright (C) 2016 The Maw Team
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
#include <config++>

namespace maw {

class terrain {
private:
  std::string name;
  /*! base food */
  const unsigned food;
  /**! base production */
  const unsigned prod;
  /*! base trade*/
  const unsigned trade;
  /*! Whether or not this is a water tile */
  bool water_tile;
  /*! The default cost for moving to this tile */
  const unsigned mov_cst;
  /*! Default defense bonus */
  const float def_bonus;
public:
  terrain(Config& config, std::string path);
  inline bool is_water_tile() const {return water_tile;}
  inline unsigned get_food() const {return food;}
  inline unsigned get_prod() const {return prod;}
  inline unsigned get_trade() const {return trade;}
  inline unsigned get_mov_cst() const {return mov_cst;}
  inline float get_defense_bonus() const {return def_bonus;}
}; // end class terrain
} // end namespace maw
