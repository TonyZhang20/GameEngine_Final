#include "GameObject_Null.h"
#include "GraphicsObject_Null.h"

namespace Azul
{
	GameObject_NULL::GameObject_NULL()
	{
		this->poGraphicsObject = new GraphicsObject_Null();
	}

	GameObject_NULL::~GameObject_NULL()
	{

	}

	void GameObject_NULL::Update(float)
	{
		//Do Nothing
	}
}

