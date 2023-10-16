#include "Collider2D.hpp"


// Collider2D class implementation
Collider2D::Collider2D(int x, int y, float rotation, std::shared_ptr<GameObject> followedObject)
    : _xCenterPos(x), _yCenterPos(y), _colliderRotation(rotation), _followedGameObject(followedObject) {
    // Initialize bounding box to the same position as the collider
    _boundingBoxX = x;
    _boundingBoxY = y;
    _boundingBoxWidth = 0;
    _boundingBoxHeight = 0;
}

void Collider2D::Update() {
    UpdateColliderPositionRotation();
    CalculateBoundingBox();
}

void Collider2D::CalculateBoundingBox() {
    // By default, a base Collider2D can be represented by a point, so the bounding box has no width or height.
    _boundingBoxX = _xCenterPos;
    _boundingBoxY = _yCenterPos;
    _boundingBoxWidth = 0;
    _boundingBoxHeight = 0;
}

bool Collider2D::CheckCollision(std::shared_ptr<Collider2D> other) {
    // Perform collision check using bounding boxes
    return (_boundingBoxX + _boundingBoxWidth >= other->_boundingBoxX &&
            _boundingBoxX <= other->_boundingBoxX + other->_boundingBoxWidth &&
            _boundingBoxY + _boundingBoxHeight >= other->_boundingBoxY &&
            _boundingBoxY <= other->_boundingBoxY + other->_boundingBoxHeight);
}

void Collider2D::UpdateColliderPositionRotation() {
    // Update the collider's position and rotation based on the followed GameObject
    _boundingBoxX = _followedGameObject->GetXCenterPos();
    _boundingBoxY = _followedGameObject->GetYCenterPos();
    _colliderRotation = _followedGameObject->GetRotation(); // Update the rotation as well
}

// CircleCollider2D class implementation
CircleCollider2D::CircleCollider2D(int x, int y, float rotation, std::shared_ptr<GameObject> followedObject, int r)
    : Collider2D(x, y, rotation, followedObject), radius(r) {
    CalculateBoundingBox(); // Calculate the bounding box for the circle
}


void CircleCollider2D::CalculateBoundingBox() {
    // Calculate the bounding box for the circle
    _boundingBoxX = _xCenterPos - radius;
    _boundingBoxY = _yCenterPos - radius;
    _boundingBoxWidth = 2 * radius;
    _boundingBoxHeight = 2 * radius;
}

// BoxCollider2D class implementation
BoxCollider2D::BoxCollider2D(int x, int y, float rotation, std::shared_ptr<GameObject> followedObject, int w, int h)
    : Collider2D(x, y, rotation, followedObject), width(w), height(h) {
    CalculateBoundingBox(); // Calculate the bounding box for the box
}

void BoxCollider2D::CalculateBoundingBox() {
    // Calculate the bounding box for the box
    _boundingBoxX = _xCenterPos - width / 2;
    _boundingBoxY = _yCenterPos - height / 2;
    _boundingBoxWidth = width;
    _boundingBoxHeight = height;
}
