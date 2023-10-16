#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <memory>
#include <iostream>

#include "GameObject.hpp"


class Collider2D {
protected:
    int _xCenterPos, _yCenterPos;
    int _boundingBoxX, _boundingBoxY, _boundingBoxWidth, _boundingBoxHeight;
    float _colliderRotation;
    std::shared_ptr<GameObject> _followedGameObject;

public:
    Collider2D(int x, int y, float rotation, std::shared_ptr<GameObject> objectWithColliderToCompare);
    virtual void Update();
    virtual bool CheckCollision(std::shared_ptr<Collider2D> other);
    virtual void UpdateColliderPositionRotation();
    virtual void CalculateBoundingBox();
};

class CircleCollider2D : public Collider2D {
private:
    int radius;

public:
    CircleCollider2D(int x, int y, float rotation, std::shared_ptr<GameObject> objectWithColliderToCompare, int r);
    void CalculateBoundingBox() override;
};

class BoxCollider2D : public Collider2D {
private:
    int width;
    int height;

public:
    BoxCollider2D(int x, int y, float rotation, std::shared_ptr<GameObject> objectWithColliderToCompare, int w, int h);
    void CalculateBoundingBox() override;
};

class ColliderFactory {
public:
    // Create a CircleCollider2D
    static std::shared_ptr<Collider2D> CreateCircleCollider(int x, int y, float rotation, std::shared_ptr<GameObject> objectWithColliderToCompare, int radius) {
        return std::make_shared<CircleCollider2D>(x, y, rotation, objectWithColliderToCompare, radius);
    }

    // Create a BoxCollider2D
    static std::shared_ptr<Collider2D> CreateBoxCollider(int x, int y, float rotation, std::shared_ptr<GameObject> objectWithColliderToCompare, int width, int height) {
        return std::make_shared<BoxCollider2D>(x, y, rotation, objectWithColliderToCompare, width, height);
    }
};
