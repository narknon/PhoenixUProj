#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Name_GameLogicExpression.h"
#include "Name_GameLogicVarBool.h"
#include "Name_GameLogicVarFloat.h"
#include "Name_GameLogicVarInt32.h"
#include "GameLogicComponent.generated.h"

class AActor;
class UGameLogicExpression;
class UGameLogicObject;
class UGameLogicVar_Bool;
class UGameLogicVar_Float;
class UGameLogicVar_Int32;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GAMELOGICRUNTIME_API UGameLogicComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameLogicObject* GameLogicObject;
    
public:
    UGameLogicComponent();
    UFUNCTION(BlueprintCallable)
    static void SetInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetFloatVariable(FName_GameLogicVarFloat FloatVarName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName, bool bValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBoolVariable(FName_GameLogicVarBool BoolVarName, bool bValue);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName, int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    void IncrementInt32Variable(FName_GameLogicVarInt32 Int32VarName, int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicVar_Int32* GetReferenceToInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Int32* GetReferenceToInt32Variable(FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicVar_Float* GetReferenceToFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Float* GetReferenceToFloatVariable(FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicExpression* GetReferenceToExpression_OnActor(const AActor* InActor, FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicExpression* GetReferenceToExpression(FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    static UGameLogicVar_Bool* GetReferenceToBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicVar_Bool* GetReferenceToBoolVariable(FName_GameLogicVarBool BoolVarName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetInt32Variable_OnActor(const AActor* InActor, FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    int32 GetInt32Variable(FName_GameLogicVarInt32 Int32VarName);
    
    UFUNCTION(BlueprintCallable)
    UGameLogicObject* GetGameLogicObject();
    
    UFUNCTION(BlueprintCallable)
    static float GetFloatVariable_OnActor(const AActor* InActor, FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    float GetFloatVariable(FName_GameLogicVarFloat FloatVarName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetExpression_OnActor(const AActor* InActor, FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    bool GetExpression(FName_GameLogicExpression ExpressionName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetBoolVariable_OnActor(const AActor* InActor, FName_GameLogicVarBool BoolVarName);
    
    UFUNCTION(BlueprintCallable)
    bool GetBoolVariable(FName_GameLogicVarBool BoolVarName);
    
};

