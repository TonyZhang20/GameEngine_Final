#include "GameObjectNode.h"

namespace Azul
{

	GameObjectNode::GameObjectNode()
		: PCSNode(), pGameObject(nullptr)
	{
		this->privClear();
	}

	GameObjectNode::~GameObjectNode()
	{
		this->privClear();
	}

	void GameObjectNode::Update(float deltaTime)
	{
		assert(pGameObject);
		this->pGameObject->Update(deltaTime);
	}

	void GameObjectNode::Draw()
	{
		assert(pGameObject);
		this->pGameObject->Draw();
	}

	void GameObjectNode::Set(const char* name, GameObject* _obj)
	{
		assert(_obj);
	
		this->pGameObject = _obj;
		this->SetName(name);
	}

	GameObject* GameObjectNode::GetGameObject()
	{
		return this->pGameObject;
	}

	bool GameObjectNode::Compare(PCSNode* pTargetNode)
	{
		GameObjectNode* compare = (GameObjectNode*)pTargetNode;
		return this->pGameObject == compare->GetGameObject();
	}

	void GameObjectNode::privClear()
	{
		if (this->pGameObject)
		{
			delete this->pGameObject;
		}

		this->pGameObject = nullptr;
	}

}

