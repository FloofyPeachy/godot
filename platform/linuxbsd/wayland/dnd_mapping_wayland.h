#pragma once
#include "core/os/drag_drop.h"
#include "core/templates/hash_map.h"

class DnDMappingWayland {
	DnDMappingWayland() {}
	static inline HashMap<DragDrop::DataType, Vector<String>> dnd_mime_map;
public:
	static void initialize();

	static DragDrop::DataType get_type(const String& mime);
	static Vector<DragDrop::DataType> get_types(const Vector<String>& mimes);
	static Vector<DragDrop::DataType> get_types(const HashSet<String> &mimes);
	static Vector<DragDrop::DataType> get_types_array(const Array &mimes);
	static Array get_types_array(const HashSet<String> &mimes);

	static String get_native(const DragDrop::DataType& type);
	static Vector<String> get_natives(const Vector<DragDrop::DataType>& types);
	static Vector<String> get_natives(const HashSet<DragDrop::DataType> &types);
	static Array get_natives_array(const HashSet<DragDrop::DataType>& types);

	static Vector<uint8_t> native_from_variant(const DragDrop::DataType& type, const Variant& variant);
	static Variant variant_from_native(const DragDrop::DataType& type, Vector<uint8_t>& native);
};
