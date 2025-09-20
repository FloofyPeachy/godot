#pragma once
#include "core/math/vector2i.h"
#include "core/variant/variant.h"

// Variant, String

class SystemDragData {

	Point2i position;
	String mime_type;
	Variant data;

protected:
	static void _bind_methods();

public:
	// setters/getters
	void set_position(const Point2i &p) { position = p; }
	Point2i get_position() const { return position; }

	void set_mime_type(const String &p) { mime_type = p; }
	String get_mime_type() const { return mime_type; }

	void set_data(const Variant &p) { data = p; }
	Variant get_data() const { return data; }

	SystemDragData() {}
};

