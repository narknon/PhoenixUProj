#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkyStateOverrideCelestialPointOfInterestAlignTo.h"
#include "SkyStateOverrideCelestialPointOfInterestAlignToRotator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API USkyStateOverrideCelestialPointOfInterestAlignToRotator : public USkyStateOverrideCelestialPointOfInterestAlignTo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator OrientTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Extra;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExtraRotation;
    
    USkyStateOverrideCelestialPointOfInterestAlignToRotator();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetOrientTo(FRotator NewOrientTo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetExtraRotation(FRotator NewExtra) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetOrientTo(FRotator& CurrentOrientTo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetExtraRotation(FRotator& CurrentExtra, bool& bHasExtra) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ClearExtraRotation() const;
    
};

