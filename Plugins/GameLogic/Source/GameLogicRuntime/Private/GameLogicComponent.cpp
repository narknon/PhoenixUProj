#include "GameLogicComponent.h"

class AActor;
class UGameLogicExpression;
class UGameLogicObject;
class UGameLogicVar_Bool;
class UGameLogicVar_Float;
class UGameLogicVar_Int32;

void UGameLogicComponent::SetInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName, int32 Value) {
}

void UGameLogicComponent::SetInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Value) {
}

void UGameLogicComponent::SetFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName, float Value) {
}

void UGameLogicComponent::SetFloatVariable(FName_GameLogicVarFloat FloatVarName, float Value) {
}

void UGameLogicComponent::SetBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName, bool bValue) {
}

void UGameLogicComponent::SetBoolVariable(FName_GameLogicVarBool BoolVarName, bool bValue) {
}

void UGameLogicComponent::IncrementInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName, int32 Delta) {
}

void UGameLogicComponent::IncrementInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Delta) {
}

UGameLogicVar_Int32* UGameLogicComponent::GetReferenceToInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName) {
    return NULL;
}

UGameLogicVar_Int32* UGameLogicComponent::GetReferenceToInt32Variable(FName_GameLogicVarInt32 Int32VarName) {
    return NULL;
}

UGameLogicVar_Float* UGameLogicComponent::GetReferenceToFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName) {
    return NULL;
}

UGameLogicVar_Float* UGameLogicComponent::GetReferenceToFloatVariable(FName_GameLogicVarFloat FloatVarName) {
    return NULL;
}

UGameLogicExpression* UGameLogicComponent::GetReferenceToExpression_OnActor(const AActor* InActor, FName_GameLogicExpression ExpressionName) {
    return NULL;
}

UGameLogicExpression* UGameLogicComponent::GetReferenceToExpression(FName_GameLogicExpression ExpressionName) {
    return NULL;
}

UGameLogicVar_Bool* UGameLogicComponent::GetReferenceToBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName) {
    return NULL;
}

UGameLogicVar_Bool* UGameLogicComponent::GetReferenceToBoolVariable(FName_GameLogicVarBool BoolVarName) {
    return NULL;
}

int32 UGameLogicComponent::GetInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName) {
    return 0;
}

int32 UGameLogicComponent::GetInt32Variable(FName_GameLogicVarInt32 Int32VarName) {
    return 0;
}

UGameLogicObject* UGameLogicComponent::GetGameLogicObject() {
    return NULL;
}

float UGameLogicComponent::GetFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName) {
    return 0.0f;
}

float UGameLogicComponent::GetFloatVariable(FName_GameLogicVarFloat FloatVarName) {
    return 0.0f;
}

bool UGameLogicComponent::GetExpression_OnActor(const AActor* InActor, FName_GameLogicExpression ExpressionName) {
    return false;
}

bool UGameLogicComponent::GetExpression(FName_GameLogicExpression ExpressionName) {
    return false;
}

bool UGameLogicComponent::GetBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName) {
    return false;
}

bool UGameLogicComponent::GetBoolVariable(FName_GameLogicVarBool BoolVarName) {
    return false;
}

UGameLogicComponent::UGameLogicComponent() {
    this->GameLogicObject = NULL;
}

