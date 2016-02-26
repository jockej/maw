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

namespace maw {

class terrain {
private:
  /*! base food */
  const unsigned food;
  /**! base production */
  const unsigned prod;
  /*! base trade*/
  const unsigned trade;
  /*! Whether or not this is a water tile */
  bool water_tile;
public:
  terrain(Setting & setting);
  inline bool is_water_tile() const {return water_tile;}
  inline unsigned get_food() const {return food;}
  inline unsigned get_prod() const {return prod;}
  inline unsigned get_trade() const {return trade;}  
}; // end class terrain
} // end namespace maw
