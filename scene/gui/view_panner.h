/*************************************************************************/
/*  view_panner.h                                                        */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef VIEW_PANNER_H
#define VIEW_PANNER_H

#include "core/object/ref_counted.h"

class InputEvent;
class Shortcut;

class ViewPanner : public RefCounted {
	GDCLASS(ViewPanner, RefCounted);

public:
	enum ControlScheme {
		SCROLL_ZOOMS,
		SCROLL_PANS,
	};

private:
	bool is_dragging = false;
	bool pan_key_pressed = false;
	bool enable_rmb = false;
	bool simple_panning_enabled = false;

	Ref<Shortcut> pan_view_shortcut;

	Callable scroll_callback;
	Callable pan_callback;
	Callable zoom_callback;

	void callback_helper(Callable p_callback, Vector<Variant> p_args);
	ControlScheme control_scheme = SCROLL_ZOOMS;

public:
	void set_callbacks(Callable p_scroll_callback, Callable p_pan_callback, Callable p_zoom_callback);
	void set_control_scheme(ControlScheme p_scheme);
	void set_enable_rmb(bool p_enable);
	void set_pan_shortcut(Ref<Shortcut> p_shortcut);
	void set_simple_panning_enabled(bool p_enabled);

	void setup(ControlScheme p_scheme, Ref<Shortcut> p_shortcut, bool p_simple_panning);

	bool is_panning() const;

	bool gui_input(const Ref<InputEvent> &p_ev, Rect2 p_canvas_rect = Rect2());
	void release_pan_key();

	ViewPanner();
};

#endif // VIEW_PANNER_H
