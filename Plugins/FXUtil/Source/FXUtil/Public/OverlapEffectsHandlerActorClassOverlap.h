#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerMinimumSpeedBase.h"
#include "OverlapEffectsHandlerActorClassOverlap.generated.h"

class AActor;
class UOverlapEffectsHandlerEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerActorClassOverlap : public UOverlapEffectsHandlerMinimumSpeedBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> BeginEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> EndEffects;
    
    UOverlapEffectsHandlerActorClassOverlap();
};

