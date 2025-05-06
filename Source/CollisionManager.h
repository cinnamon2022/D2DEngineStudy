#pragma once
#include <bitset>
#include <unordered_map>

#include "Layer.h"

union CollisionID
{
	struct
	{
		uint32_t left;
		uint32_t right;
	};
	uint64_t id;
};

class Collider;

class CollisionManager
{
public:
	static CollisionManager& GetInstance();

	void Initialize();
	void Update();
	void LateUpdate();
	void Render();

	void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
	void LayerCollision(class Scene* scene, eLayerType row,  eLayerType col);
	void ColliderCollision(Collider* left, Collider* right);
	bool Intersect(Collider* left, Collider* right);

	void AddCollider(Collider* collider);
	void RemoveCollider(Collider* collider);
private:
	std::bitset < (unsigned int)eLayerType::END> m_collisionLayerMatrix[(unsigned int)eLayerType::END] ={};
	std::unordered_map< uint64_t, bool> m_collisionMap = {}; 
};

