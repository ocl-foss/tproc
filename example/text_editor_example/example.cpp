// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/tproc

#include "texteditor.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	TTextEditor	 win;

	win.show();

	return app.exec();
}
