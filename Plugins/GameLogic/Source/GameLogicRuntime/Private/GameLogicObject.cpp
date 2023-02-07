#include "GameLogicObject.h"

class UGameLogicExpression;
class UGameLogicObject;
class UGameLogicPropositional_Bitfield;
class UGameLogicPropositional_Enum;
class UGameLogicPropositional_Float;
class UGameLogicPropositional_Int32;
class UGameLogicPropositional_String;
class UGameLogicVar_Bitfield;
class UGameLogicVar_Bool;
class UGameLogicVar_Enum;
class UGameLogicVar_Float;
class UGameLogicVar_Int32;
class UGameLogicVar_String;
class UGameLogicVar_Timer;
class UObject;
class UWorld;

void UGameLogicObject::XOrBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue) {
}

UGameLogicObject* UGameLogicObject::SpawnGameLogicObject(UObject* Outer, UWorld* World) {
    return NULL;
}

void UGameLogicObject::SetTimerVariablePauseAndValue(FName_GameLogicVarTimer TimerVarName, bool bFlag, float Value) {
}

void UGameLogicObject::SetTimerVariablePause(FName_GameLogicVarTimer TimerVarName, bool bFlag) {
}

void UGameLogicObject::SetTimerVariable(FName_GameLogicVarTimer TimerVarName, float Value) {
}

void UGameLogicObject::SetStringVariable(FName_GameLogicVarString StringVarName, const FString& Value) {
}

void UGameLogicObject::SetInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Value) {
}

void UGameLogicObject::SetFloatVariable(FName_GameLogicVarFloat FloatVarName, float Value) {
}

void UGameLogicObject::SetEnumVariableWithU8(FName_GameLogicVarEnum EnumVarName, uint8 Value) {
}

void UGameLogicObject::SetEnumVariable(FGameLogicVarAndValueEnum VarAndValue) {
}

void UGameLogicObject::SetBoolVariable(FName_GameLogicVarBool BoolVarName, bool bValue) {
}

void UGameLogicObject::SetBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue) {
}

void UGameLogicObject::OrBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue) {
}

void UGameLogicObject::IncrementInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Delta) {
}

float UGameLogicObject::GetTimerVariable(FName_GameLogicVarTimer TimerVarName) {
    return 0.0f;
}

FString UGameLogicObject::GetStringVariable(FName_GameLogicVarString StringVarName) {
    return TEXT("");
}

bool UGameLogicObject::GetStringPropositional(FName_GameLogicPropString PropName) {
    return false;
}

UGameLogicVar_Timer* UGameLogicObject::GetReferenceToTimerVariable(FName_GameLogicVarTimer TimerVarName) {
    return NULL;
}

UGameLogicVar_String* UGameLogicObject::GetReferenceToStringVariable(FName_GameLogicVarString StringVarName) {
    return NULL;
}

UGameLogicPropositional_String* UGameLogicObject::GetReferenceToPropString(FName_GameLogicPropString PropName) {
    return NULL;
}

UGameLogicPropositional_Int32* UGameLogicObject::GetReferenceToPropInt32(FName_GameLogicPropInt32 PropName) {
    return NULL;
}

UGameLogicPropositional_Float* UGameLogicObject::GetReferenceToPropFloat(FName_GameLogicPropFloat PropName) {
    return NULL;
}

UGameLogicPropositional_Enum* UGameLogicObject::GetReferenceToPropEnum(FName_GameLogicPropEnum PropName) {
    return NULL;
}

UGameLogicPropositional_Bitfield* UGameLogicObject::GetReferenceToPropBitfield(FName_GameLogicPropBitfield PropName) {
    return NULL;
}

UGameLogicVar_Int32* UGameLogicObject::GetReferenceToInt32Variable(FName_GameLogicVarInt32 Int32VarName) {
    return NULL;
}

UGameLogicVar_Float* UGameLogicObject::GetReferenceToFloatVariable(FName_GameLogicVarFloat FloatVarName) {
    return NULL;
}

UGameLogicExpression* UGameLogicObject::GetReferenceToExpression(FName_GameLogicExpression ExpressionName) {
    return NULL;
}

UGameLogicVar_Enum* UGameLogicObject::GetReferenceToEnumVariable(FName_GameLogicVarEnum EnumVarName) {
    return NULL;
}

UGameLogicVar_Bool* UGameLogicObject::GetReferenceToBoolVariable(FName_GameLogicVarBool BoolVarName) {
    return NULL;
}

UGameLogicVar_Bitfield* UGameLogicObject::GetReferenceToBitfieldVariable(FName_GameLogicVarBitfield BitfieldVarName) {
    return NULL;
}

int32 UGameLogicObject::GetInt32Variable(FName_GameLogicVarInt32 Int32VarName) {
    return 0;
}

bool UGameLogicObject::GetInt32Propositional(FName_GameLogicPropInt32 PropName) {
    return false;
}

float UGameLogicObject::GetFloatVariable(FName_GameLogicVarFloat FloatVarName) {
    return 0.0f;
}

bool UGameLogicObject::GetFloatPropositional(FName_GameLogicPropFloat PropName) {
    return false;
}

bool UGameLogicObject::GetExpression(FName_GameLogicExpression ExpressionName) {
    return false;
}

uint8 UGameLogicObject::GetEnumVariable(FName_GameLogicVarEnum EnumVarName) {
    return 0;
}

bool UGameLogicObject::GetEnumPropositional(FName_GameLogicPropEnum PropName) {
    return false;
}

bool UGameLogicObject::GetBoolVariable(FName_GameLogicVarBool BoolVarName) {
    return false;
}

FBitfield256 UGameLogicObject::GetBitfieldVariable(FName_GameLogicVarBitfield BitfieldVarName) {
    return FBitfield256{};
}

bool UGameLogicObject::GetBitfieldPropositional(FName_GameLogicPropBitfield PropName) {
    return false;
}

UGameLogicObject* UGameLogicObject::DestroyGameLogicObject(UGameLogicObject* InGameLogicObject) {
    return NULL;
}

void UGameLogicObject::BitfieldVariable_SetBit(FGameLogicVarAndBitBitfield BitfieldVarName) {
}

void UGameLogicObject::BitfieldVariable_SetAllBits(FName_GameLogicVarBitfield VarName) {
}

void UGameLogicObject::BitfieldVariable_FlipBit(FGameLogicVarAndBitBitfield BitfieldVarName) {
}

void UGameLogicObject::BitfieldVariable_ClearBit(FGameLogicVarAndBitBitfield BitfieldVarName) {
}

void UGameLogicObject::AndBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue) {
}

UGameLogicObject::UGameLogicObject() {
}

