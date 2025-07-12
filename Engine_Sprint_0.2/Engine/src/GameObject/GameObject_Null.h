#ifndef GAME_OBJECT_NULL
#define GAME_OBJECT_NULL

#include "GameObject.h"

namespace Azul
{
	class GameObject_NULL : public GameObject
	{
	public:
		GameObject_NULL();
		GameObject_NULL(const GameObject&) = delete;
		GameObject_NULL& operator = (const GameObject_NULL&) = delete;
		~GameObject_NULL();

		void Update(float deltaTime) override;

	};
}



#endif