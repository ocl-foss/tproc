// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss/tproc

#include "config.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QMainWindow	 main_win;

	auto mainWidget = new QWidget;
	main_win.setCentralWidget(mainWidget);

	QBoxLayout* bl = new QBoxLayout(QBoxLayout::TopToBottom, mainWidget);
	QTextEdit*	t  = new QTextEdit;

	bl->addWidget(t);

	main_win.show();

	auto	ret	 = app.exec();
	QString text = t->toPlainText();

	ocl::tproc::crope* rope	 = new ::ocl::tproc::crope{{text.toStdString()}};
	ocl::tproc::crope* rope2 = new ::ocl::tproc::crope{{text.toStdString()}};
	ocl::tproc::crope* rope3 = new ::ocl::tproc::crope{{text.toStdString()}};

	rope->concat(rope2);
	rope2->concat(rope3);

	std::cout << *rope;
}
