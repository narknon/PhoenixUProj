#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineMoonOpposesSun.generated.h"

UCLASS(Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineMoonOpposesSun : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UEphemerisSubroutineMoonOpposesSun();
};

