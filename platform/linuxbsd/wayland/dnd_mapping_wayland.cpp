#include "dnd_mapping_wayland.h"

void DnDMappingWayland::initialize() {
	dnd_mime_map[DragDrop::DataType::FILES] = {
		"text/uri-list"
	};
}

DragDrop::DataType DnDMappingWayland::get_type(const String &mime) {
	for (const KeyValue<DragDrop::DataType, Vector<String>> &E : dnd_mime_map) {
		for (const String &m : E.value) {
			if (m == mime) {
				return E.key;
			}
		}
	}
	return DragDrop::DataType::UNKNOWN; // fallback
}

Vector<DragDrop::DataType> DnDMappingWayland::get_types(const Vector<String> &mimes) {
	Vector<DragDrop::DataType> result;
	for (String mime : mimes) {
		result.append(DnDMappingWayland::get_type(mime));
	}
	return result;
}

Vector<DragDrop::DataType> DnDMappingWayland::get_types(const HashSet<String> &mimes) {
	Vector<DragDrop::DataType> result;
	for (String mime : mimes) {
		result.append(DnDMappingWayland::get_type(mime));
	}
	return result;
}

Vector<DragDrop::DataType> DnDMappingWayland::get_types_array(const Array &mimes) {
	Vector<DragDrop::DataType> result;
	for (String mime : mimes) {
		result.append(DnDMappingWayland::get_type(mime));
	}
	return result;
}


Array DnDMappingWayland::get_types_array(const HashSet<String> &mimes) {
	Array result;
	for (String mime : mimes) {
		result.append(DnDMappingWayland::get_type(mime));
	}
	return result;
}


String DnDMappingWayland::get_native(const DragDrop::DataType &type) {
	if (!dnd_mime_map.has(type)) {
		return String(); // empty string if not found
	}

	const Vector<String> &mimes = dnd_mime_map[type];
	if (mimes.is_empty()) {
		return String();
	}

	return mimes[0]; // just return the first "canonical" MIME string
}

Vector<String> DnDMappingWayland::get_natives(const Vector<DragDrop::DataType> &types) {
	Vector<String> result;
	for (DragDrop::DataType type : types) {
		result.append(DnDMappingWayland::get_native(type));
	}
	return result;
}

Vector<String> DnDMappingWayland::get_natives(const HashSet<DragDrop::DataType> &types) {
	Vector<String> result;
	for (DragDrop::DataType type : types) {
		result.append(DnDMappingWayland::get_native(type));
	}
	return result;
}

Array DnDMappingWayland::get_natives_array(const HashSet<DragDrop::DataType> &types) {
	Array result;
	for (DragDrop::DataType type : types) {
		result.append(DnDMappingWayland::get_native(type));
	}
	return result;
}


Vector<uint8_t> DnDMappingWayland::native_from_variant(const DragDrop::DataType &type, const Variant &variant) {

}

Variant DnDMappingWayland::variant_from_native(const DragDrop::DataType &type, Vector<uint8_t> &native) {
	switch (type) {
		case DragDrop::DataType::FILES: {
			Vector<String> almostResult;
			Array result;

			almostResult = String::utf8((const char *)native.ptr(), native.size()).split("\r\n", false);
			for (int i = 0; i < almostResult.size(); i++) {
				almostResult.write[i] = almostResult[i].replace("file://", "").uri_file_decode();
			}

			for (String almost_result : almostResult) {
				result.append(almost_result);
			}

			return result;
		}
	}
	return Variant();
}
