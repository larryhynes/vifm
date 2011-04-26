/* vifm
 * Copyright (C) 2001 Ken Steen.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include<limits.h>

#include "status.h"

Status curr_stats;

void
init_status(void)
{
	curr_stats.need_redraw = 0;
	curr_stats.getting_input = 0;
	curr_stats.menu = 0;
	curr_stats.redraw_menu = 0;
	curr_stats.is_updir = 0;
	curr_stats.last_char = 0;
	curr_stats.is_console = 0;
	curr_stats.search = 0;
	curr_stats.save_msg = 0;
	curr_stats.use_register = 0;
	curr_stats.curr_register = -1;
	curr_stats.register_saved = 0;
	curr_stats.show_full = 0;
	curr_stats.view = 0;
	curr_stats.setting_change = 0;
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab : */
