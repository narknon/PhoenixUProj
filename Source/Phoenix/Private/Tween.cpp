#include "Tween.h"

class UObject;
class UTween;

UTween* UTween::TweenVector2DPropertyToEnd(UObject* ObjectIn, FName PropertyNameIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenVector2DPropertyFromStartToEnd(UObject* ObjectIn, FName PropertyNameIn, FVector2D StartIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenTransformPropertyToEnd(UObject* ObjectIn, ETransformProperty TransformProperty, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenTransformPropertyFromStartToEnd(UObject* ObjectIn, ETransformProperty TransformProperty, FVector2D StartIn, FVector2D EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenIntPropertyToEnd(UObject* ObjectIn, FName ProertyNameIn, int32 EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenIntPropertyFromStartToEnd(UObject* ObjectIn, FName ProertyNameIn, int32 StartIn, int32 EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenFloatPropertyToEnd(UObject* ObjectIn, FName ProertyNameIn, float EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenFloatPropertyFromStartToEnd(UObject* ObjectIn, FName ProertyNameIn, float StartIn, float EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenColorPropertyToEnd(UObject* ObjectIn, FName PropertyNameIn, FLinearColor EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::TweenColorPropertyFromStartToEnd(UObject* ObjectIn, FName PropertyNameIn, FLinearColor StartIn, FLinearColor EndIn, float Duration, EEasingFunction EasingFunctionIn) {
    return NULL;
}

UTween* UTween::Play() {
    return NULL;
}

bool UTween::IsPlaying() {
    return false;
}

UTween* UTween::ConstructTween() {
    return NULL;
}

UTween::UTween() {
    this->EasingCurve = NULL;
}

