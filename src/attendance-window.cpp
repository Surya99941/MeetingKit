/* attendance-window.cpp
 *
 * Copyright 2021 SuryaSiva
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

#include "attendance-window.h"

AttendanceWindow::AttendanceWindow()
	: Glib::ObjectBase("AttendanceWindow")
	, Gtk::Window()
	, headerbar(nullptr)
	, label(nullptr)
{
	builder = Gtk::Builder::create_from_resource("/com/Surya99941/github/com/attendance-window.ui");
	builder->get_widget("headerbar", headerbar);
	builder->get_widget("label", label);
	add(*label);
	label->show();
	set_titlebar(*headerbar);
	headerbar->show();
}
