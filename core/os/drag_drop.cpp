#include "drag_drop.h"
#include "drag_drop.h"
#include "drag_drop.h"

#include "core/string/ustring.h"
#include "core/templates/hash_map.h"
#include "core/templates/rb_set.h"
#include "core/templates/tuple.h"


Vector2i DragDropEvent::get_position() const {
	return position;
}

void DragDropEvent::set_position(Vector2i p_position) {
	position = p_position;
}

Array UnfinishedDragDropEvent::get_types() const {
	return types;
}

void UnfinishedDragDropEvent::set_types(Array p_types) {
	types = p_types;
}

Variant DragDropDone::get_data() const {
	return data;
}

void DragDropDone::set_data(Variant p_data) {
	data = p_data;
}

DragDrop::DataType DragDropDone::get_type() const {
	return type;
}

void DragDropDone::set_type(DragDrop::DataType p_type) {
	type = p_type;
}


/*HashMap<String, DragDrop::DataType> data_types_linux = {
	{"text/uri-list", DragDrop::DataType::FILES}
};

HashMap<DragDrop::DataType, String> data_types_linux_reverse = {
	{DragDrop::DataType::FILES, "text/uri-list"}
};


Variant DragDrop::raw_data_to_variant_linux(DragDrop::DataType &data_type, Vector<uint8_t> &data) {
	switch (data_type) {
		case DataType::FILES: {


		}
	}
}

DragDrop::DataType DragDrop::native_to_type_linux(String& data_type) {
	if (data_types_linux.has(data_type)) {
		return data_types_linux.get(data_type);
	} else {
		return DragDrop::DataType::UNKNOWN;
	}
}

Vector<DragDrop::DataType> DragDrop::natives_to_types_linux(HashSet<String> &data_types) {
	Vector<DragDrop::DataType> set;

	for (String data_type : data_types) {
		set.append(DragDrop::native_to_type_linux(data_type));
	}

	return set;
}



String DragDrop::type_to_native_linux(DragDrop::DataType &data_type) {
	if (data_types_linux_reverse.has(data_type)) {
		return data_types_linux_reverse.get(data_type);
	} else {
		return "unknown";
	}
}

Vector<String> DragDrop::types_to_natives_linux(Vector<DragDrop::DataType> &data_types) {
	Vector<String> set;

	for (DragDrop::DataType data_type : data_types) {
		set.append(DragDrop::type_to_native_linux(data_type));
	}

	return set;
}*/




