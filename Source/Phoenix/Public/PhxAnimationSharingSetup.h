#pragma once
#include "CoreMinimal.h"
#include "AnimationSharingSetup.h"
#include "EFacialAnimType.h"
#include "PhxAnimationSharingSetup.generated.h"

UCLASS(Blueprintable)
class UPhxAnimationSharingSetup : public UAnimationSharingSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFacialAnimType> FacialAnimationOverride;
    
    UPhxAnimationSharingSetup();
};

