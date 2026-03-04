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
#include <QWidget>
#include <QApplication>

#ifndef STANDALONE

using namespace ocl;
using namespace boost;

#else

using namespace boost;

#endif

class TTextEditorWidget;
class TTextEditorWindow;
class TTextEditorDelegate;

class TTextEditorWidget : public QWidget
{
    Q_OBJECT

public:
	using rope_type  = tproc::crope;
	using size_type  = rope_type::size_type;
	using string_view = std::string_view;

    TTextEditorWidget() = delete;

	TTextEditorWidget(string_view text, TTextEditorDelegate* del)
		: buffer_(text), delegate_(del)
	{
	}

    virtual ~TTextEditorWidget() = default;

private:
	rope_type buffer_;
    std::weak_ptr<TTextEditorDelegate> delegate_:
};

#endif
