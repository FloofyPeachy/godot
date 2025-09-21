#pragma once
#include "core/string/ustring.h"
#include "core/templates/rb_set.h"
#include "core/variant/binder_common.h"

class DragDrop {

public:
	inline static DragDrop *singleton = nullptr;
	static void create() { singleton = memnew(DragDrop); }
	static void free() {
		memdelete(singleton);
		singleton = nullptr;
	}

	_FORCE_INLINE_ static DragDrop *get_singleton() { return singleton; }

public:
	enum DataType {
		TEXT,
		FILES,
		URI,
		IMAGE,
		CUSTOM,
		UNKNOWN
	};
public:
	enum SystemDropStatus {
		DRAG_ENTER,
		DRAG_MOTION,
		DRAG_EXIT,
		DRAG_DROP,
	};

	DataType map_data_type_linux(String &data_type);
	DataType native_to_type_win(String &data_type);
	DataType native_to_type_mac(String &data_type);
	Vector<DragDrop::DataType> natives_to_types_linux(HashSet<String> &data_types);
	DataType native_to_type_linux(String &data_type);
	String type_to_native_linux(DragDrop::DataType& data_type);
	Vector<String> types_to_natives_linux(Vector<DragDrop::DataType> &data_types);
	static DataType native_to_type(String &data_type);
};

VARIANT_ENUM_CAST(DragDrop::SystemDropStatus)
VARIANT_ENUM_CAST(DragDrop::DataType)
