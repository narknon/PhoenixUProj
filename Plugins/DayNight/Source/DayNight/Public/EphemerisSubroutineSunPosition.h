#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineSunPosition.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineSunPosition : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_Direction;
    
    UEphemerisSubroutineSunPosition();
};

