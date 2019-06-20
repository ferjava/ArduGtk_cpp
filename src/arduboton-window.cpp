/* arduboton-window.cpp
 *
 * Copyright 2019 ferjava
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
 *PROGAMA: Arduinoboton
 *Descripcion: Es un programa de practica que establece una conexion con un
 *arduino uno y pulsando el boton enciende o apaga un led.
 **/

#include <iostream>
#include "arduboton-window.h"
#include <gtkmm/messagedialog.h>
#include "libserialport.h"

ArdubotonWindow::ArdubotonWindow()
	: Glib::ObjectBase("ArdubotonWindow")
	, Gtk::Window()
	, headerbar(nullptr)
	, label(nullptr)
	, boton(nullptr)
	, fixed(nullptr)
{
	 //Creando la conexion
     sp_get_port_by_name("/dev/ttyACM0", &serialport);
     sp_set_baudrate(serialport,9600);
     sp_open(serialport,SP_MODE_WRITE);


    //Crea desde el archivo builder
	builder = Gtk::Builder::create_from_resource("/fjv/Ejercicios/ArduBoton/arduboton-window.ui");
	builder->get_widget("headerbar", headerbar);
	builder->get_widget("label", label);
	builder->get_widget("Fixed1",fixed);
	builder->get_widget("boton" ,boton);
	add(*fixed);
	fixed->show_all();
	set_titlebar(*headerbar);
	headerbar->show();
	boton->signal_clicked().connect(sigc::mem_fun(*this,&ArdubotonWindow::on_boton_pressed));
	}
	void ArdubotonWindow::on_boton_pressed()
{
    Gtk::MessageDialog dialogo( *this , "Estes es un dialogo de error",false ,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
    int result = dialogo.run();
    if(result == Gtk::RESPONSE_OK)
    {

    }

    char High[1] = {'H'};//Caracter del arduino que enciende el led
    char Low[1] = {'L'};//Caracter del arduino  que apaga  el led
    if(pulsado==true)
    {
    //porniendo el caracter en el arduino
    boton->set_label("OFF");
    sp_nonblocking_write(serialport, High ,1);
    pulsado = false;
    }
    else if(pulsado == false )
    {
    //poniendo el caracter en arduino
    boton->set_label("ON");
    sp_nonblocking_write(serialport,Low,1);
    pulsado = true;
    }
}
    ArdubotonWindow::~ArdubotonWindow()
    {
        fixed->remove(*boton);
        fixed->remove(*label);
        sp_close(serialport);
    }
