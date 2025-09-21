#include "drag_drop.h"
#include "drag_drop.h"

#include "core/string/ustring.h"
#include "core/templates/hash_map.h"
#include "core/templates/rb_set.h"
#include "core/templates/tuple.h"
HashMap<String, DragDrop::DataType> data_types_linux = {
	{"text/uri-list", DragDrop::DataType::FILES}
};

HashMap<DragDrop::DataType, String> data_types_linux_reverse = {
	{DragDrop::DataType::FILES, "text/uri-list"}
};





DragDrop::DataType DragDrop::native_to_type_linux(String &data_type) {
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
}




