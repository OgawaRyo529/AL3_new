#pragma once
#include "MathUtilityForText.h"
#include "Model.h"
#include "Vector3.h"
#include "WorldTransform.h"
#include "viewProjection.h"
#include"AABB.h"

class MapChipField;

class Player {
public:
	enum class LRDirection {
		kRight,
		kLeft,
	};

	struct CollisionMapInfo {
		bool ceiling = false;
		bool landing = false;
		bool wall = false;
		Vector3 move;
	};
	enum Corner {
		kRighBottom,
		kLeftBottom,
		kRighTop,
		kLeftTop,

		kNumCorner
	};

	///< summary>
	/// 初期化
	///</summary>

	void Initialize(const Vector3& position, ViewProjection* viewProjection);
	///< summary>
	/// 更新
	///</summary>
	void Update();

	///< summary>
	/// 描画
	///</summary>

	void Draw();

	const WorldTransform& GetWorldTransform() const { return worldTransform_; }
	const Vector3& GetVelocity() const { return velocity_; }
	// const Vector3& targetVelocity=target_->GetVelocity();

	/* void SetMapChipField(MapChipField*mapChipField){mapChipField_;}
	 void mapcrash(CollisionMapInfo&info);
	 Vector3 CornerPosition(const Vector3& center,Corner corner);*/
	AABB GetAABB();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャーハンドル
	uint32_t textureHandle_ = 0u;
	ViewProjection* viewProjection_ = nullptr;
	Vector3 velocity_ = {};
	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 0.01f;
	static inline const float kLimitRunSpeed = 2.0f;
	LRDirection lrDirection_ = LRDirection::kRight;
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;
	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;
	static const float Liner;

	bool onGround_ = true;

	// 重力加速度(下方向)
	static inline const float kGravityAcceleration =0.05f;
	// 最大落下速度(下方向)
	static inline const float klimitFallSpeed = 0.2f;
	// ジャンプ初速(上方向)
	static inline const float kJumpAcceleration = 0.7f;

	MapChipField* mapChipField_ = nullptr;

	// キャラクターの当たり判定サイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;

	bool landing_;
};