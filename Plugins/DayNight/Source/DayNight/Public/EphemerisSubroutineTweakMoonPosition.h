#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutineTweakDirection.h"
#include "EphemerisSubroutineTweakMoonPosition.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineTweakMoonPosition : public UEphemerisSubroutineTweakDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyLightDirection;
    
    UEphemerisSubroutineTweakMoonPosition();
};

