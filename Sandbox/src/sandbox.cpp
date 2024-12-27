#include <CCommon.h>

class Sandbox : public corecommon::application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

corecommon::application* corecommon::CreateApplication() {
	return new Sandbox();
}