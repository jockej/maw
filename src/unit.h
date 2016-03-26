/*
 * Copyright (C) 2015, The MaW Team
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
#include <cstdint>
//#include map_stuff?


/*! A unique id for each unit */
typedef uint32_t maw_unit_id;

/*! This a field in the maw_unit struct which contains most of the info about
  the unit such as its health, its type, its xp etc...  */
typedef union {
  /*! the full thing */
  uint64_t full;
  struct {
    /*! the type of the unit */
    uint64_t type:10;
    /*! The numerator of the remaining moves */
    uint64_t movp_num:7;
    /*! The denominator */
    uint64_t movp_den:4;
    /*! health */
    uint64_t hlth:10;
    /*! Experience points */
    uint64_t xp:8;
    /*! Medals, first track */
    uint64_t mdl1:2;
    /*! Medals, second track */
    uint64_t mdl2:2;
    /*! Medals, 3rd track */
    uint64_t mdl3:2;
    /*! Current state of the unit */
    uint64_t state:5;
    /*! Number of turns the unit has been in this state */
    uint64_t tu_cur_st:5;
  };
} maw_unit_info;


typedef struct {
  /*! The position of this unit, if it is aboard another unit or escorting
   * another unit, it has the same position as that unit, so we don't need to
   * store it. */
  union {
    maw_pos pos;
    maw_unit_id escorting;
    maw_unit_id aboard;
  } pos;
  /*! This is the field that holds most of the info about the unit.
   *
   * This field is the one that is usually passed around to different functions
   * that take a 'unit' as an argument.
   */
  maw_unit_info info;
  /*! the id of the unit */
  maw_unit_id id;
  /* the player the unit belongs to */
  maw_plyr_id plyr;
} maw_unit;

/*! Maw movement points, consists of a numerator and a denominator.
 *
 * This is so that a unit can have for example 2 and a half moves left. */
typedef struct maw_movp {
  uint8_t num, den;
} maw_movp;

/* Movement orders: if a unit is in s state of GOTO, it has an entry of this
 * struct with its id.*/
typedef struct maw_mvmt_ordrs {
  maw_unit_id unit;
  maw_pos to;
} maw_mvmt_ordrs;

/*! Patrol orders, if a unit is in a state of PATROL, it will have a
 * corresponding instance of this struct. This can also be reused for trade
 * units conneting two cities.*/
typedef struct maw_ptrl_ordrs {
  maw_unit_id unit;
  maw_pos from;
  maw_pos to;
} maw_ptrl_ordrs;

/*! This enum defines the states a unit can be in. */
typedef enum maw_unit_state {
  /*! active, the default state, unit is ready to take orders */
  ACTIVE,
  /*! the unit has orders to go somewhere */
  GOTO,
  /*! the unit is in a state of patrolling. This means it is moving between two
   * positions, if a unit of another player comes into view, this unit should
   * should transfer to the ACTIVE state. */
  PATROL,
  /*! the unit is watching. This is like PATROL, except the unit doesn't move.
   * When an enemy unit comes into sight, it will still wake up. */
  WATCH,
  /*! The unit is escorting another unit. It will follow the escorted unit. */
  ESCORT,
  /*! the unit is fortified, it recieves a defensive bonus. */
  FORTIFIED,
  /*! The unit is aboard another unit */
  BOARDED,
  /*! this is a state for air units. They can only be in this state for a finite
   * number of turns before they crash. I also have an idea about a helicpoter
   * unit which can be in this state indefinitely as long as it is over land, but
   * only for a finite nr of turns over water. just an idea...*/
  IN_FLIGHT,
  /*! The user has requsted that this unit skip its turn. But it can be woken
   * and become ACTIVE. */
  SKIP,
  /*! ok, this is a state for worker units. They will also need a state for
   * what they are working on, but the problem is that this has to be
   * autogenerated because it depends on what improvements we defined in the
   * conf files. The hole we dug ourself is getting deeper and deeper... */
  WORKING,
  /*! this is a state for trade units, it is essentially the same as PATROL,
   * but I figure it might be convenient. */
  TRADE
} maw_unit_state;

/*! Movement class, this defines some default moving rules */
typedef enum maw_mvmt_cls {LAND, SEA, AIR, HELI} maw_mvmt_cls;

}
