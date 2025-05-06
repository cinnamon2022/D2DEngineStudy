﻿#include "CollisionManager.h"

#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Collider.h"
#include "Transform.h"

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
	// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID 세팅
	CollisionID id = {};
	id.left = left->GetID();
	id.right = right->GetID();

	// 이전 충돌 정보를 검색한다.
	// 만약에 충돌정보가 없는 상태라면
	// 충돌정보를 생성해준다.

	auto iter = m_collisionMap.find(id.id);
	if (iter == m_collisionMap.end())
	{
		m_collisionMap.insert(std::make_pair(id.id, false));
		iter = m_collisionMap.find(id.id);
	}

	// 충돌 체크를 해준다
	if (Intersect(left, right))
	{
		//최초 충돌  
		if (iter->second == false)
		{
			left->OnCollisionEnter(right);
			right->OnCollisionEnter(left);
			iter->second = true;
		}
		else // 이미 충돌 중
		{
			left->OnCollisionStay(right);
			right->OnCollisionStay(left);
		}
	}
	else
	{
		//충돌을 하지 않은 상태
		if (iter->second == true)
		{
			left->OnCollisionExit(right);
			right->OnCollisionExit(left);

			iter->second = false;
		}
	}
}

bool CollisionManager::Intersect(Collider* left, Collider* right)
{
	Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
	Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

	DirectX::SimpleMath::Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
	DirectX::SimpleMath::Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

	// size 1,1 일 기본크기가 100픽셀
	DirectX::SimpleMath::Vector2 leftSize = left->GetSize() * 100.0f;
	DirectX::SimpleMath::Vector2 rightSize = right->GetSize() * 100.0f;

	//AABB 충돌
	if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
		&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
	{
		return true;
	}

	return false;
}

void CollisionManager::AddCollider(Collider* collider)
{
}

void CollisionManager::RemoveCollider(Collider* collider)
{
}
