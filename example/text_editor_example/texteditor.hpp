/*
 * File: qt_widget.hpp
 * Purpose: Minimal text editor widget example using tproc rope.
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#ifndef TPROC_EXAMPLE_QT_WIDGET_HPP
#define TPROC_EXAMPLE_QT_WIDGET_HPP

#include <ocl/tproc/rope.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <QtWidgets>
#include <QApplication>

#ifndef STANDALONE

using namespace ocl;
using namespace boost;

#else

using namespace boost;

#endif

class TTextEditor;

class TTextEditor : public QMainWindow
{
	Q_OBJECT

public:
	using rope_type	  = tproc::crope;
	using size_type	  = rope_type::size_type;
	using string_view = std::string_view;

	TTextEditorWidget() = delete;

	TTextEditor(string_view text, TTextEditorDelegate* del)
		: buffer_(text), delegate_(del)
	{
	}

	virtual ~TTextEditor() = default;

private:
	rope_type buffer_;
};

#endif
