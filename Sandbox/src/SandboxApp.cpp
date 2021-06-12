#include <Min.h>

class SandBox : public Min::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

Min::Application* Min::CreateApplication()
{
	return new SandBox();
}