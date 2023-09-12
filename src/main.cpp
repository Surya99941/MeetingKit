/* main.cpp
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
#include <memory>

static void
on_activate (Glib::RefPtr<Gtk::Application> app)
{
	// Get the current window. If there is not one, we will create it.
	static std::unique_ptr<Gtk::Window> window;

	if (!window) {
		window = std::make_unique<AttendanceWindow>();
		window->property_application() = app;
		window->property_default_width() = 600;
		window->property_default_height() = 300;
		app->add_window(*window);
	}

	// Ask the window manager/compositor to present the window to the user.
	window->present();
}

int
main (int argc, char *argv[])
{
	int ret;

	// Create a new Gtk::Application. The application manages our main loop,
	// application windows, integration with the window manager/compositor, and
	// desktop features such as file opening and single-instance applications.
	Glib::RefPtr<Gtk::Application> app =
		Gtk::Application::create("com.Surya99941.github.com", Gio::APPLICATION_FLAGS_NONE);

	app->signal_activate().connect(sigc::bind(&on_activate, app));
	ret = app->run(argc, argv);

	return ret;
}
