/*
 * File: example.cpp
 * Purpose: Rope example.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#include "texteditor.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	TTextEditor	 win;

	win.show();

	return app.exec();
}
