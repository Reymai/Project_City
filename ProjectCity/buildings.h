#pragma once
class Buildings {
private:
	enum class buildings : unsigned {
		HOUSE,
		COMERCIAL,
		INDUSTRIAL
	};
public:
	Buildings();
	~Buildings();
};

