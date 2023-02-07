#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Bitfield256.h"
#include "GameLogicVarAndBitBitfield.h"
#include "GameLogicVarAndValueBitfield.h"
#include "GameLogicVarAndValueEnum.h"
#include "Name_GameLogicExpression.h"
#include "Name_GameLogicPropBitfield.h"
#include "Name_GameLogicPropEnum.h"
#include "Name_GameLogicPropFloat.h"
#include "Name_GameLogicPropInt32.h"
#include "Name_GameLogicPropString.h"
#include "Name_GameLogicVarBitfield.h"
#include "Name_GameLogicVarBool.h"
#include "Name_GameLogicVarEnum.h"
#include "Name_GameLogicVarFloat.h"
#include "Name_GameLogicVarInt32.h"
#include "Name_GameLogicVarString.h"
#include "Name_GameLogicVarTimer.h"
#include "GameLogicObject.generated.h"

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
class UWorld;

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicObject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Bool*> InstancedBoolVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Int32*> InstancedInt32Vars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Float*> InstancedFloatVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Timer*> InstancedTimerVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Enum*> InstancedEnumVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_Bitfield*> InstancedBitfieldVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicVar_String*> InstancedStringVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicPropositional_Int32*> InstancedPropInt32s;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicPropositional_Float*> InstancedPropFloats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicPropositional_Enum*> InstancedPropEnums;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicPropositional_Bitfield*> InstancedPropBitfields;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicPropositional_String*> InstancedPropStrings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameLogicExpression*> InstancedExpressions;
    
    UGameLogicObject();
    UFUNCTION(BlueprintCallable)
    void XOrBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicObject* SpawnGameLogicObject(UObject* Outer, UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    void SetTimerVariablePauseAndValue(FName_GameLogicVarTimer TimerVarName, bool bFlag, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTimerVariablePause(FName_GameLogicVarTimer TimerVarName, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetTimerVariable(FName_GameLogicVarTimer TimerVarName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetStringVariable(FName_GameLogicVarString StringVarName, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    void SetInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetFloatVariable(FName_GameLogicVarFloat FloatVarName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetEnumVariableWithU8(FName_GameLogicVarEnum EnumVarName, uint8 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetEnumVariable(FGameLogicVarAndValueEnum VarAndValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBoolVariable(FName_GameLogicVarBool BoolVarName, bool bValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue);
    
    UFUNCTION(BlueprintCallable)
    void OrBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue);
    
    UFUNCTION(BlueprintCallable)
    void IncrementInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    float GetTimerVariable(FName_GameLogicVarTimer TimerVarName);
    
    UFUNCTION(BlueprintCallable)
    FString GetStringVariable(FName_GameLogicVarString StringVarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetStringPropositional(FName_GameLogicPropString PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Timer* GetReferenceToTimerVariable(FName_GameLogicVarTimer TimerVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_String* GetReferenceToStringVariable(FName_GameLogicVarString StringVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicPropositional_String* GetReferenceToPropString(FName_GameLogicPropString PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicPropositional_Int32* GetReferenceToPropInt32(FName_GameLogicPropInt32 PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicPropositional_Float* GetReferenceToPropFloat(FName_GameLogicPropFloat PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicPropositional_Enum* GetReferenceToPropEnum(FName_GameLogicPropEnum PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicPropositional_Bitfield* GetReferenceToPropBitfield(FName_GameLogicPropBitfield PropName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Int32* GetReferenceToInt32Variable(FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Float* GetReferenceToFloatVariable(FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicExpression* GetReferenceToExpression(FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Enum* GetReferenceToEnumVariable(FName_GameLogicVarEnum EnumVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Bool* GetReferenceToBoolVariable(FName_GameLogicVarBool BoolVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Bitfield* GetReferenceToBitfieldVariable(FName_GameLogicVarBitfield BitfieldVarName);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInt32Variable(FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetInt32Propositional(FName_GameLogicPropInt32 PropName);
    
    UFUNCTION(BlueprintCallable)
    float GetFloatVariable(FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetFloatPropositional(FName_GameLogicPropFloat PropName);
    
    UFUNCTION(BlueprintCallable)
    bool GetExpression(FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    uint8 GetEnumVariable(FName_GameLogicVarEnum EnumVarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetEnumPropositional(FName_GameLogicPropEnum PropName);
    
    UFUNCTION(BlueprintCallable)
    bool GetBoolVariable(FName_GameLogicVarBool BoolVarName);
    
    UFUNCTION(BlueprintCallable)
    FBitfield256 GetBitfieldVariable(FName_GameLogicVarBitfield BitfieldVarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetBitfieldPropositional(FName_GameLogicPropBitfield PropName);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicObject* DestroyGameLogicObject(UGameLogicObject* InGameLogicObject);
    
    UFUNCTION(BlueprintCallable)
    void BitfieldVariable_SetBit(FGameLogicVarAndBitBitfield BitfieldVarName);
    
    UFUNCTION(BlueprintCallable)
    void BitfieldVariable_SetAllBits(FName_GameLogicVarBitfield VarName);
    
    UFUNCTION(BlueprintCallable)
    void BitfieldVariable_FlipBit(FGameLogicVarAndBitBitfield BitfieldVarName);
    
    UFUNCTION(BlueprintCallable)
    void BitfieldVariable_ClearBit(FGameLogicVarAndBitBitfield BitfieldVarName);
    
    UFUNCTION(BlueprintCallable)
    void AndBitfieldVariable(FGameLogicVarAndValueBitfield VarAndValue);
    
};

