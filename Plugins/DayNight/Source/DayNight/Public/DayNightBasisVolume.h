#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "DayNightOverrideBasisInterface.h"
#include "DayNightBasisVolume.generated.h"

class UEphemerisBasis;

UCLASS(Blueprintable)
class DAYNIGHT_API ADayNightBasisVolume : public AVolume, public IDayNightOverrideBasisInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* BasisOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ADayNightBasisVolume();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

