#pragma once
#include "core/io/resource.h"
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
	Variant raw_data_to_variant_linux(DataType &data_type, Vector<uint8_t> &data);
	DataType native_to_type_linux(String &data_type);
	String type_to_native_linux(DragDrop::DataType &data_type);
	Vector<String> types_to_natives_linux(Vector<DragDrop::DataType> &data_types);
	static DataType native_to_type(String &data_type);
};


class DragDropEvent : public Resource {
	GDCLASS(DragDropEvent, Resource);

protected:
	Vector2i position;

public:
	Vector2i get_position() const;
	void set_position(Vector2i p_position);

	DragDropEvent() {
	}
};

class UnfinishedDragDropEvent : public DragDropEvent {
	GDCLASS(UnfinishedDragDropEvent, DragDropEvent);

protected:
	Array types;

public:
	Array get_types() const;
	void set_types(Array p_types);

	UnfinishedDragDropEvent() {
	}
};

class DragDropEnter : public UnfinishedDragDropEvent {
	GDCLASS(DragDropEnter, UnfinishedDragDropEvent);
};

class DragDropMotion : public UnfinishedDragDropEvent {
	GDCLASS(DragDropMotion, UnfinishedDragDropEvent);
};

class DragDropExit : public UnfinishedDragDropEvent {
	GDCLASS(DragDropExit, UnfinishedDragDropEvent);
};

class DragDropDone : public DragDropEvent {
	GDCLASS(DragDropDone, DragDropEvent);
public:
	Variant get_data() const;
	DragDrop::DataType get_type() const;
	void set_data(Variant p_data);
	void set_type(DragDrop::DataType p_type);
	DragDropDone() {
	}

protected:
	Variant data;
	DragDrop::DataType type;


};


template <typename T> class DnDMapper {
public:
	static Variant from_raw(const DragDrop::DataType &type, const T &data);
	static T to_raw(const DragDrop::DataType &type, const Variant &var);
};


VARIANT_ENUM_CAST(DragDrop::SystemDropStatus)

VARIANT_ENUM_CAST(DragDrop::DataType)
