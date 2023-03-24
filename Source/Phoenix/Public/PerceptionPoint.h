#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "PerceptionPoint.generated.h"

class APerceptionPoint;
class APerceptionPointArea;
class UAISenseConfig;

UCLASS(Blueprintable)
class APerceptionPoint : public APawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GroupTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGameEventEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetShareEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerPP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAISenseConfig*> SensesConfig;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APerceptionPointArea*> AttackDistanceScaleAreaList;
    
public:
    APerceptionPoint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void EnablePerception(bool bEnable, TArray<APerceptionPoint*> PerceptionPointList);
    
    UFUNCTION(BlueprintCallable)
    void Enable(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void AttackDistanceScaleVolume(float InScale, TArray<APerceptionPointArea*> InAreaList);
    
};

