#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CelestialPointOfInterestName.h"
#include "SkyStateOverride.h"
#include "SkyStateOverrideCelestialPointOfInterestAlignTo.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class DAYNIGHT_API USkyStateOverrideCelestialPointOfInterestAlignTo : public USkyStateOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCelestialPointOfInterestName PointOfInterest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SlerpUp;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSlerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USkyStateOverrideCelestialPointOfInterestAlignTo();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetPointOfInterestName(FName NewPointOfInterest) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetPointOfInterest(FCelestialPointOfInterestName NewPointOfInterest) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPointOfInterestName(FName& CurrentPointOfInterest) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPointOfInterest(FCelestialPointOfInterestName& CurrentPointOfInterest) const;
    
};

