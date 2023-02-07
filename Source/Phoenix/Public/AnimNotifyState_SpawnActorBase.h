#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_SpawnActorBase.generated.h"

class AActor;
class UCurveFloat;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_SpawnActorBase : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AlphaCurve;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* SpawnedActor;
    
public:
    UAnimNotifyState_SpawnActorBase();
};

