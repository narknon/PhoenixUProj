#pragma once
#include "CoreMinimal.h"
#include "Able_Character.h"
#include "Patronus_Character.generated.h"

class UAnimationComponent;

UCLASS(Blueprintable)
class APatronus_Character : public AAble_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RootMotionTranslationScale;
    
    APatronus_Character(const FObjectInitializer& ObjectInitializer);
};

