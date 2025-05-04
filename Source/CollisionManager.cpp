#include "CollisionManager.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Collider.h"

CollisionManager& CollisionManager::GetInstance()
{
	static CollisionManager instance;
	return instance;
}

void CollisionManager::Initialize()
{
}

void CollisionManager::Update()
{
	Scene* scene = SceneManager::GetActiveScene();
	for (UINT row = 0; row < (UINT)eLayerType::END; row++)
	{
		for (UINT col = 0; col < (UINT)eLayerType::END; col++)
		{
			if (m_collisionLayerMatrix[row][col] == true)
			{
				LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}
		}
	}
}

void CollisionManager::LateUpdate()
{
}

void CollisionManager::Render()
{
}

void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
{
	// 유니티에서 제공하는 충돌체크를 본따서 만듦

	int row = 0;
	int col = 0;

	if (left<=right)
	{
		row = left;
		col = right;
	}
	else
	{
		row = right;
		col = left;
	}

	m_collisionLayerMatrix[row][col] = enable;
}

void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
{
	const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
	const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

	for (GameObject* left : lefts)
	{
		Collider* leftCol = left->GetComponent<Collider>();
		if (leftCol == nullptr)
			continue;

		for (GameObject* right : rights)
		{
			Collider* rightCol = right->GetComponent<Collider>();
			if (rightCol == nullptr)
				continue;
			if (left == right)
				continue;

			ColliderCollision(leftCol, rightCol);
		}

	}
}

void CollisionManager::ColliderCollision(Collider* left, Collider* right)
{

}

void CollisionManager::AddCollider(Collider* collider)
{
}

void CollisionManager::RemoveCollider(Collider* collider)
{
}
