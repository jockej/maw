#ifndef UNIT_TYPE_HH
#define UNIT_TYPE_HH
/*
 * Copyright (C) 2016, The MaW Team
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

/*
  This file contains the definitions for the unit_type class. Here we define
  things that are common to all  unit types.
 */

#include <vector>
#include <string>

namespace maw {

class unit_type {
private:
  /*! supertype of this unit type */
  const std::vector<std::string> supertypes;
  /*! base movement points the unit gets each turn.  */
  const unsigned movs;
  /*! the base attack strength */
  const unsigned atk;
  /*! the base defense strength */
  const unsigned dfns;
  /*! the base health points */
  const unsigned hlth;
  /*! what unit this unit becomes when it upgrades */
  const unsigned upgrd;
  /*! splash damage */
  const unsigned splsh;
  /*! resources required to build this unit and the quantity required */
  const std::vector<std::pair<unsigned, unsigned> > req_resc;
  /*! a vector of units that this unit type can see even if they are 'hidden' */
  const std::vector<unsigned> can_see;
  /*! movement class */
  const maw_mvmt_cls mvmt_cls;

  // special cases we will need to handle somehow
  
  /*! is this unit a worker? */
  const bool worker;
  /*! is this unit a settler? */
  const bool settler;
  /*! This unit can only be seen at a distance by those units which have it in
    their 'can_see' vector */
  const bool hidden;
  /*! is this unit a 'oneshot'? This means it is destroyed on attack/defense */
  const bool oneshot;
  /*! Can this unit attack air units? */
  const bool anti_air;
  /*! this means this unit can attack across rivers and from ship to shore
   * without taking the penalty units usually get. */
  const bool amphibious;

public:
  /*! this is the interface for a unit */
  unit_type()
  {}
  
  /* Getters */
  inline unsigned get_upgrd() const {return upgrd;}
  inline unsigned get_hlth() const {return hlth;}
  inline maw_mvmt_cls get_mvmt_cls() const {return mvmt_cls;}
  inline bool is_oneshot() const {return oneshot;}
  inline bool is_worker() const {return worker;}
  inline bool is_settler() const {return settler;}
  inline bool is_hidden() const {return hidden;}
  inline bool is_anti_air() const {return anti_air;}
  inline bool is_amphibious() const {return amphibious;}
  
  /* functions implemented in  */
  
  // how many moves does the unit has left?
  maw_movp get_rem_movs(maw_unit_info unit) const;

  // get attack strength for unit `unit' when it is attacking from tile `from'
  // to  tile `to' and it is attacking unit `against',
  float get_atk(maw_unit_info unit, maw_unit_info against,
                maw_tile from, maw_tile to) const;

  // get defensive strength
  float get_dfns(maw_unit_info unit, maw_unit_info attacker,
                 maw_tile from, maw_tile to) const;

  // the cost of moving to tile `to'. A return value of 0 shall mean that it is
  // not possible for this unit to make this move.
  maw_movp mov_cst(maw_tile to) const;
};

} // end namespace maw
#endif // ifndef UNIT_TYPE_HH
