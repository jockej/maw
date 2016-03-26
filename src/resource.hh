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

#include "tile.hh"

namespace maw {
class rescource {
private:
  const std::string name;
  const unsigned quantity;
public:
  rescource(Config & config);
  unsigned get_food_bonus(maw_tile tile) const;
  unsigned get_prod_bonus(maw_tile tile) const;
  unsigned get_trade_bonus(maw_tile tile) const;
}; // end class rescource
} // end namespace maw
